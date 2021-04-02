/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_manip2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:06:40 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/04/02 17:18:17 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	reverse_stack(t_stack **st)
{
	t_stack			*head;
	t_stack			*before;
	t_stack			*tmp;

	head = *st;
	before = NULL;
	while (head)
	{
		tmp = head->next;
		head->next = before;
		before = head;
		head = tmp;
	}
	*st = before;
}

void	copystack(t_stack **dest, const t_stack *src)
{
	int	*d;

	while (src)
	{
		d = malloc(sizeof(int));
		*d = *((int *)src->data);
		push(dest, d);
		src = src->next;
	}
	reverse_stack(dest);
}

struct s_line	*copyline(const struct s_line *line)
{
	struct s_line	*cline;

	cline = init_line();
	copystack(&cline->left, line->left);
	copystack(&cline->right, line->right);
	cline->iterator = line->iterator;
	cline->len = line->len;
	reset_line(cline);
	return (cline);
}

void	copyhistory(void)
{
	t_stack		*tmp;

	g_global.g_temp.up = 0;
	g_global.g_temp.down = 0;
	tmp = g_global.g_history.down;
	while (tmp)
	{
		push(&g_global.g_temp.down, copyline(tmp->data));
		tmp = tmp->next;
	}
	tmp = g_global.g_history.up;
	while (tmp)
	{
		push(&g_global.g_temp.down, copyline(tmp->data));
		tmp = tmp->next;
	}
	reverse_stack(&g_global.g_temp.down);
}

void	cleartemp(void)
{
	clear_stack(&g_global.g_temp.up, clear_st_line);
	clear_stack(&g_global.g_temp.down, clear_st_line);
	g_global.g_temp.up = NULL;
	g_global.g_temp.down = NULL;
}
