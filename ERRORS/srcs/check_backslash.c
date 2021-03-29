/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_backslash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:25:44 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/29 14:33:09 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"

int	check_backslash(const char *line)
{
	int					backslash;
	unsigned int		iterator;

	iterator = 0;
	backslash = 0;
	while (line[iterator])
	{
		if (line[iterator] == '\\')
			backslash++;
		else
			backslash = 0;
		iterator++;
	}
	return (backslash % 2);
}
