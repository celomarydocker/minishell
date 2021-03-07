/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_existance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:08:03 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/06 21:52:47 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static int          is_command(const char *cmd)
{
    struct stat     s;
    if (stat(cmd, &s) == 0 && (s.st_mode & S_IEXEC))
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
            return (FILE_EXEC);
        }
        iterator++;
    }
    return (NOT_FOUND);
}