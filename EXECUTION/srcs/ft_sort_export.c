/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:36:21 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/02 16:15:45 by hfadyl           ###   ########.fr       */
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
	tmp = d1;
	d1 = d2;
	d2 = tmp;
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
