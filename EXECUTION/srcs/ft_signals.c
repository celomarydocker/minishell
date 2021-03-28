/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:41:25 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/28 17:33:58 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static void signal_int()
{
    char buffer[100];

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

static void signal_quit()
{
    if (g_global.g_pid)
        write(2, "Quit: 3\n", 8);
}

void signal_handler(int sig)
{
    if (sig == SIGINT)
        signal_int();
    if (sig == SIGQUIT)
        signal_quit();
}

void   init_parent_signals()
{
    signal(SIGINT, signal_handler);
    signal(SIGQUIT, signal_handler);
}

void        init_child_signal()
{
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
}