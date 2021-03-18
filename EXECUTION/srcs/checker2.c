/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:22:14 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/18 12:22:58 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int      is_equal(const char *s1, const char *s2)
{
    unsigned int iterator;

    iterator = 0;
    while (s1[iterator] && s1[iterator] == s2[iterator])
        iterator++;
    if (s1[iterator] != s2[iterator])
        return (0);
    return (1);
}

bool     is_not_making_change(t_exec *exec)
{
    if (exec->perm != BUILTINS)
        return (1);
    return (!(is_equal(exec->cmd, "cd") ||
    is_equal(exec->cmd, "export") ||
    is_equal(exec->cmd, "unset") || is_equal(exec->cmd, "exit")));
}