/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:14:47 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/07 14:40:55 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

// change function return from void to int to check errors
int ft_exec_pwd(char **str, int fd, t_cmap * envs)
{
    char pwd[200];
    getcwd(pwd, 200 * sizeof(char));
    ft_putstr_fd(pwd, fd);
    ft_putstr_fd("\n", fd);
    return (0);
}