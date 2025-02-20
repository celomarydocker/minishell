/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_environ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:29:02 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/02 16:12:22 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static char	*concate_line(t_cmap *map,
t_clist *iterator, const char *cmd)
{
	char			*value;

	if (!ft_strncmp(iterator->data, "SHLVL", 5)
		&& !ft_strncmp(cmd, "./minishell", 11))
	{
		value = get(map, iterator->data);
		if (value)
			value = ft_itoa(ft_atoi(value) + 1);
	}
	else
		value = ft_cstrdup(get(map, iterator->data));
	return (ft_cstrjoin(ft_cstrjoin(ft_cstrdup(iterator->data),
				ft_cstrdup("=")), value));
}

char	**from_map_to_array_2d(t_cmap *map, const char *cmd)
{
	char			**array_2d;
	t_clist			*lst;
	t_clist			*iterator;
	unsigned int	i;

	lst = get_keys(map);
	array_2d = malloc((length(lst) + 1) * sizeof(char *));
	iterator = lst;
	i = 0;
	while (iterator)
	{
		if (ft_strncmp(iterator->data, "?", 1))
		{
			array_2d[i] = concate_line(map, iterator, cmd);
			i++;
		}
		iterator = iterator->next;
	}
	clear_list(&lst, NULL);
	array_2d[i] = NULL;
	return (array_2d);
}
