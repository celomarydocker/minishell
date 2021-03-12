/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_environ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:28:01 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/12 21:52:39 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

char        **from_map_to_array_2d(t_cmap *map)
{
    char            **array_2d;
    t_clist         *lst;
    t_clist         *iterator;
    unsigned int    i;

    lst = get_keys(map);
    array_2d = malloc((length(lst) + 1) * sizeof(char *));
    iterator = lst;
    i = 0;
    while(iterator)
    {
        array_2d[i] = ft_cstrjoin(ft_cstrjoin(ft_cstrdup(iterator->data),
        ft_cstrdup("=")), ft_cstrdup(get(map, iterator->data)));
        i++;
        iterator = iterator->next;
    }
    clear_list(&lst, NULL);
    array_2d[i] = NULL;
    return (array_2d);
}