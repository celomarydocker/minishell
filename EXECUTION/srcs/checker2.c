/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:14:29 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/02 15:57:29 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int	is_equal(const char *s1, const char *s2)
{
	unsigned int	iterator;

	iterator = 0;
	while (s1[iterator] && s1[iterator] == s2[iterator])
		iterator++;
	if (s1[iterator] != s2[iterator])
		return (0);
	return (1);
}

BOOL	is_not_making_change(t_exec *exec)
{
	if (exec->perm != BUILTINS)
		return (1);
	if (is_equal(exec->cmd, "export") && !*(exec->arguments + 1))
		return (1);
	return (!(is_equal(exec->cmd, "cd")
			|| is_equal(exec->cmd, "export")
			|| is_equal(exec->cmd, "unset")
			|| is_equal(exec->cmd, "exit")));
}

static int	check_cmd(const char *n)
{
	unsigned int		iterator;

	iterator = 0;
	while (n[iterator])
	{
		if (n[iterator] == '/')
			return (0);
		else if (n[iterator] != '.')
			break ;
		iterator++;
	}
	return (1);
}

int	is_command(const char *cmd)
{
	struct stat		s;

	if (stat(cmd, &s) == 0 && !check_cmd(cmd))
	{
		if (s.st_mode & S_IEXEC)
			return (1);
		else
			return (2);
	}
	return (0);
}
