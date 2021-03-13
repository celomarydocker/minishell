/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:32:06 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/13 16:14:44 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int ft_isnumber(char *str)
{
    int i = -1;
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[++i])
        if (!ft_isdigit(str[i]))
            return (0);
    return (1);
}

int     ft_exec_exit(char **str, int fd, t_cmap *envs)
{
    int excod;

	excod = 0;
	if (str[0])
	{
		if (ft_isnumber(str[0]))
		{
			if (ft_strlentwo(str) > 1)
            {
                if (ilakan pipe)
			        print("exit\n");
                ft_putstr_fd("exit: too many arguments\n", 2);
				return (!ilakan pipe);
            }
			print("exit\n");
			excod = ft_atoi(str[0]);
		}
		else
		{
			print("exit\n");
			excod = 255;
            print("exit: %s: numeric argument required\n", str[0]);
		}
	}
    else
	    print("exit\n");
	exit(excod);
	return (1);
}

/*
bash-3.2$ exit 546 65453 | echo $?
bash: exit: too many arguments
0
bash-3.2$ exit 534 3546 354
exit
bash: exit: too many arguments
*/