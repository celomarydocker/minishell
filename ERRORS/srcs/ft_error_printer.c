/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:24:31 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/29 14:02:57 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"

static void	ft_print_char(int times, char c)
{
	int	iter;

	iter = 0;
	while (iter++ < times)
		write(2, &c, 1);
}

int	print_error(int error, char c)
{
	if (error)
	{
		ft_putstr_fd("CSHELL: syntax error near unexpected token `", 2);
		ft_print_char(error, c);
		ft_putstr_fd("'\n", 2);
	}
	return (error);
}

int	print_error_quote(int error)
{
	if (error)
		ft_putstr_fd("CSHELL: syntax error quotes not closed\n", 2);
	return (error);
}

int	print_error_backslash(int error)
{
	if (error)
		ft_putstr_fd("CSHELL: unxpected backslash at the end\n", 2);
	return (error);
}

int	print_error_redirection(int error)
{
	if (error)
	{
		if (error == 4)
			ft_putstr_fd("CSHELL: syntax error near unexepected token\ 
			`newline'\n", 2);
		else if (error == 3)
			ft_putstr_fd("CSHELL: syntax error near unexepected token `>'\n", 2);
		else if (error == 2)
			ft_putstr_fd("CSHELL: syntax error near unexepected token `<'\n", 2);
		else if (error == 5)
			ft_putstr_fd("bash: syntax error near unexpected token `|'\n", 2);
		else if (error == 6)
			ft_putstr_fd("bash: syntax error near unexpected token `;'\n", 2);
	}
	return (error);
}
