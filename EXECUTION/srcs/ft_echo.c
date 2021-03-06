/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:14:34 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/06 17:04:18 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void ft_exec_echo(char **str)
{
    int i = -1;
    int nl = 1;
    int j;
    if (str[0] == NULL)
        write(1, "\n", 1);
    while (str[++i])
    {
        j = 1;
        while (str[i][j] && str[i][0] == '-' && str[i][j] == 'n')
            j++;   
        if (str[i][j] && str[i][j] != 'n' && j > 0)
        {
            nl = (i == 0);
            break;  
        }
    }
    while (str[i])
    {
        ft_putstr_fd(str[i++], 1);
        if (!str[i+1])
            write(1, " ", 1);
    }
    if (nl)
        write(1, "\n", 1);
}