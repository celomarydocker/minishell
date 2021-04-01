/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:37:07 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/01 18:37:47 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int	ft_cstrcmp(const char *s1, const char *s2)
{
	unsigned int	iterator;

	iterator = 0;
	while (s1[iterator] && s2[iterator] && s1[iterator] == s2[iterator])
		iterator++;
	return ((int)(s1[iterator] - s2[iterator]));
}
