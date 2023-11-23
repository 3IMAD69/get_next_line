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
#include <string.h>

void add_to_list(t_list **lst,char *buffer)
{
	t_list *newnode;
	t_list *last_node;

	last_node = ft_lstlast(*lst);
	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return ;
	if (!last_node)
		*lst = newnode;
	else
		last_node->next = newnode;
	newnode->str = buffer;
	newnode->next = NULL;
}
void printLinkedList(t_list *head) {
    t_list *current = head;

    while (current != NULL) {
        printf("%s ", current->str);
        current = current->next;
    }

    printf("\n");
}

void read_and_stock(int fd, t_list **lst)
{
	int		char_read;	
	char	*buffer;

	while (!found_newline(*lst))
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (!char_read)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		add_to_list(lst, buffer);
		//printf("bytes Readed %d\n",char_read);
	}
}


char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	read_and_stock(fd,&lst);
	if (lst == NULL)
		return (NULL);
	line = get_line(lst);
	freelst(&lst);
	 //printLinkedList(lst);
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

	//system("leaks a.out");
}

