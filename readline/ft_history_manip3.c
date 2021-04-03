/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_manip3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:17:33 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/04/03 10:08:45 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	reset_line(struct s_line *line)
{
	if (line)
	{
		from_second_to_first(&line->left, &line->right);
		line->len = length_st(line->left);
		line->iterator = line->len;
	}
}

void	display_history_line(void)
{
	int	*c;

	tcapply("rc");
	write(1, "\r", 1);
	tcapply("cd");
	tcapply("sc");
	prompt();
	if (g_global.g_line)
	{
		print_stack(g_global.g_line->right, ft_putchar);
		from_second_to_first(&g_global.g_line->right, &g_global.g_line->left);
		c = pop_st(&g_global.g_line->right);
		while (c)
		{
			ft_putchar(c);
			push(&g_global.g_line->left, c);
			c = pop_st(&g_global.g_line->right);
		}
	}
}
