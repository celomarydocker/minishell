/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_parsing2execution.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:32:14 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/07 11:30:24 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static char        **convert_list2array2d(const t_clist *lst)
{
    char    **array_2d;
    size_t  iterator;
    size_t  length_string;

    array_2d = malloc(sizeof(char *) * (length(lst) + 2));
    array_2d[0] = malloc(sizeof(char));
    array_2d[0][0] = 0;
    iterator = 1;
    while (lst)
    {
        length_string = ft_cstrlen((char *)lst->data);
        array_2d[iterator] = malloc(sizeof(char) * (length_string+ 1));
        ft_cstrcpy( array_2d[iterator], lst->data, length_string);
        lst = lst->next;
        iterator++;
    }
    array_2d[iterator] = NULL;
    return (array_2d);
}

static t_file   *create_file(const char *filename, const char *redirect)
{
    t_file      *file;

    file = malloc(sizeof(t_file));
    file->filename = ft_strdup(filename);
    if (!ft_strncmp(redirect, ">", 2))
        file->redirect = OUTPUT;
    else if (!ft_strncmp(redirect, "<", 2))
        file->redirect = INPUT;
    else
        file->redirect = APPEND;
    return (file);
}

static t_clist      *combine_files_and_redirections(const t_clist *files, const t_clist *redirections)
{
    t_clist     *combine;

    combine = NULL;
    while (files)
    {
        append(&combine, create_file(files->data, redirections->data));
        files = files->next;
        redirections = redirections->next;
    }
    return (combine);
}

static t_exec  *parse_exec(const t_ccommand *command, const char *path)
{
    t_exec      *exec;
    t_rec       *rec;
    char        *line;

    exec = malloc(sizeof(t_exec));
    exec->cmd = ft_cstrdup(command->cmd);
    exec->arguments = convert_list2array2d(command->data->text);
    exec->perm = check_existance(exec->cmd, path, &line);
    if (line)
    {
        free(exec->cmd);
        exec->cmd = line;
    }
    exec->files = combine_files_and_redirections(command->data->files, command->data->oper);    
    return (exec);
}

t_clist        *from_parsing2exec(const t_clist *lst, const char *path)
{
    t_clist     *execution;

    execution = NULL;
    while (lst)
    {
        append(&execution, parse_exec(lst->data, path));
        lst = lst->next;   
    }
    return (execution);
}
