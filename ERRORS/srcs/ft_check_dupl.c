/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dupl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:58:13 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/11 16:28:31 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"
#include <stdio.h>

/*
-- 1 one pipe
-- 2 pipe on the middle
*/
int     pipe_dup(const char *line)
{
    int                 lock;
    unsigned int        iterator;

    lock = 0;
    iterator = 1;
    if (!*line)
        return (0);
    if (line[0] == '|')
        return (1);
    if (is_inset(line[0], "\\\"'"))
        lock = line[0];

    while (line[iterator])
    {
        if (!lock && line[iterator] == '|' && line[iterator] == line[iterator - 1])
            return (2);
        if (lock == line[iterator])
            lock = 0;
        if (!lock && is_inset(line[iterator], "\\\"'"))
            lock = line[iterator];
        else if (lock == '\\' && line[iterator] != '\\')
            lock = 0;
        iterator++;
    }
    if (line[iterator - 1] == '|' && !lock && iterator - 2 >= 0 && line[iterator - 2] != '\\')
        return (1);
    return (0);
}
