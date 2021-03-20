/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_function_error.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:49:27 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/20 22:50:04 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"

void    init_vars_errors(unsigned int *iterator, int *vars)
{
    *iterator = 0;
    vars[0] = 0;
    vars[1] = 0;
    vars[2] = 0;
    vars[3] = 0;
}

void check_back(int *back_vars, const char *line, unsigned int iterator)
{
    if (line[iterator] != '\\')
        *back_vars = 0;
    else
        (*back_vars)++;
}

void     ds_quotes_checker(int back, char c, int *other, int *ds)
{
        if (back % 2 == 0 && (c == '"' || c == '\''))
        {
            if (*ds == c)
                *ds = 0;
            else if(!*ds)
                *ds = c;
            *other = 1;
        }
}