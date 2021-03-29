/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_coomands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 07:10:13 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/29 15:16:19 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

char	*get_command(char *str, int *iter)
{
	char	*s;

	s = NULL;
	while (str[*iter] == ' ')
		(*iter)++;
	while (str[*iter] && !in_set(str[*iter], " ><"))
	{
		if (str[*iter] == '\'' || str[*iter] == '"')
			s = ft_cstrjoin(s, single_double_quotes(str, iter, str[*iter]));
		else
			s = ft_cstrjoin(s, withback(str, iter));
	}
	return (s);
}

t_rec	*handle_command(char *str, int *iter, int is_found)
{
	int			is_file;
	t_rec		*rec;

	is_file = 0;
	rec = init_rec();
	while (str[*iter])
	{
		if (str[*iter] == '>' || str[*iter] == '<')
		{
			get_oper(str, iter, &rec->oper);
			is_file = 1;
		}
		else if (is_file)
		{
			enter(str, iter, &rec->files);
			is_file = 0;
		}
		else if (!is_found)
			break ;
		else if (str[*iter] != ' ')
			enter(str, iter, &rec->text);
		while (str[++(*iter)] == ' ')
			;
	}
	return (rec);
}

t_clist	*join_command(t_clist **first, t_clist **second)
{
	t_clist	*lst;

	lst = joined_list(*first, *second);
	clear_list(first, NULL);
	clear_list(second, NULL);
	return (lst);
}

void	add_command(char *cmd, t_clist **lst, int error)
{
	int				i;
	int				is_found;
	t_ccommand		*command;

	is_found = 0;
	i = 0;
	command = malloc(sizeof(t_ccommand));
	command->cmd = NULL;
	command->data = NULL;
	while (cmd[i] == ' ')
		i++;
	while (!is_found)
	{
		if (!in_set(cmd[i], "><"))
		{
			command->cmd = get_command(cmd, &i);
			is_found = 1;
		}
		command->data = join_rec(command->data,
				handle_command(cmd, &i, is_found));
	}
	command->error = error;
	append(lst, command);
}

t_clist	*get_command_line(char *cmd, t_cmap *global_vars)
{
	t_clist			*all_cmds;
	char			**commands;
	int				iter;
	char			*replaced;

	all_cmds = NULL;
	commands = csplit(cmd, '|');
	iter = 0;
	while (commands[iter])
	{
		replaced = ft_replace_envs(commands[iter], global_vars);
		add_command(replaced, &all_cmds,
		export_am(commands[iter], global_vars));
		free(replaced);
		iter++;
	}
	free_split(commands);
	return (all_cmds);
}
