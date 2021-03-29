/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_envirement_variables.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:45:14 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/29 18:07:15 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

static unsigned int	found_first_equal(const char *line)
{
	unsigned int	iterator;

	iterator = 0;
	while (line[iterator])
	{
		if (line[iterator] == '=')
			return (iterator);
		iterator++;
	}
	return (iterator);
}

char	**split_envirement_variable(const char *line)
{
	char			**envs;
	unsigned int	index_equal;

	envs = malloc(sizeof(char *) * 3);
	index_equal = found_first_equal(line);
	envs[2] = NULL;
	envs[0] = ft_csubstr((char *)line, index_equal);
	if (line[index_equal])
		envs[1] = ft_csubstr((char *)(line + index_equal + 1),
				ft_strlen(line) - index_equal - 1);
	else
		envs[1] = ft_cstrdup(NULL);
	return (envs);
}
