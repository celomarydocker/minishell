/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:32:06 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/12 12:30:31 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int     ft_exec_exit(char **str, int fd, t_cmap *envs)
{
    int i = 0;
    if (ft_isalpha(*str[i++]) == 1)
    {
        write(1, "exit\n", 5);
        print("%s: %s: %s: %s\n", "minishell", "exit", *str, "numeric argument required");
        //return (1);
        exit(1);
    }
    else if (ft_isdigit(*str[i++] == 1))
    {
        print("exit");
        exit(1);
    }
    else
    {
        print("exit");
        exit(1);
    }
    return (0);
}