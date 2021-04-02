/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:33:04 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/04/02 18:54:07 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(void)
{
	char	buffer[100];

	print("\033[0;32m$%s> \033[0;37m", getcwd(buffer, 100));
	g_global.count_prompt = ft_cstrlen(buffer);
}

void	init_bash(t_cmap **envs, char **environ, int argc, char *argv[])
{
	*envs = put_vars(environ);
	setv(*envs, "?", ft_itoa(0));
	init_parent_signals();
	g_global.sigint_ret = 0;
	ft_init_builtins();
	g_global.g_pid = 0;
	argv = NULL;
	argc = 0;
	prompt();
}

void	clear_all(t_cmap **envs)
{
	clear_map(&g_global.g_builtins, free_builtins);
	clear_map(envs, free_vars);
	clear_history();
}

void	reset_vars(char **line)
{
	free(*line);
	*line = NULL;
	g_global.g_pid = 0;
	prompt();
}

int	main(int argc, char *argv[], char **environ)
{
	int		error;
	t_cmap	*envs;
	char	*line;

	init_bash(&envs, environ, argc, argv);
	error = 0;
	while (1)
	{
		line = readline(envs);
		if (g_global.sigint_ret)
			setv(envs, "?", ft_itoa(g_global.sigint_ret));
		g_global.sigint_ret = 0;
		if (line)
		{
			error = error_parsing(line);
			if (!error)
				all_commands(line, envs);
			else
				setv(envs, "?", ft_itoa(error));
		}
		reset_vars(&line);
	}
	clear_all(&envs);
	return (0);
}
