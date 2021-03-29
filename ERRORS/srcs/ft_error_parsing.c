/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:39:57 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/29 13:08:01 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"

int	error_parsing(const char *line)
{
	int		error;

	error = print_error(semi_colon_dup(line), ';');
	if (error)
		return (258);
	error = print_error(pipe_dup(line), '|');
	if (error)
		return (258);
	error = print_error_quote(check_quotes(line));
	if (error)
		return (1);
	error = print_error_backslash(check_backslash(line));
	if (error)
		return (1);
	error = print_error_redirection(check_redirection(line));
	if (error)
		return (258);
	return (0);
}
