/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 02:29:02 by hfadyl            #+#    #+#             */
/*   Updated: 2019/10/23 05:43:27 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	if (*needle == 0)
		return ((char *)haystack);
	j = 0;
	while (j < len && haystack[j])
	{
		k = j;
		i = 0;
		while (haystack[k] == needle[i] && (j + i) < len)
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)(haystack + (k - i + 1)));
			k++;
		}
		j++;
	}
	return (0);
}
