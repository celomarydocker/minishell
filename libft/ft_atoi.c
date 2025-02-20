/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:57:56 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/02 17:24:53 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getsign(const char *str, int *i)
{
	if (str[*i] == '-')
	{
		*i += 1;
		return (-1);
	}
	else if (str[*i] == '+')
	{
		*i += 1;
		return (1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = getsign(str, &i);
	while (str[i] != '\0')
	{
		if (result > 2147483648 && sign == -1)
			return (0);
		if (result > 2147483647 && sign == 1)
			return (-1);
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		else
			return (result * sign);
		i++;
	}
	return (result * sign);
}
