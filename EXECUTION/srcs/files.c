/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:04:37 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/07 11:39:22 by mel-omar@st      ###   ########.fr       */
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

t_pair_files    iofile(t_clist *files, int *error)
{
    t_pair_files pair;
    t_file       *file;

    pair.input = -1;
    pair.output = -1;
    error = 0;
    while (files)
    {
        file = files->data;
        if (file->redirect == INPUT)
        {
            if (pair.input != -1)
                close(pair.input);
            pair.input = input_file(file);
            if (pair.input == -1)
                *error = 255;
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
                print("FILE NOT CREATED\n");
        }
        files = files->next;
    }
    return (pair);   
}