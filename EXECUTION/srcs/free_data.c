/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:02:03 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/08 19:02:36 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/execution.h"

static void    free_files(void *data)
{
    t_file      *file;

    file = (t_file *)data;
    free(file->filename);
    free(file);
}

void free_exec(void  *exec)
{
    t_exec      *e;
    size_t      iterator;

    e = (t_exec *)exec;
    free(e->cmd);
    iterator = 0;
    while (e->arguments[iterator] != NULL)
    {
        free(e->arguments[iterator]);
        iterator++;
    }
    free(e->arguments);
    e->arguments = NULL;
    clear_list(&e->files, free_files);
    free(e);
}