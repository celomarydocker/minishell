/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:33:04 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/19 18:44:28 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    prompt(void)
{
    char buffer[100];

    print("\033[0;32m$%s> \033[0;37m",getcwd(buffer, 100));
}

void    init_bash(char **line, t_cmap **envs)
{
    *line = NULL;
    *envs = put_vars(environ);
    setv(*envs, "?", ft_itoa(0));
    setv(*envs, "$", ft_itoa(getpid()));
    init_parent_signals();
    g_global.sigint_ret = 0;
    ft_init_builtins();
    g_global.g_pid = 0;
    g_global.pid = getpid();
    g_global.cerrno = 0;
    prompt();
}


void    clear_all(t_cmap **envs)
{
    clear_map(&g_global.g_builtins, free_builtins);
    clear_map(envs, free_vars);
}

void    reset_vars(char **line)
{
    free(*line);
    *line = NULL;
    g_global.g_pid = 0;
    prompt();
}

int     main()
{
    int     error;
    t_cmap *envs;

    init_bash(&g_global.g_line, &envs);
    error = 0;
    while (1)
	{
        if (readline(&g_global.g_line))
            end_of_line();
        if (g_global.sigint_ret)
        {
            setv(envs, "?", ft_itoa(g_global.sigint_ret));
        }
        g_global.sigint_ret = 0;
        if(g_global.g_line)
        {
          error = error_parsing(g_global.g_line);
            if (!error)
		        all_commands(g_global.g_line, envs);
            else
                setv(envs, "?", ft_itoa(error));
        }
        reset_vars(&g_global.g_line);
	}
    clear_all(&envs);
    return (0);
}
