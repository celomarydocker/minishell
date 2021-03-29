/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:15:48 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/29 12:40:33 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"

static int	return_quotes(int lock)
{
	if (lock)
		return (1);
	return (0);
}

int	check_quotes(const char *line)
{
	int					lock;
	unsigned int		iterator;
	int					backslash;

	lock = 0;
	iterator = 0;
	backslash = 0;
	while (line[iterator])
	{
		if ((backslash % 2 == 0 || lock == '\'')
			&& (line[iterator] == '\'' || line[iterator] == '"'))
		{
			if (!lock)
				lock = line[iterator];
			else if (lock == line[iterator])
				lock = 0;
		}
		if (line[iterator] == '\\')
			backslash++;
		else
			backslash = 0;
		iterator++;
	}
	return (return_quotes(lock));
}
