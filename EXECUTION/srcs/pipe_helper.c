/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:37:56 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/07 12:42:41 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

int         ft_pipe_return(int status)
{
    if (WIFEXITED(status) && WEXITSTATUS(status) != EXIT_SUCCESS)
        return (WEXITSTATUS(status));
    return (EXIT_SUCCESS);
}