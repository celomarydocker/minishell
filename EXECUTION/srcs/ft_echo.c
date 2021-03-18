/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:14:34 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/18 16:33:20 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static short	ft_chkopt(char **args, int *i)
{
	short	nl;
	int		j;
	*i = -1;
	nl = 1;
	while (args[++(*i)])
	{
		j = 0;
		if (args[*i][0] == '-')
		{
			while (args[*i][++j])
				if (args[*i][j] != 'n')
					break ;
			if (*i == 0)
				nl = !(!args[*i][j] && args[*i][j - 1] == 'n');
			if (args[*i][j] && args[*i][j] != 'n')
				break ;
		}
		else
			break ;
	}
	return (nl);
}

int ft_exec_echo(char **str, int  is_pipe, int fd, t_cmap *envs)
{
    short newline;
    int i;
    
    if (!str[0])
        return (!(write(fd, "\n", 1)));
    newline = ft_chkopt(str, &i);
    while (str[i])
	{
		ft_putstr_fd(str[i++], fd);
		if (str[i])
			write(fd, " ", 1);
	}
	if (newline)
		write(fd, "\n", 1);
	ft_disable_unused(&str, &is_pipe, &fd, &envs);
	return (0);
}