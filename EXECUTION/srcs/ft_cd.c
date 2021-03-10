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
    // mohammed initial 'OLDPWD' b "cd: OLDPWD not set" and don't print it in envs untill 'OLDPWD' has another value.
    char    *to_der;
    char    *buffer;
    char    *s;
    buffer = malloc(64);
    if (!*str || ft_strncmp(*str, "--", 3) == 0)
    {
        to_der = get(envs, "HOME");
        print("old pwd %s\n", get(envs, "PWD"));
        chdir(to_der);
        getcwd(buffer, 64);
        setv(envs, "OLDPWD", get(envs, "PWD"));
        setv(envs, "PWD", buffer);
        print("new pwd %s\n", get(envs, "PWD"));
    }
    else
    {
        if (ft_strncmp(*str, "-", 2) == 0)
        {
            if (chdir(s = get(envs, "OLDPWD")) == -1);
                printf("%s\n", s);
            else
            {
                setv(envs, "OLDPWD", get(envs, "PWD"));
                setv(envs, "PWD", getcwd(buffer, 64));
                printf("%s\n", buffer);
            }
        }
        else if (!(chdir(*str)))
        {
            print("old pwd %s\to_dern", get(envs, "PWD"));
            getcwd(buffer, 64);
            setv(envs, "OLDPWD", get(envs, "PWD"));
            setv(envs, "PWD", buffer);
            print("new pwd %s\n", get(envs, "PWD"));
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
  
//     chdir(".."); // chan        chdir(to_der);ge the directory

//     printf("%s\n", getcwd(s, 100)); // print the change directory
  
//     return 0; 
// }
