/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_existance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:08:03 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/16 17:38:07 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"


int                 check_cmd(const char *n)
{
    unsigned int iterator;

    iterator = 0;
    while (n[iterator])
    {
        if (n[iterator] == '/')
            return (0);
        else if (n[iterator] != '.')
            break;
        iterator++;
    }
    return (1);
}

static int          is_command(const char *cmd)
{
    struct stat     s;

    if (stat(cmd, &s) == 0 && (s.st_mode & S_IEXEC) && !check_cmd(cmd))
        return (1);
    return (0);
}

static  char *             join_command(const char *path, char **cmd)
{
    char    *joined;

    joined = ft_cstrjoin(ft_cstrdup((char *)path), ft_cstrdup("/"));
    joined = ft_cstrjoin(joined, *cmd);
    if (is_command(joined))
        return (joined);
    free(joined);
    return (NULL);
}

t_permessions       check_existance(const char *command, const char *path, char **line)
{
    char                **spath;
    unsigned int        iterator;
    char                *cmd;

    *line = NULL;
    if (check_if_builtins(command))
        return (BUILTINS);
    spath = ft_csplit((char *)path, ':', NULL);
    iterator = 0;
    while (spath[iterator])
    {
        cmd = ft_cstrdup((char *)command);
        if (is_command(cmd) || (cmd = join_command(spath[iterator], &cmd)))
        {
            *line = cmd;
            free_split(spath);
            return (FILE_EXEC);
        }
        iterator++;
    }
    free_split(spath);
    return (NOT_FOUND);
}