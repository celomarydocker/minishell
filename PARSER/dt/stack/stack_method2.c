/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_method2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:01:49 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/25 16:04:11 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	print_stack(const t_stack *stack, void display_data(void *data))
{
	if (stack)
	{
		display_data(stack->data);
		print_stack(stack->next, display_data);
	}
}
