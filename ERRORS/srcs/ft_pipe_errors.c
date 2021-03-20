/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:39:04 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/20 21:09:47 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"

void         command_not_found_error(const char *cmd)
{
        ft_putstr_fd("CSHELL: ", 2);
        ft_putstr_fd((char *)cmd, 2);
        ft_putstr_fd(": command not found\n", 2);
        exit(127);
}

void         command_perm_denied(const char *command)
{
    ft_putstr_fd("CSHELL: ", 2);
    ft_putstr_fd((char *)command, 2);
    ft_putstr_fd(": Permission denied\n", 2);
    exit(126);
}
