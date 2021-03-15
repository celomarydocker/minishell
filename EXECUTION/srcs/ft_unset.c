/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:02:25 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/15 12:48:21 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"


int     ft_unset(char **arguments, int is_pipe, int fd, t_cmap *envs)
{
    char                *value;
    unsigned int        iterator;
    int                 ret;

    iterator = 0;
    ret = 0;
    while (arguments[iterator])
    {
        if (is_variable_not_valid(arguments[iterator]))
        {
            ft_putstr_fd("CSHELL: unset: `", 2);
            ft_putstr_fd(arguments[iterator], 2);
            ft_putstr_fd("' not a valid identifier\n", 2);
            ret = 1;
        }
        else
        {
            value = pop_value(envs, arguments[1], ft_strlen(arguments[0]), free_envs);
            free(value);
        }
        iterator++;
    }
    return (ret);
}
