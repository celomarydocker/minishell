/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:57:44 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/27 23:02:57 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void        enter_key(char **line)
{
    size_t     len;
    size_t     iterator;
    void        *data;
    while (g_global.g_line->iterator > 0)
            key_left();
    from_second_to_first(&g_global.g_line->right, &g_global.g_line->left);
    write(1, "\n", 1);
    len = length_st(g_global.g_line->right);
    *line = malloc(sizeof(char) * (len + 1));
    iterator = 0;
    while (iterator < len)
    {
        data = pop_st(&g_global.g_line->right);
        (*line)[iterator] = *((char *)data);
        push(&g_global.g_line->left, data);
        iterator++;
    }
    (*line)[iterator] = 0;
    if (g_global.g_line->len > 0)
    {
        reset_line(g_global.g_line);
        push(&g_global.g_history.down, g_global.g_line);
    }
    else
        clear_line(g_global.g_line);
}

void     ctrl_d(t_stack *left, t_stack *right)
{
    if (!length_st(left) && !length_st(right))
    {
        write(2, "exit\n", 5);
        exit(0);
    }
}


void    ctrl_l(void)
{
    write(1, "here", 5);
    tcapply("cl");
    display_history_line();
}