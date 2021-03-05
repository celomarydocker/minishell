/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:57:35 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/05 10:25:25 by hfadyl           ###   ########.fr       */
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

    file = malloc(sizeof(*file));
    exec = malloc(sizeof(*exec));
    file->redirect = ft_strdup(">");
    file->filename = ft_strdup("file1");
    exec->cmd = ft_strdup("echo");
    exec->arguments = ft_split("hicham fadyl", ' ');
    exec->files->data = ft_strdup("file1");
    exec->files->next = NULL;

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
