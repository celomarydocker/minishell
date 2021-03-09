/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:02:22 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/09 23:16:13 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"


void ft_export(t_cmap *envs, const char *line)
{
    char    **slt;

    slt = split_envirement_variable(line);
    setv(envs, slt[0], ft_cstrdup(slt[1]));
    free_split(slt);
}