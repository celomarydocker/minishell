/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 04:17:19 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/02 11:52:08 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

int	len_name(char *str)
{
	int		len;

	len = 0;
	if ((str[len] < 'A' || (str[len] > 'Z' && str[len] < 'a')
			|| str[len] > 'z') && !is_inset(str[len], "_?"))
		return (0);
	len++;
	while (str[len])
	{
		if (str[len] < '0' || (str[len] > '9' && str[len] < 'A'))
			break ;
		else if (((str[len] > 'Z' && str[len] < 'a')
				|| str[len] > 'z') && str[len] != '_')
			break ;
		len++;
	}
	return (len);
}

int	var_len(char *str, int *iter, t_cmap *map)
{
	int		len;
	char	*var;

	len = len_name(str + 1);
	*iter += len + 1;
	if (!len)
		return (1);
	var = ft_csubstr(str + 1, len);
	len = ft_cstrlen(get(map, var));
	free(var);
	return (len + 1);
}

int	variables(char *dest, char *str, int *iter, t_cmap *map)
{
	int		len;
	char	*var_name;
	char	*value;

	len = len_name(str + 1);
	*iter += len + 1;
	if (!len)
	{
		dest[0] = '$';
		dest[1] = 0;
		return (1);
	}
	var_name = ft_csubstr(str + 1, len);
	value = get(map, var_name);
	free(var_name);
	if (!value)
		return (0);
	len = ft_cstrlen(value);
	ft_cstrcpy(dest, value, len);
	return (len);
}

t_cmap	*put_vars(char **vars)
{
	int			iter;
	char		**sp;
	t_cmap		*map;

	map = init_map();
	iter = 0;
	while (vars[iter])
	{
		sp = split_envirement_variable(vars[iter]);
		setv(map, sp[0], ft_cstrdup(sp[1]));
		free_split(sp);
		iter++;
	}
	return (map);
}
