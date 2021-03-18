/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:48:17 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/18 16:33:30 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/execution.h"

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
        {
            ft_putstr_fd(iter_key->data, fd);
            ft_putstr_fd("=", fd);
            ft_putstr_fd(value, fd);
            ft_putstr_fd("\n", fd);
        }
        iter_key = iter_key->next;
    }
    clear_list(&keys, NULL);
    ft_disable_unused(&str, &is_pipe, &fd, &envs);
    return (0);
}