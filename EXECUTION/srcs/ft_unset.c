/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:02:25 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/13 16:53:25 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int     ft_unset(char **arguments, int is_pipe, int fd, t_cmap *envs)
{
    char                *value;
    unsigned int        iterator;

    iterator = 0;
    value = pop_value(envs, arguments[0], ft_strlen(arguments[0]), free_envs);
    print("%s\n", value);
    free(value);
    return (0);
}
