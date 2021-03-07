/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hicham <hicham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:45:51 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/07 21:03:17 by hicham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int     check_if_builtins(const char *str)
{
    if (ft_strncmp(str, "echo", 5) == 0 || ft_strncmp(str, "cd", 3) == 0 ||
    ft_strncmp(str, "pwd", 4) == 0 || ft_strncmp(str, "export", 7) == 0 ||
    ft_strncmp(str, "env", 4) == 0 || ft_strncmp(str, "exit", 5) == 0 ||
    ft_strncmp(str, "unset", 6) == 0)
    {
        return (1);
    }
    else 
        return (0);
}

/*void           init_builtins(t_cmap **map)
{
    *map = init_map();   
}

void            insert_builtins(t_cmap *map, const char *builtin_name, t_builtin_function builtin_funcn)
{
    set_value(map, ft_cstrdup((char *)builtin_name), builtin_funcn, ft_cstrlen(builtin_name));
}

t_builtin_function            get_builtins(t_cmap *mp, const char *key)
{
    return ((t_builtin_function)get_value(mp, key, ft_cstrlen(key)));
}

void        free_builtins(void *data)
{
    t_key_value *key_value;
    free(key_value->key);
    free(key_value);
}*/