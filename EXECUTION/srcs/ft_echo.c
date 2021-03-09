/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:14:34 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/09 16:00:48 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void ft_exec_echo(char **str, int fd)
{
    int i;
    int nl;
    int j;

    i = -1;
    nl = 1;
    if (str[0] == NULL)
        write(fd, "\n", 1);
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
        ft_putstr_fd(str[i++], fd);
        if (str[i])
            write(fd, " ", 1);
    }
    //if (nl)
        write(fd, "\n", 1);
}