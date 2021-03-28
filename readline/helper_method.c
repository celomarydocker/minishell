/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_method.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:57:34 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/28 17:43:16 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

struct s_line    *init_line(void)
{
        struct s_line   *line;

        line = malloc(sizeof(struct s_line));
        line->left = 0;
        line->right = 0;
        line->len = 0;
        line->iterator = 0;
        return (line);
}

void    clear_line(struct s_line *line)
{
        clear_stack(&line->left, free);
        clear_stack(&line->right, free);
        free(line);
}

int             get_char()
{
        char    c;
        int     total;
        struct termios term, init;

        tcgetattr(0, &term);
        tcgetattr(0, &init);
        term.c_lflag &= ~(ICANON | ECHO);
        term.c_cc[VMIN] = 0;
        term.c_cc[VTIME] = 0;
        tcsetattr(0, TCSANOW, &term);
        total = 0;
        while (read(0, &c, 1) <= 0);
        total += c;
        while (read(0, &c, 1) > 0)
                total += c;
        tcsetattr(0, TCSANOW, &init);
        return (total);
}

int             ft_puts(int d)
{
        return (write(1, &d, sizeof(int)));
}

void             ft_putchar(void *dt)
{
        write(1, dt, sizeof(int));
}

void                    reverse_stack(t_stack **st)
{
        t_stack         *head;
        t_stack         *before;
        t_stack         *tmp;
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

void                    copystack(t_stack **dest, const t_stack *src)
{
        int     *d;
        while (src)
        {
                d = malloc(sizeof(int));
                *d = *((int *)src->data);
                push(dest, d);
                src = src->next;
        }
        reverse_stack(dest);
}

struct s_line           *copyline(const struct s_line   *line)
{
        struct s_line           *cline;

        cline = init_line();
        copystack(&cline->left, line->left);
        copystack(&cline->right, line->right);
        cline->iterator = line->iterator;
        cline->len = line->len;
        reset_line(cline);
        return (cline);
}

void                    copyhistory()
{
        t_stack         *tmp;

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

void                   cleartemp()
{
        clear_stack(&g_global.g_temp.up, clear_st_line);
        clear_stack(&g_global.g_temp.down, clear_st_line);
        g_global.g_temp.up = NULL;
        g_global.g_temp.down = NULL;       
}
