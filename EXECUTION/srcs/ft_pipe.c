/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:25:06 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/01 13:12:33 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static void	ft_setup_output(int output, bool is_last, t_pair_files io)
{
	if (io.output != -1)
	{
		dup2(io.output, 1);
		close(io.output);
	}
	else
	{
		if (!is_last)
		{
			dup2(output, 1);
			close(output);
		}
	}
}

static void	ft_setup_input(int old_input, bool is_first, t_pair_files io)
{
	if (io.input != -1)
	{
		dup2(io.input, 0);
		close(io.input);
	}
	else
	{
		dup2(old_input, 0);
		if (!is_first)
			close(old_input);
	}
}

void	ft_setup_io(int fd[2], int input, int is[2], t_pair_files io)
{
	ft_setup_input(input, is[0], io);
	ft_setup_output(fd[1], is[1], io);
	close(fd[0]);
}

static void	ft_child_pipe(t_exec *data, int fd[2], bool *is, t_cmap *envs)
{
	 t_pair_files			io;
	 int					status_error;
	 char					*filename_error;

	if (data->perm == WITHOUT)
	{
		status_error = just_create_files(data->files);
		exit(status_error);
	}
	init_child_signal();
	if (data->perm == NOT_FOUND)
		command_not_found_error(data->arguments[0]);
	else if (data->perm == PERMISSION_DENIED)
		command_perm_denied(data->arguments[0]);
	io = iofile(data->files, &status_error, &filename_error);
	if (status_error)
		file_not_found(filename_error, io);
	ft_setup_io(fd, is[0], is + 1, io);
	ft_child_helper(data, envs);
}

int	ft_pipe(t_clist *pipe_exec, bool is_first, int old_stdin, t_cmap *envs)
{
	int		vars[7];

	if (!pipe_exec)
		return (EXIT_SUCCESS);
	init_ft_pipe_vars(vars, is_first, pipe_exec, old_stdin);
	if (pipe_exec->next)
		pipe(vars + 2);
	vars[0] = fork();
	if (vars[0] == 0)
		ft_child_pipe(pipe_exec->data, vars + 2, vars + 4, envs);
	if (vars[0] < 0)
		exit(EXIT_FAILURE);
	close(vars[3]);
	if (!is_first)
		close(old_stdin);
	if (!pipe_exec->next)
	{
		g_global.g_pid = 1;
		waitpid(vars[0], &vars[1], 0);
		return (ft_pipe_return(vars[1]));
	}
	vars[1] = ft_pipe(pipe_exec->next, 0, vars[2], envs);
	g_global.g_pid = 1;
	waitpid(vars[0], NULL, 0);
	return (vars[1]);
}
