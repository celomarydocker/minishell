/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:04:37 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/06 22:51:51 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static int      append_file(t_file *file)
{
    return (open(file->filename, O_APPEND | O_TRUNC | O_CREAT));
}

static int      output_file(t_file *file)
{
    return (open(file->filename, O_WRONLY | O_TRUNC | O_CREAT));
}

static int      input_file(t_file *file)
{
    return (open(file->filename, O_RDONLY));
}

t_pair_files    iofile(t_clist *files)
{
    t_pair_files pair;
    t_file       *file;

    pair.intput = -1;
    pair.output = -1;
    while (files)
    {
        file = files->data;
        if (file->redirect == INPUT)
        {
            if (pair.intput != -1)
                close(pair.intput);
            pair.intput = input_file(file->filename);
            if (pair.intput == -1)
                print("ERROR\n");
        }
        else
        {
            if (pair.output != -1)
                close(pair.output);
            if (file->redirect == APPEND)
                pair.output = append_file(file->filename);
            if (file->redirect == OUTPUT)
                pair.output = output_file(file->filename);
            if (pair.output == -1)
                print("FILE NOT CREATED\n");
        }
        files = files->next;
    }
    return (pair);   
}