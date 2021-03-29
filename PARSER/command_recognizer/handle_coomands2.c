/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_coomands2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 07:12:10 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/29 15:31:21 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

t_clist	*get_commands(char *cmd, t_cmap *envs)
{
	t_clist	*cmds;

	cmds = NULL;
	append(&cmds, get_command_line(cmd, envs));
	return (cmds);
}

char	*single_double_quotes(char *str, int *iter, char c)
{
	char	*ret;

	(*iter)++;
	if (c == '"')
		ret = (double_quotes(str, iter));
	else
		ret = (single_quotes(str, iter));
	(*iter)++;
	return (ret);
}

int	check_for_variables(const char *str, unsigned int iterator)
{
	int		single_quotes;
	int		backslash;

	single_quotes = 0;
	backslash = 0;
	while (str[iterator])
	{
		if (str[iterator] == '$' && backslash % 2 == 0 && !single_quotes)
			return (1);
		if ((str[iterator] == '\'' || str[iterator] == '"')
			&& backslash % 2 == 0)
		{
			if (single_quotes)
				single_quotes = 0;
			else
				single_quotes = 1;
		}
		if (str[iterator] == '\\')
			backslash++;
		else
			backslash = 0;
		iterator++;
	}
	return (0);
}

void	copy(t_clist **a, t_clist *b)
{
	while (b)
	{
		append(a, ft_cstrdup((char *)b->data));
		b = b->next;
	}
}

t_rec	*join_rec(t_rec *rec1, t_rec *rec2)
{
	t_rec	*rec;

	rec = init_rec();
	if (rec1)
	{
		copy(&rec->files, rec1->files);
		copy(&rec->text, rec1->text);
		copy(&rec->oper, rec1->oper);
	}
	if (rec2)
	{
		copy(&rec->files, rec2->files);
		copy(&rec->text, rec2->text);
		copy(&rec->oper, rec2->oper);
	}
	free_rec(&rec1);
	free_rec(&rec2);
	return (rec);
}
