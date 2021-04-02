/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_unused.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:32:30 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/01 18:32:40 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void	ft_disable_unused(char ***str, int *is_pipe, int *fd, t_cmap **envs)
{
	*str = NULL;
	*is_pipe = 0;
	*fd = -1;
	*envs = NULL;
}
