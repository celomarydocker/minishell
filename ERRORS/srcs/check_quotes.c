/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:15:48 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/18 14:24:58 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"

int         check_quotes(const char *line)
{
    int             lock;
    unsigned int    iterator;
    int             backslash;

    lock = 0;
    iterator = 0;
    backslash = 0;
    while (line[iterator])
    {
        if (backslash % 2 == 0 && (line[iterator] == '\'' || line[iterator] == '"'))
        {
            if (!lock)
                lock = line[iterator];
            else if (lock == line[iterator])
                lock = 0;
        }
        if (line[iterator] == '\\')
            backslash++;
        else
            backslash = 0;
        iterator++;
    }
    if (lock)
        return (1);
    return (0);
}