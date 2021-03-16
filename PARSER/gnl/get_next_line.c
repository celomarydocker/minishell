/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:56:34 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/16 17:02:59 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line_helper(int fd, char **line, char *buffer)
{
	static long	current;
	static long	pos;
	int			len;
	size_t		old_size;
	int			r;
	old_size = 0;
	while (1)
	{
		if (update_buffer(buffer, &current, &pos, fd) <= 0)
		{
			if (!*line)
			{
				*line = ft_realloc(NULL, 0, 1);
				return (pos);
			}
		}
		len = get_len(buffer, current, pos);
		*line = ft_realloc(line, old_size, (size_t)len);
		if ((r = copy_to_line((buffer) + current, (*line) + old_size, len)))
		{
			
			current += len + 1;
			break ;
		}
		old_size += (size_t)len;
		current += len;
	}
	return (pos);
}

int		get_next_line(int fd, char **line)
{
	static char		buffer[BUFFER_SIZE];

	*line = NULL;
	return (get_next_line_helper(fd, line, buffer));
}
