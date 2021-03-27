/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:57:48 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/27 23:34:49 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void        key_up()
{
        if (peek(g_global.g_history.down))
        {
                reset_line(g_global.g_line);
                push(&g_global.g_history.up, g_global.g_line);
                g_global.g_line = pop_st(&g_global.g_history.down); 
                display_history_line();
        }
}

void        key_down()
{
        if (peek(g_global.g_history.up))
        {
                reset_line(g_global.g_line);
                push(&g_global.g_history.down, g_global.g_line);
                g_global.g_line = pop_st(&g_global.g_history.up);
                display_history_line();
        }
}

void        key_left()
{
        transfer_one_char(&g_global.g_line->right, &g_global.g_line->left);
        tcapply("le");
        g_global.g_line->iterator--;
}

void        key_right()
{
        transfer_one_char(&g_global.g_line->left, &g_global.g_line->right);
        tcapply("nd");
        g_global.g_line->iterator++;
}

void        key_remove_char()
{
        delete_one_char(&g_global.g_line->left);
        tcapply("le");
        tcapply("sc");
        tcapply("ce");
        print_stack(g_global.g_line->right, ft_putchar);
        tcapply("rc");
        g_global.g_line->iterator--;
        g_global.g_line->len--;
}
