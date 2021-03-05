/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:57:35 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/05 11:52:30 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

// int check_if_builtins(char *str)
// {
//     if (ft_strncmp(str, "echo", 5) || ft_strncmp(str, "cd", 3) ||
//         ft_strncmp(str, "pwd", 4) || ft_strncmp(str, "export", 7) ||
//         ft_strncmp(str, "env", 4) || ft_strncmp(str, "exit", 5) ||
//         ft_strncmp(str, "unset", 6))
//         return (1);
//     else 
//         return (0);
// }

void start_execut()
{
    t_file *file;
    t_exec *exec;

    file = malloc(sizeof(t_file));
    exec = malloc(sizeof(t_exec));
    file->redirect = ft_strdup(">");
    file->filename = ft_strdup("file1");
    exec->cmd = ft_strdup("echo");
    exec->arguments = ft_split("hicham fadyl", ' ');
    exec->files = malloc(sizeof(t_clist));
    exec->files->data = file;
    exec->files->next = NULL;
    file  = malloc(sizeof(t_file));
    file->filename = ft_strdup("f2");
    file->redirect = ft_strdup(">>");
    exec->files->next = malloc(sizeof(t_clist));
    exec->files->next->data = file;
    exec->files->next->next = NULL;
    t_clist *files = exec->files;
    while (files)
    {
        printf("%s %s\n", ((t_file *)files->data)->redirect, ((t_file *)files->data)->filename);
        files = files->next;
    }
    // if (check_if_builtins((char *)check->keys->data) == 1)
    // {
    //     if (ft_strncmp((char *)check->keys->data, "echo", 5))
    //     {
    //         printf("eccho >> %s\n", (char *)check->keys->data);
            
    //     }
    //     else if (ft_strncmp((char *)check->keys->data, "pwd", 4))
    //     {
    //         printf("pwd >> %s\n", (char *)check->keys->data);
    //     }
    // }
    // else
    // {
    //     printf("ach hna %s\n", (char *)check->keys->data);
    // }
}

int main()
{
    start_execut();
    return 0;
}
