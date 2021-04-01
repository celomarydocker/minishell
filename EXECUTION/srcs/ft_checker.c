/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:22:33 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/01 18:23:23 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int	is_lower(char c)
{
	if (c < 'a' || c > 'z')
		return (0);
	return (1);
}

int	is_upper(char c)
{
	if (c < 'A' || c > 'Z')
		return (0);
	return (1);
}

int	is_digits(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	is_variable_not_valid(const char *variable_name)
{
	unsigned int	iter;

	if (!is_lower(variable_name[0]) && !is_upper(variable_name[0])
		&& variable_name[0] != '_')
		return (1);
	iter = 1;
	while (variable_name[iter])
	{
		if (!is_lower(variable_name[iter]) && !is_upper(variable_name[iter])
			&& !is_digits(variable_name[iter]) && variable_name[iter] != '_')
		{
			if (variable_name[iter] == ' ')
				return (2);
			return (1);
		}
		iter++;
	}
	return (0);
}
