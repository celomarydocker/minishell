/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:32:06 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/02 16:10:24 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static int	ft_isnumber(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

static int	ft_hack0_exit(char **str, int is_pipe)
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
	{
		ft_putstr_fd("exit\n", 2);
		exit(ft_atoi(str[0]));
	}
	return (ft_atoi(str[0]));
}

static int	ft_hack1_exit(char **str, int is_pipe)
{
	if (!is_pipe)
		ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("CSHELL: exit: ", 2);
	ft_putstr_fd(str[0], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	if (is_pipe)
		return (255);
	else
		exit(255);
}

int	ft_exec_exit(char **str, int is_pipe, int fd, t_cmap *envs)
{
	int	excod;

	excod = 0;
	if (str[0])
	{
		if (ft_isnumber(str[0]))
			excod = ft_hack0_exit(str, is_pipe);
		else
			excod = ft_hack1_exit(str, is_pipe);
	}
	else if (!is_pipe)
	{
		ft_putstr_fd("exit\n", 2);
		exit(excod);
	}
	ft_disable_unused(&str, &is_pipe, &fd, &envs);
	return (excod);
}
