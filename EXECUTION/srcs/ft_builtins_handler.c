/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:21:38 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/01 18:21:52 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int	just_create_files(t_clist *files)
{
	t_pair_files	io;
	int				error;
	char			*file_error;

	io = iofile(files, &error, &file_error);
	if (error)
	{
		ft_putstr_fd("CSHELL: ", 2);
		ft_putstr_fd(file_error, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (1);
	}
	if (io.input != -1)
		close(io.input);
	if (io.output != -1)
		close(io.output);
	return (0);
}

int	non_pipe_builtins(const t_exec *ex, t_cmap *envs)
{
	int		c_ret;

	if (ex->error)
		return (1);
	c_ret = just_create_files(ex->files);
	if (c_ret)
		return (c_ret);
	return (get_builtins(g_global.g_builtins,
			ex->cmd)(ex->arguments + 1, 0, 1, envs));
}
