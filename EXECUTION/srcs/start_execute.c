/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:05:59 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/06 19:08:13 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int check_if_builtins(char *str)
{
    if (ft_strncmp(str, "echo", 5) == 0 || ft_strncmp(str, "cd", 3) == 0 ||
        ft_strncmp(str, "pwd", 4) == 0 || ft_strncmp(str, "export", 7) == 0 ||
        ft_strncmp(str, "env", 4) == 0 || ft_strncmp(str, "exit", 5) == 0 ||
        ft_strncmp(str, "unset", 6) == 0)
        return (1);
    else 
        return (0);
}

void start_execut()
{
    t_file *file;
    t_exec *exec;
 
    file = malloc(sizeof(t_file));
    exec = malloc(sizeof(t_exec));
    file->redirect = OUTPUT;
    file->filename = ft_strdup("file1");
    exec->cmd = ft_strdup("echo");
    exec->arguments = ft_split("-nn hicham fadyl", ' ');
    exec->files = malloc(sizeof(t_clist));
    exec->files->data = file;
    exec->files->next = NULL;
    file  = malloc(sizeof(t_file));
    file->filename = ft_strdup("file2");
    file->redirect = APPEND;
    exec->files->next = malloc(sizeof(t_clist));
    exec->files->next->data = file;
    exec->files->next->next = NULL;
    // t_clist *files = exec->files;
    
    // while (files)
    // {
    //     printf("%s %s\n", ((t_file *)files->data)->redirect, ((t_file *)files->data)->filename);
    //     files = files->next;
    // }
    if (check_if_builtins(exec->cmd) == 1)
    {
        if (ft_strncmp(exec->cmd, "echo", 5) == 0)
            ft_exec_echo(exec->arguments);
        else if (ft_strncmp(exec->cmd, "pwd", 4) == 0)
            ft_exec_pwd(exec->arguments);
        // else if (ft_strncmp(exec->cmd, "cd", 3) == 0)
        //     ft_exec_cd(exec->arguments);
        // else if (ft_strncmp(exec->cmd, "export", 7) == 0)
        //     ft_exec_export(exec->arguments);
        // else if (ft_strncmp(exec->cmd, "unset", 6) == 0)
        //     ft_exec_unset(exec->arguments);
        // else if (ft_strncmp(exec->cmd, "env", 4) == 0)
        //     ft_exec_env(exec->arguments);
        // else if (ft_strncmp(exec->cmd, "exit", 5) == 0)
        //     ft_exec_exit(exec->arguments);
    }
    else
    {
        printf("ach hna %s\n", exec->cmd);
    }
}

int main()
{
    start_execut();
    return 0;
}
