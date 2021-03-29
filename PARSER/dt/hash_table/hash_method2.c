/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_method2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:17:26 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/29 18:57:39 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

t_clist	*get_keys(const t_cmap *map)
{
	t_clist			*list;
	t_clist			*lst;
	int				iter;
	unsigned char	*key;

	iter = 0;
	list = NULL;
	while (iter < SIZE)
	{
		lst = map->lst[iter];
		while (lst)
		{
			key = ((t_key_value *)lst->data)->key;
			append(&list, key);
			lst = lst->next;
		}
		iter++;
	}
	return (list);
}

void	*copy_key(const unsigned char *key, size_t key_size)
{
	size_t			iter;
	unsigned char	*dst;

	iter = 0;
	dst = malloc(key_size + 1);
	while (iter < key_size)
	{
		dst[iter] = key[iter];
		iter++;
	}
	dst[iter] = 0;
	return (dst);
}

void	*getting_value(t_clist *before, t_clist *list,
t_clist **first, void (*free_key)(t_key_value *data))
{
	void		*value;

	value = ((t_key_value *)list->data)->value;
	free_key(list->data);
	if (!before)
		*first = list->next;
	else
		before->next = list->next;
	free(list);
	return (value);
}

void	*pop_value(t_cmap *map, const void *key, size_t key_size,
		void (*free_key)(t_key_value *data))
{
	int			id;
	t_clist		*list;
	t_clist		*before;

	id = get_hash_code(key, key_size);
	if (!map->lst[id])
		return (NULL);
	before = NULL;
	list = map->lst[id];
	while (list)
	{
		if (compare(((t_key_value *)list->data)->key, key, key_size))
			return (getting_value(before, list, &map->lst[id], free_key));
		before = list;
		list = list->next;
	}
	return (NULL);
}
