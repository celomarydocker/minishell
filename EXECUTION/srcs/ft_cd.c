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


// change function return from void to int to check errors

int    ft_exec_cd(char **str, int fd, t_cmap *envs)
{
    char    *to_der;
    char    buffer[200];
    char    *old_pwd;

    if (!*str)
    {
        to_der = get(envs, "HOME");
        old_pwd = ft_strdup(get(envs, "PWD"));
        chdir(to_der);
        getcwd(buffer, 200);
        setv(envs, "PWD", ft_strdup(buffer));
        setv(envs, "OLDPWD", old_pwd);
    }
    else
    {
        if (!chdir(*str))
        {
            // print("old pwd %s\n", get(envs, "PWD"));
            getcwd(buffer, 200);
            old_pwd = ft_strdup(get(envs, "PWD"));
            setv(envs, "PWD", ft_strdup(buffer));
            setv(envs, "OLDPWD", old_pwd);
            // print("new pwd %s\n", get(envs, "PWD"));
        }
        else
        {
            ft_putstr_fd("cd : no such file or directory ", fd);
            write(fd, "\n", 1);
        }
    }
    return (0);
}
// int main()
// {
//     char s[1000];

//     printf("%s\n", getcwd(s, 100));  // print current working directory
  
//     chdir(".."); // change the directory

//     printf("%s\n", getcwd(s, 100)); // print the change directory
  
//     return 0; 
// }
