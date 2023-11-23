/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:45:09 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/23 13:09:54 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5 
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

int found_newline(t_list *lst);
char *get_line(t_list *lst);
void copy_line_to_str(char *next_str,t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void add_to_list(t_list **lst,char *buffer);
void freelst(t_list **lst);
void clearlst(t_list **lst,t_list *newlist, char *tmp_buffer);

#endif