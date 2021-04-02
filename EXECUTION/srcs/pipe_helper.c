/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:38:21 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/02 16:17:30 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int	ft_pipe_return(int status)
{
	if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}

void	file_not_found(const char *file, t_pair_files io)
{
	ft_putstr_fd("CSHELL: ", 2);
	ft_putstr_fd((char *)file, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	if (io.input != -1)
		close(io.input);
	if (io.output != -1)
		close(io.output);
	exit(1);
}

void	init_ft_pipe_vars(int vars[7], int is_first,
const t_clist *pipe_exec, int old)
{
	vars[2] = -1;
	vars[3] = -1;
	vars[4] = old;
	vars[5] = is_first;
	if (!pipe_exec->next)
		vars[6] = 1;
	else
		vars[6] = 0;
}

void	ft_child_helper(t_exec *data, t_cmap *envs)
{
	int		status_error;

	if (data->perm == FILE_EXEC)
	{
		execve(data->cmd, data->arguments,
			from_map_to_array_2d(envs, data->cmd));
		exit(0);
	}
	else if (data->perm == BUILTINS)
	{
		status_error = get_builtins(g_global.g_builtins,
				data->cmd)(data->arguments + 1, 1, 1, envs);
		exit(status_error);
	}
}
