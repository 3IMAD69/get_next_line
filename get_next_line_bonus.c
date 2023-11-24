/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:42:05 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/24 19:28:03 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char *get_linee(t_list *lst)
{
	char *myline;
	int line_count;

	line_count = count_my_line(lst);
	myline = (char *)malloc((sizeof(char) * line_count )+ 1);
	if (!myline)
		return (NULL);
	copy_lstline(lst,myline);
	return (myline);
}

char	*get_next_line(int fd)
{
	static t_list	*lst[256];
	char			*line;
	t_list *tmp;

	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, &line, 0) < 0)
	{
		while (lst[fd])
		{
			tmp = lst[fd]->next;
			free(lst[fd]->str);
			free(lst[fd]);
			lst[fd] = tmp;
		}
		lst[fd] = NULL;
		return NULL;
	}	
	read_to_list(&lst[fd],fd);
	if (!lst[fd])
		return (NULL);
	line = get_linee(lst[fd]);

	clearlst(&lst[fd]);
	return (line);
}



// int	main(void)
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	int fd2 = open("text2.txt", O_RDONLY);
// 	printf("%s",get_next_line(fd)); // 1 file 1
// 	printf("%s",get_next_line(fd2)); // 1 file 2
// 	printf("%s",get_next_line(fd)); // 2 file 1
// 	printf("%s",get_next_line(fd2)); // 2 file 2
// 	printf("%s",get_next_line(fd));  // 3 file 1
// 	printf("%s",get_next_line(fd2)); // 3 file 2
    
// 	close(fd);
// 	close(fd2);

// 	//system("leaks a.out");
// }
