/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_manip.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:43:20 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/02 17:17:00 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	init_history(void)
{
	g_global.g_history.up = 0;
	g_global.g_history.down = 0;
}

void	clear_st_line(void *data)
{
	clear_line(data);
}

void	clear_history(void)
{
	clear_stack(&g_global.g_history.up, clear_st_line);
	clear_stack(&g_global.g_history.down, clear_st_line);
	g_global.g_history.up = NULL;
	g_global.g_history.down = NULL;
}

void	froma2b(t_stack **a, t_stack **b)
{
	void	*data;

	data = pop_st(a);
	if (data)
		push(b, data);
}

void	reset_history(t_stack **up, t_stack **down)
{
	struct s_line	*line;

	line = pop_st(up);
	while (line)
	{
		if (length_st(line->left) || length_st(line->right))
			push(down, line);
		else
			clear_line(line);
		line = pop_st(up);
	}
}
