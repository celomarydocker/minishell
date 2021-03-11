/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:02:25 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/11 23:01:59 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"


int     ft_unset(char **arguments, int fd, t_cmap *envs)
{
    char    *value;

    value = pop_value(envs, arguments[0], ft_strlen(arguments[0]), free_envs);
    print("%s\n", value);
    free(value);
    return (0);
}
