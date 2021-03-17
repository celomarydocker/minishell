/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:56:34 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/17 17:32:48 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_buffer(char **buffer, char **line)
{
	if (!*line)
		*line = ft_realloc(NULL, 0, 1);
	free(*buffer);
	*buffer = NULL;
}

int		get_next_line_helper(int fd, char **line, char **buffer)
{
	static long	current;
	static long	pos;
	int			len;
	size_t		old_size;

	old_size = 0;
	while (1)
	{
		if (update_buffer(*buffer, &current, &pos, fd) <= 0)
		{
			if (!*line)
			{
				free_buffer(buffer, line);
				return (pos);
			}
		}
		len = get_len(*buffer, current, pos);
		*line = ft_realloc(line, old_size, (size_t)len);
		if (copy_to_line((*buffer) + current, (*line) + old_size, len))
		{
			current += len + 1;
			break ;
		}
		old_size += (size_t)len;
		current += len;
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*buffer;

	*line = NULL;
	if (!buffer)
		buffer = ft_realloc(NULL, 0, BUFFER_SIZE);
	return (get_next_line_helper(fd, line, &buffer));
}