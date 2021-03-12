/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:37:56 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/12 20:58:11 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int         ft_pipe_return(int status)
{
   // if (WIFSIGNALED(status))
    //    return (WTERMSIG(status) + 128);
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (0);
}