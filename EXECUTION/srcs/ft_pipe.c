/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:25:06 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/13 16:55:09 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static void  ft_setup_output(int output, bool is_last, t_pair_files io)
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

static void  ft_setup_input(int old_input, bool is_first, t_pair_files io)
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

static void  ft_child_pipe(t_exec *data, int fd[2], bool *is, t_cmap *envs)
{
    t_pair_files        io;
    int                 status_error;

    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
    if (data->perm == NOT_FOUND)
    {
        ft_putstr_fd("CSHELL: ", 2);
        ft_putstr_fd(data->cmd, 2);
        ft_putstr_fd(" command not found\n", 2);
        exit(127);
    }
    io = iofile(data->files, &status_error);
    if (status_error == 255)
        exit(status_error);
    ft_setup_input(is[0], is[1], io);
    ft_setup_output(fd[1], is[2], io);
    close(fd[0]);
    if (data->perm == FILE_EXEC)
        execve(data->cmd, data->arguments, from_map_to_array_2d(envs));
    else if (data->perm == BUILTINS)
    {
        get_builtins(g_global.g_builtins, data->cmd)(data->arguments + 1, 1 , 1, envs);
        exit(0);
    }
    exit(127);
}

int    ft_pipe(t_clist  *pipe_exec, bool is_first, int old_stdin, t_cmap *envs)
{
    int     pid;
    int     status;
    int     fd[2];
    int     is_first_last[3];


    fd[0] = -1;
    fd[1] = -1;
    if (!pipe_exec)
        return (EXIT_SUCCESS);
    is_first_last[0] = old_stdin;
    is_first_last[1] = is_first;
    is_first_last[2] = ((!pipe_exec->next) ? 1 : 0);
    if (pipe_exec->next)
        pipe(fd);
    if ((pid=fork()) == 0)
        ft_child_pipe(pipe_exec->data, fd, is_first_last, envs);
    if (pid < 0)
        exit(EXIT_FAILURE);
    close(fd[1]);
    if (!is_first)
        close(old_stdin);
    if (!pipe_exec->next)
    {
        waitpid(pid, &status, 0);
        return (ft_pipe_return(status));
    }
    status = ft_pipe(pipe_exec->next, 0, fd[0], envs);
    waitpid(pid, NULL, 0);
    return (status);
}
