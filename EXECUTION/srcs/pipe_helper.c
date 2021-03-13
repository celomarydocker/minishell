/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:37:56 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/13 17:54:23 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int         ft_pipe_return(int status)
{
   if (WIFSIGNALED(status))
   {
       return (WTERMSIG(status) + 128);
   }
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (0);
}