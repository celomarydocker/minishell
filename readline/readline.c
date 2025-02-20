/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:14:17 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/03 21:05:34 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	set_char(int c)
{
	insert_char(&g_global.g_line->left, c);
	g_global.g_total = g_global.g_line->len + 4 + g_global.count_prompt;
	if (g_global.g_total % tgetnum("co") == 0)
		write(1, "\n", 1);
	write(1, &c, sizeof(int));
	tcapply("sc");
	print_stack(g_global.g_line->right, ft_putchar);
	g_global.g_line->len++;
	g_global.g_line->iterator++;
	tcapply("rc");
}

static int	some_logic(int d, char **line)
{
	if (d >= 32 && d < 127)
		set_char(d);
	else if (d == KEY_UP)
		key_up();
	else if (d == KEY_DOWN)
		key_down();
	else if (d == KEY_LEFT && g_global.g_line->iterator > 0)
		key_left();
	else if (d == KEY_RIGHT
		&& g_global.g_line->iterator < g_global.g_line->len)
		key_right();
	else if (d == KEY_REMOVE
		&& g_global.g_line->iterator > 0)
		key_remove_char();
	else if (d == CTRL_D)
		ctrl_d(g_global.g_line->left, g_global.g_line->right);
	else if (d == ENTER)
	{
		enter_key(line);
		return (1);
	}
	else if (d == CTRL_L)
		ctrl_l();
	return (0);
}

char	*readline(t_cmap *envs)
{
	int		d;
	char	*string;

	g_global.g_line = init_line();
	copyhistory();
	string = getenv("TERM");
	if (!string)
	{
		ft_putstr_fd("TERM environment variable not set.\n", 2);
		setv(envs, "?", ft_cstrdup("1"));
		exit(1);
	}
	tgetent(NULL, string);
	string = 0;
	tcapply("sc");
	prompt();
	while (1)
	{
		d = get_char();
		if (some_logic(d, &string))
			break ;
	}
	cleartemp();
	return (string);
}
