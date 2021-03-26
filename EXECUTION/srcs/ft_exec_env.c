/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:48:17 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/21 13:20:23 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/execution.h"

static void printer(char *s1, char *s2, int fd)
{
            ft_putstr_fd(s1, fd);
            ft_putstr_fd("=", fd);
            ft_putstr_fd(s2, fd);
            ft_putstr_fd("\n", fd);
}

int        ft_exec_env(char **str, int is_pipe, int fd, t_cmap *envs)
{
    t_clist         *keys;
    t_clist         *iter_key;
    char            *value;

    keys = get_keys(envs);
    iter_key = keys;
    while (iter_key)
    {
        if (!ft_strncmp(iter_key->data, "?", 1) ||
        !ft_strncmp(iter_key->data, "$", 1))
        {
            iter_key = iter_key->next;
            continue;
        }
        value = get(envs, iter_key->data);
        if (value)
            printer(iter_key->data, value, fd);
        iter_key = iter_key->next;
    }
    clear_list(&keys, NULL);
    ft_disable_unused(&str, &is_pipe, &fd, &envs);
    return (0);
}