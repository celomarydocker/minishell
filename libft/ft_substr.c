/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:21:27 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/02 17:38:10 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned long start, size_t len)
{
	int				k;
	int				i;
	int				j;
	char			*tab;

	if (!s)
		return (NULL);
	if (s[0] == '\0' || start > ft_strlen(s))
	{
		tab = malloc(1 * sizeof(char));
		tab[0] = '\0';
		return (tab);
	}
	i = 0;
	j = len + start;
	k = start;
	tab = (char *)malloc((len + 1) * sizeof(char));
	while (s[start] != '\0' && k++ < j)
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}
