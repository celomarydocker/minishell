/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:02:22 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/19 19:58:14 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int     ft_cstrcmp(const char *s1, const char *s2)
{
    unsigned int        iterator;

    iterator = 0;
    while (s1[iterator] && s2[iterator] && s1[iterator] == s2[iterator])
        iterator++;
    return ((int)(s1[iterator] - s2[iterator]));
}

void    ft_swap(char **d1, char **d2)
{
    char *tmp;

    tmp = *d1;
    *d1 = *d2;
    *d2 = tmp;
}

void    print_value(const char *value)
{
    int iter;

    iter = 0;
    while (value[iter])
    {
        if (is_inset(value[iter], "\"\\$"))
            ft_putchar_fd('\\', 1);
        ft_putchar_fd(value[iter], 1);
        iter++;
    }
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

void    print_variables(t_cmap *envs, int fd)
{
    t_clist     *keys;
    t_clist     *iter_key;
    char        *value;

    keys = sorted_keys(get_keys(envs));
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
        ft_putstr_fd("declare -x ", fd);
        ft_putstr_fd(iter_key->data, fd);
        if (value)
        {
            ft_putstr_fd("=\"", fd);
            print_value(value);
            ft_putstr_fd("\"\n", fd);

      }
      else
        ft_putstr_fd("\n", fd);
      iter_key = iter_key->next;
    }
    clear_list(&keys, NULL);

}

int ft_export(char **args, int is_pipe, int fd, t_cmap *envs)
{
    char            **slt;
    int             ret;
    int             v_ret;
    unsigned int    iterator;
    ret = 0;
    if (!*args)
    {
        print_variables(envs, fd);
        return (0);
    }
    iterator = 0;
    while (args[iterator])
    {
        slt = split_envirement_variable(args[iterator]);
        if ((v_ret=is_variable_not_valid(slt[0])))
        {
            if (v_ret == 1)
            {
                ft_putstr_fd("CSHELL: export: `", 2);
                ft_putstr_fd(args[iterator], 2);
                ft_putstr_fd("' not a valid identifier\n", 2);
                ret = 1;
            }
        }
        else
            setv(envs, slt[0], ft_cstrdup(slt[1]));
        free_split(slt);
        iterator++;
    }
    ft_disable_unused(&args, &is_pipe, &fd, &envs);
    return (ret);
}