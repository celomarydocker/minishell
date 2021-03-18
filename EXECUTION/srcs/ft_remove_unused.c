/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_unused.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:28:28 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/18 16:32:10 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void    ft_disable_unused(char ***str, int *is_pipe, int *fd, t_cmap **envs)
{
    *str = NULL;
    *is_pipe = 0;
    *fd = -1;
    *envs = NULL;
}