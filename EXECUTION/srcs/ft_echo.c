/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:14:34 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/11 10:16:45 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"


// change function return from void to int to check errors

int ft_exec_echo(char **str, int fd, t_cmap *envs)
{
    int i;
    int nl;
    int j;

    i = -1;
    nl = 1;
    if (!str)
          write(fd, "\n", 1);
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
    //hadi li zti hna kadir mochkil
    --i; // i added this to check return of pipe; 
    while (str[i])
    {
        ft_putstr_fd(str[i++], fd);
        // if (i != 1 && str[i])
        //     write(fd, " ", 1);
        if (!str[i+1])
            write(1, " ", 1);
    }
    if (nl)
        write(fd, "\n", 1);
    return (0);
}
