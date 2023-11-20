/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:18:52 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/20 19:53:59 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
    lst = NULL;
	read_and_stock(fd,lst);
	if (lst == NULL)
		return (NULL);
	return (line);
}

void read_and_stock(int fd, t_list **lst)
{
	char *buffer;
	int bytes_read;

	bytes_read = 1;
	while (!found_newline(*lst) && bytes_read != 0)
	{
		buffer = malloc(BUFFER_SIZE * sizeof(char));
		if (buffer == NULL)
			return ;
		bytes_read = read(fd,buffer,BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return ;
		}
		buffer[BUFFER_SIZE] = '\0';
		add_to_list(lst,buffer);
	}
}

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
}