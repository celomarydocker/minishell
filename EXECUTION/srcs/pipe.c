/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:25:06 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/07 12:44:42 by mel-omar@st      ###   ########.fr       */
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

static void  ft_child_pipe(t_exec *data, int fd[2], int old_stdin, bool is[2])
{
    t_pair_files        io;
    int                 status_error;

    if (data->perm == NOT_FOUND)
        exit(127);
    io = iofile(data->files, &status_error);
    if (status_error == 255)
        exit(status_error);
    ft_setup_input(old_stdin, is[0], io);
    ft_setup_output(fd[1], is[1], io);
    close(fd[0]);
    if (data->perm == FILE_EXEC)
        execve(data->cmd, data->arguments, NULL);
    else
    {
        print("BUILTINS\n", )
    }
    exit(127);
}

static void     ft_status_error(int input, int *status)
{
    close(input);
    wait(status);   
}

int    ft_pipe(t_clist  *pipe_exec, bool is_first, int old_stdin)
{
    int     pid;
    int     status;
    int     fd[2];
    int     is_first_last[2];

    if (!pipe_exec)
        return ;
    is_first_last[0] = is_first;
    is_first_last[1] = (pipe_exec->next) ? 1 : 0;
    if (pipe_exec->next)
        pipe(fd);
    if ((pid=fork()) == 0)
        ft_child_pipe(pipe_exec->data, fd, old_stdin, is_first_last);
    if (pid < 0)
        exit(EXIT_FAILURE);
    close(fd[1]);
    if (!is_first)
        close(old_stdin);
    if ((status = ft_pipe(pipe_exec->next, 0, fd[0])) != EXIT_SUCCESS)
    {
        ft_status_error(fd[0], NULL);
        return (status);
    }
    ft_status_error(fd[0], &status);
    return (ft_pipe_return(status));
}
