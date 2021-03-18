/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_environ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:28:01 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/18 14:40:24 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

char        **from_map_to_array_2d(t_cmap *map, const char *cmd)
{
    char            **array_2d;
    t_clist         *lst;
    t_clist         *iterator;
    char            *value;
    unsigned int    i;

    lst = get_keys(map);
    array_2d = malloc((length(lst) + 1) * sizeof(char *));
    iterator = lst;
    i = 0;
    while(iterator)
    {
        if (!ft_strncmp(iterator->data, "SHLVL", 5) && !ft_strncmp(cmd, "./minishell", 11))
        {
            value = get(map, iterator->data);
            if (value)
                value = ft_itoa(ft_atoi(value) + 1);
        }
        else
            value = ft_cstrdup(get(map, iterator->data));
        array_2d[i] = ft_cstrjoin(ft_cstrjoin(ft_cstrdup(iterator->data),
        ft_cstrdup("=")), value);
        i++;
        iterator = iterator->next;
    }
    clear_list(&lst, NULL);
    array_2d[i] = NULL;
    return (array_2d);
}