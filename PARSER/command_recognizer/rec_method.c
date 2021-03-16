/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_method.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:02:30 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/16 17:28:08 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"


char        *get(t_cmap *map, const char *key)
{
    return (get_value(map, key, ft_cstrlen(key)));
}

void        setv(t_cmap *map, const char *key, char *value)
{
    char    *val;

    val = get(map, key);
    if (!value && val)
        return ;
    if (val)
        free(val);
    set_value(map, key, value, ft_cstrlen(key));
}

t_rec       *get_cmd(t_cmap *map, char *key)
{
    return (get_value(map, key, ft_cstrlen(key)));
}

void        set_cmd(t_cmap *map, char *key, t_rec *value)
{
    set_value(map, key, value, ft_cstrlen(key));
}

int			in_set(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}