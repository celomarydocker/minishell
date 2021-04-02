/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:44 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/02 17:31:53 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	help;

	help = n;
	if (n < 0)
	{
		help = help * (-1);
		ft_putchar_fd('-', fd);
	}
	if (help >= 10)
	{
		ft_putnbr_fd(help / 10, fd);
	}
	ft_putchar_fd(help % 10 + 48, fd);
}
