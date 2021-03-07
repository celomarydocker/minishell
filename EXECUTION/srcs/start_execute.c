/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:53:16 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/07 14:58:04 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/execution.h"

/*
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
*/

