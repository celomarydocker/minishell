/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:44:49 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/02 17:33:08 by hfadyl           ###   ########.fr       */
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
	r = (char *)malloc(sizeof(char) * (j + 1));
	if (!r)
		return (0);
	while (i < j)
	{
		r[i] = s1[i];
		i++;
	}
	r[j] = '\0';
	return (r);
}
