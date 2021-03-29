/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:46:44 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/29 12:59:29 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"

static int	check_for_redirection(const char *s,
unsigned int *iter, char red_char)
{
	int		count_red;

	count_red = 0;
	while (s[*iter] == '>' || s[*iter] == '<')
	{
		if (s[*iter] != red_char)
		{
			if (s[*iter] == '<')
				return (2);
			return (3);
		}
		count_red++;
		(*iter)++;
	}
	if (count_red > 1 && red_char == '<')
		return (2);
	if (count_red > 2 && red_char == '>')
		return (3);
	return (1);
}

static int	check_for_file(const char *s, unsigned int *i)
{
	while (s[*i])
	{
		if (s[*i] == '>' || s[*i] == '<')
			return (0);
		if (s[*i] == '|')
			return (5);
		if (s[*i] == ';')
			return (6);
		if (s[*i] != ' ')
			return (1);
		(*i)++;
	}
	return (0);
}

int	norminette_problems(int which_case, int vars[5],
	unsigned int *iterator, const char *line)
{
	if (which_case == 1)
	{
		if (!vars[3])
			vars[3] = line[*iterator];
		else if (line[*iterator] == vars[3])
			vars[3] = 0;
	}
	else if (which_case == 2)
	{
		vars[0] = check_for_redirection(line, iterator, line[*iterator]);
		vars[1] = check_for_file(line, iterator);
		if (vars[0] != 1 || vars[1] != 1)
		{
			if (vars[0] == 1 && vars[1] > 1)
				return (vars[1]);
			if (!line[*iterator] && vars[0] == 1)
				return (4);
			return (vars[0]);
		}
	}
	return (0);
}

int	check_redirection(const char *line)
{
	unsigned int	iterator;
	int				vars[5];

	init_vars_errors(&iterator, vars);
	while (line[iterator])
	{
		if (vars[2] % 2 == 0)
		{
			if (line[iterator] == '\'' || line[iterator] == '"')
				norminette_problems(1, vars, &iterator, line);
			if ((line[iterator] == '>' || line[iterator] == '<') && !vars[3])
			{
				vars[4] = norminette_problems(2, vars, &iterator, line);
				if (vars[4])
					return (vars[4]);
				if (!line[iterator])
					break ;
			}
		}
		check_back(&vars[2], line, iterator);
		iterator++;
	}
	return (0);
}
