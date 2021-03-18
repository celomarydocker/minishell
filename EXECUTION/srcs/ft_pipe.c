/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:25:06 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/18 14:40:43 by mel-omar@st      ###   ########.fr       */
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

void         command_not_found_error(const char *cmd)
{
        ft_putstr_fd("CSHELL: ", 2);
        ft_putstr_fd((char *)cmd, 2);
        ft_putstr_fd(": command not found\n", 2);
        exit(127);
}

void        file_not_found(const char *file, t_pair_files io)
{
        ft_putstr_fd("CSHELL: ", 2);
        ft_putstr_fd((char *)file, 2);
        ft_putstr_fd(": ", 2);
        ft_putstr_fd(strerror(errno), 2);
        ft_putstr_fd("\n", 2);
        if (io.input != -1)
            close(io.input);
        if (io.output != -1)
            close(io.output);
        exit(1);
}

void        init_child_signal()
{
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
}

void        is_ourshell(const char *cmd, int input)
{
    int     pid;

    if (!ft_strncmp(cmd, "./minishell", 11))
    {
        pid  = getpid();
        write(input, &pid, sizeof(int));
    }
    close(input);
}

void            ft_setup_io(int fd[4], int input, int is[2], t_pair_files io)
{
    ft_setup_input(input, is[0], io);
    ft_setup_output(fd[1], is[1], io);
    close(fd[0]);
}
void         command_perm_denied(const char *command)
{
    ft_putstr_fd("CSHELL: ", 2);
    ft_putstr_fd((char *)command, 2);
    ft_putstr_fd(": Permission denied\n", 2);
    exit(126);
}

static void  ft_child_pipe(t_exec *data, int fd[4], bool *is, t_cmap *envs)
{
    t_pair_files        io;
    int                 status_error;
    char                *filename_error;

    if (data->perm == WITHOUT)
    {
        status_error = just_create_files(data->files);
        exit(status_error);
    }
    init_child_signal();
    is_ourshell(data->cmd, fd[3]);
    if (data->perm == NOT_FOUND)
        command_not_found_error(data->arguments[0]);
    else if (data->perm == PERMISSION_DENIED)
        command_perm_denied(data->arguments[0]);
    io = iofile(data->files, &status_error, &filename_error);
    if (status_error)
        file_not_found(filename_error, io);
    ft_setup_io(fd, is[0], is + 1, io);
    if (data->perm == FILE_EXEC)
    {
        execve(data->cmd, data->arguments,
        from_map_to_array_2d(envs, data->cmd));
        exit(0);
    }
    else if (data->perm == BUILTINS)
    {
        status_error = get_builtins(g_global.g_builtins, data->cmd)(data->arguments + 1, 1 , 1, envs);
        exit(status_error);
    }
}

int    ft_pipe(t_clist  *pipe_exec, bool is_first, int old_stdin, t_cmap *envs)
{
    int     pid;
    int     status;
    int     sign;
    int     fd[4];
    int     is_first_last[3];

    fd[0] = -1;
    fd[1] = -1;
    if (!pipe_exec)
        return (EXIT_SUCCESS);
    is_first_last[0] = old_stdin;
    is_first_last[1] = is_first;
    is_first_last[2] = ((!pipe_exec->next) ? 1 : 0);
    pipe(fd + 2);
    if (pipe_exec->next)
        pipe(fd);
    if ((pid=fork()) == 0)
    {
        close(fd[2]);
        ft_child_pipe(pipe_exec->data, fd, is_first_last, envs);
    }
    if (pid < 0)
        exit(EXIT_FAILURE);
    close(fd[1]);
    if (!is_first)
        close(old_stdin);
    close(fd[3]);
    read(fd[2], &g_global.pid, sizeof(int));
    close(fd[2]);
    if (!pipe_exec->next)
    {
        g_global.g_pid= 1;
        waitpid(pid, &status, 0);
        g_global.pid = getpid();
        return (ft_pipe_return(status));
    }
    status = ft_pipe(pipe_exec->next, 0, fd[0], envs);
    g_global.g_pid= 1;
    waitpid(pid, &sign, 0);
    g_global.pid = getpid();
    return (status);
}
