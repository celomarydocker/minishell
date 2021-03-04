/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:44:49 by hfadyl            #+#    #+#             */
/*   Updated: 2019/10/30 23:20:09 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
		j++;
	if (!(r = (char *)malloc(sizeof(char) * (j + 1))))
		return (0);
	while (i < j)
	{
		r[i] = s1[i];
		i++;
	}
	r[j] = '\0';
	return (r);
}
