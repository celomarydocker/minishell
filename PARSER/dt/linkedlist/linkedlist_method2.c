/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_method2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:00:21 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/12 11:30:32 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void	*free_node(t_clist **list)
{
	void	*data;

	data = (*list)->data;
	free(*list);
	return (data);
}

t_clist 	*joined_list(t_clist *lst1, t_clist *lst2)
{
	t_clist		*joined;
	t_clist		*iter1;
	t_clist		*iter2;

	iter1 = lst1;
	iter2 = lst2;
	joined = NULL;
	while (iter1)
	{
		append(&joined, iter1->data);
		iter1 = iter1->next;
	}
	while (iter2)
	{
		append(&joined, iter2->data);
		iter2 = iter2->next;
	}
	return (joined);
}