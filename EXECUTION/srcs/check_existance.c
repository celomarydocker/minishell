/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_existance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:08:03 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/17 17:42:55 by mel-omar@st      ###   ########.fr       */
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

    if (stat(cmd, &s) == 0 && !check_cmd(cmd))
    {
        if (s.st_mode & S_IEXEC)
            return (1);
        else
            return (2);
    }
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

int                 check_perm(const char *command, const char *path, char **line)
{
    char                *cmd;
    int                 ret;

    cmd = ft_cstrdup((char *)command);
    cmd = join_command(path, &cmd);
    ret = is_command(cmd);
    if (ret == 1)
    {
        *line = cmd; 
        return (1);
    }
    return (0);
}

t_permessions       sample_command(const char *command, char **line)
{
    int     ret;

    ret = is_command(command);
    if (ret == 1)
    {
        *line = ft_cstrdup((char *)command);
        return (FILE_EXEC);
    }
    else if (ret == 2)
    {
        *line = NULL;
        return (PERMISSION_DENIED);
    }
    return (NOT_FOUND);
}

t_permessions       check_existance(const char *command, const char *path, char **line)
{
    char                **spath;
    unsigned int        iterator;
    int                 ret;

    *line = NULL;
    if (!command)
        return (WITHOUT);
    if (check_if_builtins(command))
        return (BUILTINS);
    spath = ft_csplit((char *)path, ':', NULL);
    iterator = 0;
    while (spath[iterator])
    {
        if (check_perm(command, spath[iterator], line))
        {
            free_split(spath);
            return (FILE_EXEC);
        }
        iterator++;
    }
    free_split(spath);    
    return sample_command(command, line);
}