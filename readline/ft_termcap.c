/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:46:02 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/03 21:08:57 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	tcapply(const char *id)
{
	char	*s;

	s = tgetstr((NCURSES_CONST char *)id, NULL);
	write(1, s, ft_cstrlen(s));
}
