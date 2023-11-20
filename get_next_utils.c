/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:50:12 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/20 20:06:28 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int found_newline(t_list *lst)
{
    int i;
    t_list *current;

    if (lst == NULL)
        return (0);
    current = ft_lstlast(lst);
	i = 0;
	while (current->str[i])
	{
		if (current->str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

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
	return (newnode);
}
