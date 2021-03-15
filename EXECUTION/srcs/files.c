/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:04:37 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/15 10:39:37 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static int      append_file(t_file *file)
{
    return (open(file->filename, O_APPEND | O_RDWR | O_CREAT, 0644));
}

static int      output_file(t_file *file)
{
    return (open(file->filename, O_RDWR | O_TRUNC | O_CREAT, 0644));
}

static int      input_file(t_file *file)
{
    return (open(file->filename, O_RDONLY));
}

t_pair_files    iofile(t_clist *files, int *error, char **file_error)
{
    t_pair_files pair;
    t_file       *file;

    pair.input = -1;
    pair.output = -1;
    *error = 0;
    while (files)
    {
        file = files->data;
        if (file->redirect == INPUT)
        {
            if (pair.input != -1)
                close(pair.input);
            pair.input = input_file(file);
            if (pair.input == -1)
            {
                *error = 47;
                *file_error = file->filename;
                break;
            }
        }
        else
        {
            if (pair.output != -1)
                close(pair.output);
            if (file->redirect == APPEND)
                pair.output = append_file(file);
            if (file->redirect == OUTPUT)
                pair.output = output_file(file);
            if (pair.output == -1)
            {
                *error = 74;
                *file_error = file->filename; 
                break;
            }
        }
        files = files->next;
    }
    return (pair);   
}