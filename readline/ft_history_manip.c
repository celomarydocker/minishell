/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_manip.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:43:20 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/28 15:14:02 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"


void    init_history()
{
    g_global.g_history.up = 0;
    g_global.g_history.down = 0;
}

void    clear_st_line(void *data)
{
    clear_line(data);
}

void    clear_history()
{
    clear_stack(&g_global.g_history.up, clear_st_line);
    clear_stack(&g_global.g_history.down, clear_st_line);
    g_global.g_history.up = NULL;
    g_global.g_history.down = NULL;
}

void    froma2b(t_stack **a, t_stack **b)
{
    void        *data;

    data = pop_st(a);
    if (data)
        push(b, data);
}

void reset_line(struct s_line *line)
{
    if (line)
    {
        from_second_to_first(&line->left, &line->right);
        line->len = length_st(line->left);
        line->iterator = line->len;
    }
}

void    display_history_line()
{
    int    *c;

    tcapply("cb");
    tcapply("ce");
    write(1,"\r", 1);
    prompt();
    if (g_global.g_line)
    {
        from_second_to_first(&g_global.g_line->right, &g_global.g_line->left);
        c = pop_st(&g_global.g_line->right);
        while (c)
        {
            ft_putchar(c);
            push(&g_global.g_line->left, c);
            c = pop_st(&g_global.g_line->right);
        }
    }
}