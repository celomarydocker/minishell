/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 22:56:09 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/02 17:30:25 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*k;

	k = (unsigned char *)s;
	while (n--)
	{
		if (*k == (unsigned char)c)
			return (k);
		k++;
	}
	return (0);
}
