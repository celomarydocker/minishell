/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_existance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:08:03 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/06 17:53:03 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"


t_permessions       check_existance(const char *command, const char *path, char **line)
{
    char                **spath;
    unsigned int        iterator;
    char                *joined;
    struct stat         s;

    if (check_if_builtins(command))
        return (BUILTINS);
    spath = ft_csplit((char *)path, ':', NULL);
    iterator = 0;
    *line = NULL;
    while (spath[iterator])
    {
        joined = ft_cstrjoin(ft_cstrdup(spath[iterator]), ft_cstrdup("/"));
        joined = ft_cstrjoin(joined, ft_cstrdup((char *)command));
        if (stat(joined, &s) == 0 && (s.st_mode & S_IEXEC))
        {
            *line = joined;
            return (FILE_EXEC);
        }
        free(joined);
        joined = NULL;
        iterator++;
    }
    return (NOT_FOUND);
}