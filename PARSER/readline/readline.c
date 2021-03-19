/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:11:40 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/19 14:51:56 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

char		*ft_realloc(char **buffer, size_t old_size, size_t new_size)
{
	char	*new_buff;
	size_t	iter;

	iter = 0;
	new_buff = malloc(sizeof(char) * (old_size + new_size));
	while (iter < old_size)
	{
		new_buff[iter] = (*buffer)[iter];
		iter++;
	}
	while (iter < new_size)
	{
		new_buff[iter] = 0;
		iter++;
	}
	if (old_size)
		free(*buffer);
	return (new_buff);
}

void    end_of_line()
{
    write(2, "exit\n", 5);
    exit(0);
}

static int    get_char(char *c)
{
    return (read(0, c, sizeof(char)));
}

int     readline(char **line)
{
    char                c;

    *line = 0;
    g_global.g_len_line = 0;
    if (!get_char(&c))
        return (1);
    while (c != '\n')
    {
        if (c != 0)
        {
            *line = ft_realloc(line, g_global.g_len_line, g_global.g_len_line + 2);
            (*line)[g_global.g_len_line + 1] = 0;
            (*line)[g_global.g_len_line] = c;
            c = 0;
            g_global.g_len_line++;
        }
        else
            write(2, "  \b\b", 4);
        get_char(&c);
    }
    return (0);
}