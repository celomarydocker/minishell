/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:43:33 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/17 17:33:15 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 128

# include <stdlib.h>
# include <unistd.h>

char		*ft_realloc(char **buffer, size_t old_size, size_t new_size);
int			get_len(char *buffer, long current, long pos);
int			copy_to_line(char *buffer, char *line, int len);
long		update_buffer(char *buffer, long *current, long *pos, int fd);
int			get_next_line_helper(int fd, char **line, char **buffer);
int			get_next_line(int fd, char **line);
#endif
