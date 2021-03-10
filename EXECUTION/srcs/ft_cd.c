 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:48:36 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/08 11:25:10 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"



void    ft_exec_cd(char **str, int fd, t_cmap *envs)
{
    char    *to_der;
    char    *buffer;

    buffer = malloc(64);
    if (!*str)
    {
        to_der = get(envs, "HOME");
        // print("old pwd %s\n", get(envs, "PWD"));
        chdir(to_der);
        getcwd(buffer, 64);
        setv(envs, "PWD", buffer);
        // print("new pwd %s\n", get(envs, "PWD"));
    }
    else
    {
        if (!(chdir(*str)))
        {
            // print("old pwd %s\n", get(envs, "PWD"));
            getcwd(buffer, 64);
            setv(envs, "PWD", buffer);
            // print("new pwd %s\n", get(envs, "PWD"));
        }
        else
        {
            ft_putstr_fd("cd : no such file or directory ", fd);
            write(1, "\n", 1);
        }
    }
}
// int main()
// {
//     char s[1000];

//     printf("%s\n", getcwd(s, 100));  // print current working directory
  
//     chdir(".."); // change the directory

//     printf("%s\n", getcwd(s, 100)); // print the change directory
  
//     return 0; 
// }
