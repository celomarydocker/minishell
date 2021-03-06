/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:25:06 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/06 15:59:44 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void    ft_pipe(t_clist  *pipe_exec, bool is_first, int old_stdin)
{
    int     pid;
    int     status;
    int     fd[2];
    t_exec  *exec;

    if (!pipe_exec)
        return ;
    if (pipe_exec->next)
        pipe(fd);
    if ((pid=fork()) == 0)
    {
        exec = (t_exec *)pipe_exec->data;
        dup2(old_stdin, 0);
        if (pipe_exec->next)
            dup2(fd[1], 1);
        close(fd[1]);
        if (!is_first)
            close(old_stdin);
        close(fd[0]);
        execve(exec->cmd, exec->arguments, NULL);
        exit(127);
    }
    close(fd[1]);
    if (!is_first)
        close(old_stdin);
    ft_pipe(pipe_exec->next, 0, fd[0]);
    close(fd[0]);
    wait(NULL);
}
