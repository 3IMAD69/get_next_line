/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:18:52 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/23 16:43:21 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list *ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void add_buffer_to_list(t_list **lst,char *buffer)
{
	t_list *newnode;
	t_list *lastnode;

	lastnode = ft_lstlast(*lst);
	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return ;
	if (!lastnode)
		*lst = newnode;
	else
		lastnode->next = newnode;
	newnode->str = buffer;
	newnode->next = NULL;
}

int	found_newline(t_list *lst)
{
	int	i;

	if (NULL == lst)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->str[i] && i < BUFFER_SIZE)
		{
			if (lst->str[i] == '\n')
				return (1);
			++i;
		}
		lst = lst->next;
	}
	return (0);
}

void read_to_list(t_list **lst, int fd)
{
	char *buffer;
	int byte_read;

	while(!found_newline(*lst))
	{
		buffer = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
		if (!buffer)
			return ;
		byte_read = read(fd,buffer,BUFFER_SIZE);
		if (!byte_read)
		{
			free (buffer);
			return ;
		}
		buffer[byte_read] = '\0';
		add_buffer_to_list(lst,buffer);
	}

}

char *get_line(t_list *lst)
{
	char *myline;
	int line_count;

	// check if lst is null 
	line_count = count_my_line(lst);
	myline = (char *)malloc((sizeof(char) * line_count )+ 1);
	if (!myline)
		return (NULL);
	copy_lstline(lst,myline);
	return (myline);
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	read_to_list(&lst,fd);
	if (!lst)
		return (NULL);
	line = get_line(lst);

	clearlst(&lst);
	return (line);
}



int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char *str1 = get_next_line(fd);
	char *str2 = get_next_line(fd);
	char *str3 = get_next_line(fd);
	printf("%s",str1);
	printf("%s",str2);
	printf("%s",str3);
	free(str1);
	free(str2);
	free(str3);
	close(fd);

	//system("leaks a.out");
}

