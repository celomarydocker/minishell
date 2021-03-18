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
        setv(envs, "PWD", ft_cstrdup(buffer));
    }
    else
    {
        if (ft_strncmp(*str, "-", 2) == 0)
        {
            if (chdir(s = get(envs, "OLDPWD")) == -1)
            {
                ft_putstr_fd("cd: OLDPWD not set\n", 2);
                //return (1);
            }
            else
            {
                setv(envs, "OLDPWD", ft_strdup(get(envs, "PWD")));
                setv(envs, "PWD", getcwd(buffer, 64));
                print("%s\n", buffer);
            }
        }
        else if (!(chdir(*str)))
        {
            getcwd(buffer, 64);
            setv(envs, "OLDPWD", ft_strdup(get(envs, "PWD")));
            setv(envs, "PWD", ft_cstrdup(buffer));
        }
        else
        {
            s = ft_cstrjoin(ft_cstrdup("CSHELL: cd: no such file or directory: "), ft_cstrdup(*str));
            ft_putstr_fd(s, 2);
            write(2, "\n", 1);
            free(s);
            free(buffer);
            return (1);
        }
    }
    free(buffer);
    ft_disable_unused(&str, &is_pipe, &fd, &envs);
    return (0);
}
