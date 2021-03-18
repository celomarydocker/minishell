/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:11:40 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/18 21:57:29 by mel-omar         ###   ########.fr       */
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

static char    get_char()
{
    char    c;

    c = 0;
    read(0, &c, sizeof(char));
    return (c);
}

int     readline(char **line)
{
    unsigned int        iter;
    char                c;

    *line = 0;
    iter = 0;
    c = get_char();
    if (c == '\0')
        return (1);
    while (c != '\n')
    {
        if (c != 0)
        {
            *line = ft_realloc(line, iter, iter + 1);
            (*line)[iter] = c;
            iter++;
        }
        else
            write(2, "  \b\b", 4);
        c = get_char();
    }
    if(*line)
    {
        *line = ft_realloc(line, iter, iter + 1);
        (*line)[iter] = 0;
    }
    return (0);
}