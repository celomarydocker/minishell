/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:35:01 by hfadyl            #+#    #+#             */
/*   Updated: 2019/10/30 23:06:27 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*r;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	k = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	if (!(r = malloc(sizeof(char) * (i + j + 1))))
		return (0);
	while (*s1 != '\0')
		r[k++] = *s1++;
	while (*s2 != '\0')
		r[k++] = *s2++;
	r[k] = '\0';
	return (r);
}
