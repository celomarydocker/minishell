/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_method.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:00:31 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/25 16:04:46 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack **stack, void *data)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	temp->data = data;
	temp->next = NULL;
	if (!(*stack))
		*stack = temp;
	else
	{
		temp->next = *stack;
		*stack = temp;
	}
}

void	*pop_st(t_stack **stack)
{
	void	*data;
	t_stack	*next;

	if (!(*stack))
		return (NULL);
	data = (*stack)->data;
	next = (*stack)->next;
	free(*stack);
	*stack = next;
	return (data);
}

void	*peek(const t_stack *stack)
{
	if (stack)
		return (stack->data);
	return (NULL);
}

void	clear_stack(t_stack **stack, void free_data(void *data))
{
	if (*stack)
	{
		clear_stack(&(*stack)->next, free_data);
		free_data((*stack)->data);
		free(*stack);
		*stack = NULL;
	}
}
