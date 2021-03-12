/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:32:06 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/12 18:54:47 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int     ft_exec_exit(char **str, int fd, t_cmap *envs)
{
    int i = 0;
    if (!*str)
    {
        print("exit\n");
        exit(0);
    }
    else if (ft_isalpha(**str) == 1)
    {
        write(1, "exit\n", 5);
        print("%s: %s: %s: %s\n", "minishell", "exit", *str, "numeric argument required");
        //return (1);
        exit(255);
    }
    else if (ft_isdigit(**str) == 1)
    {
        print("exit\n");
        exit(ft_atoi(str[i++]));
    }
    else
    {
        print("exit\n");
        exit(0);
    }
    return (0);
}