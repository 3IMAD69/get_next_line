/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:42:31 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/24 16:42:58 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
char *get_linee(t_list *lst);
void read_to_list(t_list **lst, int fd);
void add_buffer_to_list(t_list **lst,char *buffer);
t_list *ft_lstlast(t_list *lst);
int count_my_line(t_list *lst);
void copy_lstline(t_list *lst,char *line);
void clearlst(t_list **lst);
void	free_all(t_list *clean_node, char *buf,t_list **list);



#endif