/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:15:29 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/01 18:18:01 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static int		append_file(t_file *file)
{
	return (open(file->filename, O_APPEND | O_RDWR | O_CREAT, 0644));
}

static void		output_file(t_file *file, t_pair_files *pair)
{
	if (file->redirect == APPEND)
		pair->output = append_file(file);
	if (file->redirect == OUTPUT)
		pair->output = (open(file->filename,
					O_RDWR | O_TRUNC | O_CREAT, 0644));
}

static int		input_file(t_file *file)
{
	return (open(file->filename, O_RDONLY));
}

static int		io_manip(t_file *file, t_pair_files *pair, char **file_error,
		int *error)
{
	if (file->redirect == INPUT)
	{
		if (pair->input != -1)
			close(pair->input);
		pair->input = input_file(file);
		if (pair->input == -1)
		{
			*error = 47;
			*file_error = file->filename;
			return (1);
		}
	}
	else
	{
		if (pair->output != -1)
			close(pair->output);
		output_file(file, pair);
		if (pair->output == -1)
		{
			*error = 74;
			*file_error = file->filename;
			return (1);
		}
	}
	return (0);
}

t_pair_files	iofile(t_clist *files, int *error, char **file_error)
{
	t_pair_files	pair;

	pair.input = -1;
	pair.output = -1;
	*error = 0;
	while (files)
	{
		if (io_manip(files->data, &pair, file_error, error))
			break ;
		files = files->next;
	}
	return (pair);
}
