/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dupl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:58:13 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/29 13:04:27 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"

int	pipe_dup(const char *line)
{
	int					vars[4];
	unsigned int		iterator;

	init_vars_errors(&iterator, vars);
	while (line[iterator])
	{
		if (vars[2] > 1)
			return (2);
		if (!vars[3] && vars[2] == 1 && line[iterator] != '|')
			return (1);
		ds_quotes_checker(vars[1], line[iterator], &vars[3], &vars[0]);
		if (line[iterator] == '|' && !vars[0] && vars[1] % 2 == 0)
			vars[2]++;
		else
		{
			vars[3] = 1;
			vars[2] = 0;
		}
		check_back(&vars[1], line, iterator);
		iterator++;
	}
	return (vars[2]);
}

int	semi_colon_dup(const char *line)
{
	unsigned int		iterator;
	int					vars[4];

	init_vars_errors(&iterator, vars);
	while (line[iterator])
	{
		ds_quotes_checker(vars[1], line[iterator], &vars[3], &vars[0]);
		if (line[iterator] == ';' && !vars[0] && vars[1] % 2 == 0)
			vars[2]++;
		else
		{
			if (!vars[3] && vars[2] == 1 && line[iterator] != ';')
				return (1);
			if (line[iterator] != ' ')
				vars[3] = 1;
			vars[2] = 0;
		}
		if (vars[2] > 1)
			return (2);
		check_back(&vars[1], line, iterator);
		iterator++;
	}
	if (!vars[3] && vars[2] == 1 && line[iterator] != ';')
		return (1);
	return (0);
}
