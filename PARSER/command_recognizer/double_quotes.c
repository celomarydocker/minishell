/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 03:48:49 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/29 14:52:27 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

static int	double_quotes_back(char *s)
{
	int		len;
	int		iter;
	int		lock;

	len = 0;
	iter = -1;
	while (s[++iter] != 0)
	{
		if (s[iter] == '"' && lock)
			break ;
		if (s[iter] == '\\' && in_set(s[iter + 1], "$\"") && lock)
		{
			lock = 0;
			continue ;
		}
		len++;
		lock = 1;
	}
	return (len);
}

static void	init_vars(int *i, int *i1, int *i2)
{
	*i = 0;
	*i1 = -1;
	*i2 = 1;
}

static void	double_quotes_helper(char *s, int *i, char c)
{
	s[*i] = c;
	(*i)++;
}

static char	*double_quotes_helper2(char *s, int *i, int iter2, int iter)
{
	*i += iter;
	s[iter2] = 0;
	return (s);
}

char	*double_quotes(char *str, int *i)
{
	char		*s;
	int			len;
	int			iter;
	int			iter2;
	int			lock;

	len = double_quotes_back(str + *i);
	s = malloc(sizeof(char) * (len + 3));
	init_vars(&iter2, &iter, &lock);
	while (str[++iter + *i] != 0)
	{
		if (str[iter + *i] == '"' && lock)
			break ;
		if (str[iter + *i] == '\\' && in_set(str[iter + 1 + *i], "$\"\\") && lock)
			lock = 0;
		else
		{
			double_quotes_helper(s, &iter2, str[iter + *i]);
			lock = 1;
		}
	}
	return (double_quotes_helper2(s, i, iter2, iter));
}
