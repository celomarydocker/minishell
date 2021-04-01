/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:34:55 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/01 14:22:06 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static void	ft_swap(void *pda, void *pdb)
{
	char	*tmp;
	char	*d1;
	char	*d2;

	d1 = (char *)pda;
	d2 = (char *)pdb;
	tmp = *d1;
	*d1 = *d2;
	*d2 = tmp;
}

t_clist	*sorted_keys(t_clist *keys)
{
	t_clist		*next;
	t_clist		*current;

	if (!keys)
		return (NULL);
	current = keys;
	while (current->next)
	{
		next = current->next;
		while (next)
		{
			if (ft_cstrcmp(current->data, next->data) > 0)
				ft_swap(current->data, next->data);
			next = next->next;
		}
		current = current->next;
	}
	return (keys);
}
