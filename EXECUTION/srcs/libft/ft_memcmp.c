/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:57:41 by hfadyl            #+#    #+#             */
/*   Updated: 2019/10/23 06:09:14 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*f;
	unsigned char	*e;

	i = 0;
	f = (unsigned char *)s1;
	e = (unsigned char *)s2;
	while (n--)
	{
		if (*f != *e)
			return (*f - *e);
		f++;
		e++;
	}
	return (0);
}
