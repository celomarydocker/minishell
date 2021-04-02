/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_existance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:13:12 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/02 15:44:08 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static char	*join_command(const char *path, char **cmd)
{
	char	*joined;

	joined = ft_cstrjoin(ft_cstrdup((char *)path), ft_cstrdup("/"));
	joined = ft_cstrjoin(joined, *cmd);
	if (is_command(joined) == 1)
		return (joined);
	free(joined);
	return (NULL);
}

int	check_perm(const char *command, const char *path, char **line)
{
	char	*cmd;
	int		ret;

	cmd = ft_cstrdup((char *)command);
	cmd = join_command(path, &cmd);
	ret = is_command(cmd);
	if (ret == 1)
	{
		*line = cmd;
		return (1);
	}
	return (0);
}

t_permessions	sample_command(const char *command, char **line)
{
	int	ret;

	ret = is_command(command);
	if (ret == 1)
	{
		*line = ft_cstrdup((char *)command);
		return (FILE_EXEC);
	}
	else if (ret == 2)
	{
		*line = NULL;
		return (PERMISSION_DENIED);
	}
	return (NOT_FOUND);
}

t_permessions	check_existance(const char *command,
const char *path, char **line)
{
	char				**spath;
	unsigned int		iterator;

	*line = NULL;
	if (!command)
		return (WITHOUT);
	if (!*command)
		return (NOT_FOUND);
	if (check_if_builtins(command))
		return (BUILTINS);
	spath = csplit((char *)path, ':');
	iterator = 0;
	while (spath[iterator])
	{
		if (check_perm(command, spath[iterator], line))
		{
			free_split(spath);
			return (FILE_EXEC);
		}
		iterator++;
	}
	free_split(spath);
	return (sample_command(command, line));
}
