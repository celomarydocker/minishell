/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hicham <hicham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:57:41 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/07 21:02:02 by hicham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*f;
	unsigned char	*e;

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
