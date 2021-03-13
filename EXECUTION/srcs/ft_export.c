/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:02:22 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/13 16:53:51 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"


void ft_export(t_cmap *envs, int is_pipe, int fd, const char *line)
{
    char    **slt;

    slt = split_envirement_variable(line);
    setv(envs, slt[0], ft_cstrdup(slt[1]));
    free_split(slt);
}