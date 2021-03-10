/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:25:06 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/09 23:11:06 by mel-omar         ###   ########.fr       */
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

static void  ft_child_pipe(t_exec *data, int fd[2], int old_stdin, bool *is)
{
    t_pair_files        io;
    int                 status_error;

    if (data->perm == NOT_FOUND)
    {
        ft_putstr_fd(data->cmd, 2);
        ft_putstr_fd(": command not found\n", 2);
        exit(127);
    }
    io = iofile(data->files, &status_error);
    if (status_error == 255)
        exit(status_error);
    ft_setup_input(old_stdin, is[0], io);
    ft_setup_output(fd[1], is[1], io);
    close(fd[0]);
    if (data->perm == FILE_EXEC)
        execve(data->cmd, data->arguments, NULL);
    else if (data->perm == BUILTINS)
    {
        get_builtins(g_builtins, data->cmd)(data->arguments, 1);
        exit(0);
    }
    exit(127);
}

int    ft_pipe(t_clist  *pipe_exec, bool is_first, int old_stdin)
{
    int     pid;
    int     status;
    int     fd[2];
    int     is_first_last[2];


    fd[0] = -1;
    fd[1] = -1;
    if (!pipe_exec)
        return (EXIT_SUCCESS);
    is_first_last[0] = is_first;
    is_first_last[1] = ((!pipe_exec->next) ? 1 : 0);
    if (pipe_exec->next)
        pipe(fd);
    if ((pid=fork()) == 0)
        ft_child_pipe(pipe_exec->data, fd, old_stdin, is_first_last);
    if (pid < 0)
        exit(EXIT_FAILURE);
    close(fd[1]);
    if (!is_first)
        close(old_stdin);
    if (!pipe_exec->next)
    {
        waitpid(pid, &status, 0);
        return (ft_pipe_return(status))                   ;
    }
    status = ft_pipe(pipe_exec->next, 0, fd[0]);
    wait(NULL);
    return (status);
}

/*
int         ft_pipe(t_clist  *pipe_exec, bool is_first, int old_stdin)
{
    int     fd[2];
    if (!pipe_exec)
    {
        if (!is_first)
            close(old_stdin);
        return (0);
    }
    if (pipe_exec->next)
        pipe(fd);
    if (fork() == 0)
    {
        if (pipe_exec->next)
            dup2(fd[1], 1);
        if (pipe_exec->next)
        {
            close(fd[1]);
            close(fd[0]);
        }
        dup2(old_stdin, 0);
        if (old_stdin)
            close(old_stdin);
        t_exec *ex = (t_exec *)pipe_exec->data;
        execve(ex->cmd, ex->arguments, NULL);
    }
    if (pipe_exec->next)
        close(fd[1]);
    if (old_stdin)
        close(old_stdin);
    ft_pipe(pipe_exec->next, 0, fd[0]);
    wait(NULL);
    return (0);
}*/