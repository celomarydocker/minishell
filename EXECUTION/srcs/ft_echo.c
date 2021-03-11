/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:14:34 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/11 15:05:49 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"


// change function return from void to int to check errors

// int ft_exec_echo(char **str, int fd, t_cmap *envs)
// {
//     int i;
//     int nl;
//     int j;

//     i = -1;
//     nl = 1;
//     if (!str)
//           write(fd, "\n", 1);
//     // if (str[0] == NULL)
//     //     write(fd, "\n", 1);
//     while (str[++i])
//     {
//         j = 1;
//         while (str[i][j] && str[i][0] == '-' && str[i][j] == 'n')
//             j++;   
//         if (str[i][j] && str[i][j] != 'n' && j > 0)
//         {
//             nl = (i == 0);
//             break;  
//         }
//     }
//     //hadi li zti hna kadir mochkil
//     // --i; // i added this to check return of pipe; 
//     while (str[i])
//     {
//         ft_putstr_fd(str[i++], fd);
//         // if (i != 1 && str[i])
//         //     write(fd, " ", 1);
//         if (!str[i+1])
//             write(1, " ", 1);
//     }
//     if (nl)
//         write(fd, "\n", 1);
//     return (0);
// }

short	ft_chkopt(char **args, int *i)
{
	short	nl;
	int		j;
	*i = -1;
	nl = 1;
	while (args[++(*i)])
	{
		j = 0;
		if (args[*i][0] == '-')
		{
			while (args[*i][++j])
				if (args[*i][j] != 'n')
					break ;
			if (*i == 0)
				nl = !(!args[*i][j] && args[*i][j - 1] == 'n');
			if (args[*i][j] && args[*i][j] != 'n')
				break ;
		}
		else
			break ;
	}
	return (nl);
}

int ft_exec_echo(char **str, int fd, t_cmap *envs)
{
    short newline;
    int i;
    
    if (!str[0])
        return (!(write(fd, "\n", 1)));
    newline = ft_chkopt(str, &i);
    while (str[i])
	{
		ft_putstr_fd(str[i++], fd);
		if (str[i])
			write(fd, " ", 1);
	}
	if (newline)
		write(fd, "\n", 1);
	return (0);
}