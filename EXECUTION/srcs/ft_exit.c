/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:32:06 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/19 18:15:35 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int ft_isnumber(char *str)
{
    int i = -1;
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[++i])
        if (!ft_isdigit(str[i]))
            return (0);
    return (1);
}

int     ft_exec_exit(char **str, int is_pipe,  int fd, t_cmap *envs)
{
    int excod;

	excod = 0;
	if (str[0])
	{
		if (ft_isnumber(str[0]))
		{
			if (ft_strlentwo(str) > 1)
            {
                if (!is_pipe)
			        ft_putstr_fd("exit\n", 2);
                ft_putstr_fd("CSHELL: exit: too many arguments\n", 2);
				if (is_pipe)
					return (1);
				return (10001);
            }
			if (!is_pipe)
				ft_putstr_fd("exit\n", 2);
			excod = ft_atoi(str[0]);
		}
		else
		{
			if (!is_pipe)
				ft_putstr_fd("exit\n", 2);
			excod = 255;
			ft_putstr_fd("CSHELL: exit: ", 2);
			ft_putstr_fd(str[0], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			if (is_pipe)
				return (excod);
			else
				exit(255);
		}
	}
    else if (!is_pipe)
	{
	    ft_putstr_fd("exit\n", 2);
		exit(excod);
	}
	ft_disable_unused(&str, &is_pipe, &fd, &envs);
	return (excod);
}