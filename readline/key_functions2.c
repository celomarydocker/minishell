/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:57:44 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/02 13:03:17 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static void	init_vars(size_t *len, size_t *iterator,
char **line, const t_stack *stack)
{
	*iterator = 0;
	*len = length_st(stack);
	*line = malloc(sizeof(char) * (*len + 1));
}

void	enter_key(char **line)
{
	size_t		len;
	size_t		iterator;
	void		*data;

	while (g_global.g_line->iterator > 0)
		key_left();
	from_second_to_first(&g_global.g_line->right, &g_global.g_line->left);
	write(1, "\n", 1);
	init_vars(&len, &iterator, line, g_global.g_line->right);
	while (iterator < len)
	{
		data = pop_st(&g_global.g_line->right);
		(*line)[iterator] = *((char *)data);
		push(&g_global.g_line->left, data);
		iterator++;
	}
	(*line)[iterator] = 0;
	reset_history(&g_global.g_history.up, &g_global.g_history.down);
	if (g_global.g_line->len > 0)
	{
		reset_line(g_global.g_line);
		push(&g_global.g_history.down, g_global.g_line);
	}
	else
		clear_line(g_global.g_line);
}

void	ctrl_d(t_stack *left, t_stack *right)
{
	if (!length_st(left) && !length_st(right))
	{
		write(2, "exit\n", 5);
		exit(0);
	}
}

void	ctrl_l(void)
{
	tcapply("cl");
	display_history_line();
}
