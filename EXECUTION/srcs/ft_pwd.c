/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:14:47 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/02 16:13:39 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int	ft_exec_pwd(char **str, int is_pipe, int fd, t_cmap *envs)
{
	char	pwd[200];

	getcwd(pwd, 200 * sizeof(char));
	ft_putstr_fd(pwd, fd);
	ft_putstr_fd("\n", fd);
	ft_disable_unused(&str, &is_pipe, &fd, &envs);
	return (0);
}
