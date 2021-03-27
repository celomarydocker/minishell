/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_method.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:57:34 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/27 22:57:21 by mel-omar         ###   ########.fr       */
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