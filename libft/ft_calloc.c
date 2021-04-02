/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 01:40:15 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/02 17:25:42 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	s = malloc(count * size);
	while (i < size * count)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
