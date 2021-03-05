/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_parsing2execution.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:32:14 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/05 17:26:36 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

char        **convert_list2array2d(const t_clist *lst, size_t  size)
{
    char    **array_2d;
    size_t  iterator;

    array_2d = malloc(size * (length(lst) + 1));
    iterator = 0;
    while (lst)
    {
        ft_memcpy(*(array_2d + iterator * size), lst->data, size);
        lst = lst->next;
        iterator++;
    }
    *(array_2d + iterator * size) = NULL;
    return (array_2d);
}

static t_file   *create_file(const char *filename, const char *redirect)
{
    t_file      *file;

    file = malloc(sizeof(t_file *));
    file->filename = ft_strdup(filename);
    if (!ft_strncmp(redirect, ">", 2))
        file->redirect = OUTPUT;
    else if (!ft_strncmp(redirect, "<", 2))
        file->redirect = INPUT;
    else
        file->redirect = APPEND;
    return (file);
}

t_clist      *combine_files_and_redirections(const t_clist *files, const t_clist *redirections)
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

static t_exec  *parse_exec(const t_ccommand *command)
{
    t_exec      *exec;
    t_rec       *rec;

    exec = malloc(sizeof(t_exec));
    exec->cmd = ft_strdup(command->cmd);
    exec->arguments = convert_list2array2d(command->data->text, sizeof(char *));
    exec->files = combine_files_and_redirections(command->data->files, command->data->oper);    
    return (exec);
}

t_clist        *from_parsing2exec(const t_clist *lst)
{
    t_clist     *execution;

    execution = NULL;
    while (lst)
    {
        append(&execution, parse_exec(lst->data));
        lst = lst->next;   
    }
    return (execution);
}
