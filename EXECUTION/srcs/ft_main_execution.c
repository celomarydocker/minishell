/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:19:55 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/18 12:28:16 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static t_clist     *put_data_into_struct(const char *command, const t_cmap *envs)
{
    t_clist     *exec_list;
    t_clist     *parser_pipe;

    parser_pipe = get_command_line((char *)command, (t_cmap *)envs);
    exec_list = from_parsing2exec(parser_pipe, get((t_cmap *)envs, "PATH"));
    clear_list(&parser_pipe, free_ccommand);
    return (exec_list);
}

static int     exec_command(const t_clist *commands, t_cmap *envs)
{
    t_clist       *iter_lst;
    int            pipe_ret;

    iter_lst = (t_clist *)commands;
    if (iter_lst)
    {
    if ((iter_lst->next || is_not_making_change(iter_lst->data)))
    {
        pipe_ret = ft_pipe(iter_lst, 1, 0, envs);
        setv(envs, "?", ft_itoa(pipe_ret));
    }
    else
    {
        pipe_ret = non_pipe_builtins(iter_lst->data, envs);
        setv(envs, "?", ft_itoa(pipe_ret));
        if (pipe_ret > 10000)
        {
            setv(envs, "?", ft_itoa(pipe_ret - 10000));
            return (1);
        }
        else
            setv(envs, "?", ft_itoa(pipe_ret));
    }
    }
    return (0);
}

void     all_commands(char *s, t_cmap *global_env)
{
    t_clist     *exec_pipe;
    char        **cmds;
    int         iter;
    int         exit_cmd;

    cmds = csplit(s, ';');
    iter = 0;
    while (cmds[iter])
    {
       exec_pipe = put_data_into_struct(cmds[iter], global_env);
       exit_cmd = exec_command(exec_pipe, global_env);
       clear_list(&exec_pipe, free_exec);
       if (exit_cmd)
            break ;
       iter++;
    }
    free_split(cmds);
}