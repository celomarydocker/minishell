 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:48:36 by hfadyl            #+#    #+#             */
/*   Updated: 2021/03/08 11:25:10 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void ft_exec_cd(char **str)
{
    char *der;

    der = opendir(*str);
    if (der != NULL)
    {
        
    }
    else
    {
        // print error
        ft_putstr_fd(str,1);
    }
}
// int main()
// {
//     char s[1000];

//     printf("%s\n", getcwd(s, 100));  // print current working directory
  
//     chdir(".."); // change the directory

//     printf("%s\n", getcwd(s, 100)); // print the change directory
  
//     return 0; 
// }