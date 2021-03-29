/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_file_case_export.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:38:56 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/29 14:28:55 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"

int	check_for_space(const char *line, int *iterator, t_cmap *envs)
{
	int		len;
	char	*name;
	char	*value;

	len = len_name((char *)(line + *iterator + 1));
	name = ft_csubstr((char *)(line + *iterator + 1), len);
	*iterator += len + 1;
	len = 0;
	value = get(envs, name);
	free(name);
	if (!value)
		return (0);
	while (value[len])
	{
		if (value[len] == ' ')
			return (1);
		len++;
	}
	return (0);
}

static void	init_vars(int vars[4])
{
	vars[0] = 0;
	vars[1] = 0;
	vars[2] = 0;
	vars[3] = 0;
}

static void	export_amm(const char *line, int vars[4])
{
	if ((line[vars[3]] == '>' || line[vars[3]] == '<')
		&& vars[2] % 2 == 0 && !vars[1])
		vars[0] = 1;
	if ((line[vars[3]] == '\'' || line[vars[3]] == '"')
		&& vars[2] % 2 == 0)
	{
		if (!vars[1])
			vars[1] = line[vars[3]];
		else if (vars[1] == line[vars[3]])
			vars[1] = 0;
	}
	if (line[vars[3]] == '\\')
		vars[2]++;
	else
		vars[2] = 0;
	vars[3]++;
}

int	export_am(const char *line, t_cmap *envs)
{
	int		vars[4];

	init_vars(vars);
	while (line[vars[3]])
	{
		if (line[vars[3]] == '$' && vars[0]
			&& vars[2] % 2 == 0 && !vars[1])
		{
			if (check_for_space(line, &vars[3], envs))
				return (1);
			vars[0] = 0;
		}
		else
			export_amm(line, vars);
	}
	return (0);
}
