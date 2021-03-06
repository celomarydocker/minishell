/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:14:34 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/06 12:14:59 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void ft_exec_echo(char **str)
{
    int i = -1;
    if (str[0] == NULL)
        write(1, "\n", 1);
    if (ft_strncmp(str[0], "-n", 3) == 0)
        i++;
    while (str[++i])
        ft_putstr_fd(str[i], 1);
    if (ft_strncmp(str[0], "-n", 3) != 0)
        write(1, "\n", 1);
}