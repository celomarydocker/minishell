/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:50:03 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/29 17:43:40 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

char	*ft_csubstr(char *str, int len)
{
	char	*s;
	int		iter;

	iter = 0;
	s = malloc(sizeof(char) * (len + 1));
	while (iter < len)
	{
		s[iter] = str[iter];
		iter++;
	}
	s[len] = 0;
	return (s);
}

int	ft_cstrlen(const char *s)
{
	int		len;

	if (!s)
		return (0);
	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_cstrcpy(char *dst, const char *src, int len)
{
	int	iter;

	if (!src)
		return (dst);
	iter = 0;
	while (iter < len)
	{
		dst[iter] = src[iter];
		iter++;
	}
	dst[len] = 0;
	return (dst);
}

char	*ft_cstrjoin(char *text, char *s)
{
	char	*new_text;
	int		len1;
	int		len2;

	len1 = ft_cstrlen(text);
	len2 = ft_cstrlen(s);
	new_text = malloc(sizeof(char) * (len1 + len2 + 1));
	ft_cstrcpy(new_text, text, len1);
	ft_cstrcpy(new_text + len1, s, len2);
	free(text);
	free(s);
	return (new_text);
}

char	*ft_cstrdup(char *str)
{
	char		*s;
	int			iter;

	if (!str)
		return (NULL);
	s = malloc(sizeof(char) * (ft_cstrlen(str) + 1));
	iter = 0;
	while (str[iter] != '\0')
	{
		s[iter] = str[iter];
		iter++;
	}
	s[iter] = 0;
	return (s);
}
