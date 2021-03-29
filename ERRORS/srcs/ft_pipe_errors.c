/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:39:04 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/29 14:30:30 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"

void	command_not_found_error(const char *cmd)
{
	ft_putstr_fd("CSHELL: ", 2);
	ft_putstr_fd((char *)cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}

void	command_perm_denied(const char *command)
{
	ft_putstr_fd("CSHELL: ", 2);
	ft_putstr_fd((char *)command, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	exit(126);
}
