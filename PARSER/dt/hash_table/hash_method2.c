/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_method2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:17:26 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/11 22:56:00 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

t_clist		*get_keys(const t_cmap *map)
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

void		*copy_key(const unsigned char *key, size_t key_size)
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

void			*pop_value(t_cmap *map, const void *key, size_t key_size,
void (*free_key)(t_key_value *data))
{
	int		id;
	t_clist	*list;
	void	*value;
	id = get_hash_code(key, key_size);
	if (!map->lst[id])
		return (NULL);
	list = map->lst[id];
	while (list)
	{
		if (compare(((t_key_value *)list->data)->key, key, key_size))
		{
			value = ((t_key_value *)list->data)->value;
			free_key(list->data);
			return (value);
		}
		list = list->next;
	}
	return (NULL);
}