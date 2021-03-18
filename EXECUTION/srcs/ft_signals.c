/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:41:25 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/18 12:50:55 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static void signal_int()
{
    char buffer[100];

    if (g_global.pid == getpid())
    {
        if (!g_global.g_pid)
        {
            g_global.sigint_ret = 1;
            write(1, "\b\b  \r\n", 6);
            print("\033[0;32m$%s> \033[0;37m", getcwd(buffer, 100));
        }
        else
            print("\n");
    } 
}

static void signal_quit()
{
    if (g_global.pid == getpid())
    {
        if (!g_global.g_pid)
            write(2, "\b\b  \b\b", 6);
        else
            write(2, "Quit: 3\n", 8);
    }
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