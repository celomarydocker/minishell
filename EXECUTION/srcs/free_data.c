/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:18:28 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/02 15:58:29 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static void	free_files(void *data)
{
	t_file		*file;

	file = (t_file *)data;
	free(file->filename);
	free(file);
}

void	free_exec(void *exec)
{
	t_exec		*e;
	size_t		iterator;

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

void	free_envs(t_key_value *kv)
{
	free(kv->key);
	free(kv);
}
