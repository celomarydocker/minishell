/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:32:06 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/18 15:10:20 by mel-omar@st      ###   ########.fr       */
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
	return (excod);
}