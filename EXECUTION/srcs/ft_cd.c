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

int    ft_exec_cd(char **str, int is_pipe, int fd, t_cmap *envs)
{
    // mohammed initial 'OLDPWD' b "cd: OLDPWD not set" and don't print it in envs untill 'OLDPWD' has another value.
    char    *to_der;
    char    *buffer;
    char    *s;
    buffer = malloc(64);
    if (!*str || ft_strncmp(*str, "--", 3) == 0)
    {
        to_der = get(envs, "HOME");
        chdir(to_der);
        getcwd(buffer, 64);
        setv(envs, "OLDPWD", ft_strdup(get(envs, "PWD")));
        setv(envs, "PWD", buffer);
    }
    else
    {
        if (ft_strncmp(*str, "-", 2) == 0)
        {
            if (chdir(s = get(envs, "OLDPWD")) == -1)
                printf("cd: OLDPWD not set\n");
            else
            {
                setv(envs, "OLDPWD", ft_strdup(get(envs, "PWD")));
                setv(envs, "PWD", getcwd(buffer, 64));
                printf("%s\n", buffer);
            }
        }
        else if (!(chdir(*str)))
        {
            getcwd(buffer, 64);
            setv(envs, "OLDPWD", ft_strdup(get(envs, "PWD")));
            setv(envs, "PWD", buffer);
        }
        else
        {
            // ft_putstr_fd(ft_strjoin("cd: no such file or directory: ", *str) , fd);
            // write(fd, "\n", 1);
            return (1);
        }
    }
    return (0);
}
