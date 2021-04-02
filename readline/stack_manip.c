/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:49:17 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/02 16:52:18 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	from_second_to_first(t_stack **first, t_stack **second)
{
	void	*data;

	data = pop_st(second);
	while (data)
	{
		push(first, data);
		data = pop_st(second);
	}
}

void	transfer_one_char(t_stack **first, t_stack **second)
{
	void	*data;

	data = pop_st(second);
	if (data)
		push(first, data);
}

void	delete_one_char(t_stack **st)
{
	void	*data;

	data = pop_st(st);
	free(data);
}

size_t	length_st(const t_stack *st)
{
	size_t	len;

	len = 0;
	while (st)
	{
		len++;
		st = st->next;
	}
	return (len);
}

void	insert_char(t_stack **stack, int c)
{
	int		*d;

	d = malloc(sizeof(int));
	*d = c;
	push(stack, d);
}
