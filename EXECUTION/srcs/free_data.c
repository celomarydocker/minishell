/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:02:03 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/06 21:15:44 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/execution.h"

static void    free_exec(void *data)
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
    while (e->arguments[iterator])
    {
        free(e->arguments[iterator]);
        iterator++;
    }
    free(e->arguments);
    e->arguments = NULL;
    clear_list(&e->files, free_exec);
    free(e);
}