/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:34:55 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/21 13:38:24 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static void    ft_swap(char **d1, char **d2)
{
    char *tmp;

    tmp = *d1;
    *d1 = *d2;
    *d2 = tmp;
}

t_clist *sorted_keys(t_clist *keys)
{
    t_clist     *next;
    t_clist     *current;
    char        *d1;
    char        *d2;

    if (!keys)
        return (NULL);
    current = keys;
    while (current->next)
    {
        next = current->next;
        while (next)
        {
            if (ft_cstrcmp(current->data, next->data) > 0)
            {
                d1 = (char *)current->data;
                d2 = (char *)next->data;
                ft_swap(&d1, &d2);
                current->data = d1;
                next->data = d2;
            }
            next = next->next;
        }
        current = current->next;
    }
    return (keys);
}