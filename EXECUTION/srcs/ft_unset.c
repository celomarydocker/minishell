/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:02:25 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/15 14:58:26 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"


int     ft_unset(char **arguments, int is_pipe, int fd, t_cmap *envs)
{
    char                **inside;
    char                *value;
    unsigned int        iterator;
    unsigned int        nested_iterator;
    int                 ret;

    iterator = 0;
    ret = 0;
    while (arguments[iterator])
    {
        inside = csplit(arguments[iterator], ' ');
        nested_iterator = 0;
        while (inside[nested_iterator])
        {
            if (is_variable_not_valid(inside[nested_iterator]))
            {
                ft_putstr_fd("CSHELL: unset: `", 2);
                ft_putstr_fd(inside[nested_iterator], 2);
                ft_putstr_fd("' not a valid identifier\n", 2);
                ret = 1;
        }
        else
        {
            value = pop_value(envs, inside[nested_iterator],
            ft_strlen(inside[nested_iterator]), free_envs);
            free(value);
        }
        nested_iterator++;
        }
        free_split(inside);
        iterator++;
    }
    return (ret);
}
