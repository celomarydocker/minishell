/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:55:13 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/31 17:28:17 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_stack
{
	void			*data;
	struct s_stack	*next;
}				t_stack;

void				copy_data(void *dst, void *src, size_t len);
void				push(t_stack **stack, void *data);
void				*pop_st(t_stack **stack);
void				*peek(const t_stack *stack);
void				print_stack(const t_stack *stack,
						void display_data(void *data));
void				clear_stack(t_stack **stack, void free_data(void *data));
#endif
