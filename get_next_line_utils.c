/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:50:12 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/23 17:05:29 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(t_list *lst)
{
	int	i;

	if (lst == NULL)
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
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}


int count_my_line(t_list *lst)
{
	int count;
	int i;

	count = 0;
	while (lst)
	{
		i = 0;
		while(lst->str[i])
		{
			if (lst->str[i] != '\n')
			{
				count++;
				return (count);
			}
			count++;
			i++;
		}
		lst = lst->next;
	}
	return (count);
}

void copy_line_to_str(char *next_str,t_list *lst)
{
	int i;
	int k;
	
	k = 0;
	while (lst)
	{
		i = 0;
		while (lst->str[i])
		{
			if (lst->str[i] == '\n')
			{
				next_str[k++] = '\n';
				next_str[k] = '\0';
				return ;
			}
			next_str[k++] = lst->str[i++]; 
		}
		lst = lst->next;
	}
	next_str[k] = '\0';
}

char *get_line(t_list *lst)
{
	size_t line_len;
	char *next_str;

	line_len = count_my_line(lst);
	next_str = (char *)malloc(sizeof(char) * (line_len + 1));
	if (next_str == NULL)
		return (NULL);
	copy_line_to_str(next_str,lst);
	return (next_str);
}

void clearlst(t_list **lst,t_list *newlist, char *tmp_buffer)
{
	t_list *tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->str);
		free((*lst));
		*lst = tmp;
	}
	*lst = NULL;
	if (newlist->str[0] == '\0')
	{
		free(newlist->str);
		free(newlist);
	}
	else
		*lst = newlist;
}


void freelst(t_list **lst)
{
	t_list *newlist;
	t_list *last_node;
	char *tmp_str;
	int i;
	int j;

	i = 0;
	j = 0;
	tmp_str = (char *)malloc(BUFFER_SIZE + 1);
	newlist = (t_list *)malloc(sizeof(t_list));
	if (!newlist || !tmp_str)
		return ;
	last_node = ft_lstlast(*lst);
	while (last_node->str[i] && last_node->str[i] != '\n')
		i++;
	while (last_node->str[i] && last_node->str[++i])
		tmp_str[j++] = last_node->str[i];
	tmp_str[j] = '\0';
	newlist->str = tmp_str;
	newlist->next = NULL;
	//free the original lst hna 
	clearlst(lst,newlist,tmp_str);
}


