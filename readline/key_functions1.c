/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:57:48 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/03 15:28:22 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	key_up(void)
{
	if (peek(g_global.g_temp.down))
	{
		reset_line(g_global.g_line);
		push(&g_global.g_temp.up, g_global.g_line);
		g_global.g_line = pop_st(&g_global.g_temp.down);
		print_stack(g_global.g_line->left, ft_putchar);
		display_history_line();
	}
}

void	key_down(void)
{
	if (peek(g_global.g_temp.up))
	{
		reset_line(g_global.g_line);
		push(&g_global.g_temp.down, g_global.g_line);
		g_global.g_line = pop_st(&g_global.g_temp.up);
		display_history_line();
	}
}

void	key_left(void)
{
	transfer_one_char(&g_global.g_line->right, &g_global.g_line->left);
	tcapply("le");
	g_global.g_line->iterator--;
}

void	key_right(void)
{
	transfer_one_char(&g_global.g_line->left, &g_global.g_line->right);
	tcapply("nd");
	g_global.g_line->iterator++;
}

void	key_remove_char(void)
{
	int		g;

	g_global.g_total = g_global.g_line->len + 4 + g_global.count_prompt;
	if (g_global.g_total % tgetnum("co") == 0)
	{
		tcapply("dl");
		tcapply("up");
		g = 0;
		while (g++ < tgetnum("co"))
			tcapply("nd");
	}
	delete_one_char(&g_global.g_line->left);
	tcapply("le");
	tcapply("sc");
	tcapply("ce");
	print_stack(g_global.g_line->right, ft_putchar);
	tcapply("rc");
	g_global.g_line->iterator--;
	g_global.g_line->len--;
}
