/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:02:22 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/15 12:48:29 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int ft_export(char **args, int is_pipe, int fd, t_cmap *envs)
{
    char            **slt;
    int             ret;
    unsigned int    iterator;

    ret = 0;
    if (!*args)
    {
        ft_putstr_fd("TODO\n", 1);
        return (0);
    }
    iterator = 0;
    while (args[iterator])
    {
        slt = split_envirement_variable(args[iterator]);
        if (is_variable_not_valid(slt[0]))
        {
            ft_putstr_fd("CSHELL: export: `", 2);
            ft_putstr_fd(args[iterator], 2);
            ft_putstr_fd("' not a valid identifier\n", 2);
            ret = 1;
        }
        else
            setv(envs, slt[0], ft_cstrdup(slt[1]));
        free_split(slt);
        iterator++;
    }
    return (ret);
}