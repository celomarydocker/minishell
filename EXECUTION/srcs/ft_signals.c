/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:35:26 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/01 18:35:50 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static void	signal_int(void)
{
	char	buffer[100];

	if (!g_global.g_pid)
	{
		clear_line(g_global.g_line);
		g_global.g_line = init_line();
		cleartemp();
		copyhistory();
		g_global.sigint_ret = 1;
		write(1, "\n", 1);
		print("\033[0;32m$%s> \033[0;37m", getcwd(buffer, 100));
		g_global.count_prompt = ft_cstrlen(buffer);
	}
	else
		print("\n");
}

static void	signal_quit(void)
{
	if (g_global.g_pid)
		write(2, "Quit: 3\n", 8);
}

void		signal_handler(int sig)
{
	if (sig == SIGINT)
		signal_int();
	if (sig == SIGQUIT)
		signal_quit();
}

void		init_parent_signals(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}

void		init_child_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
