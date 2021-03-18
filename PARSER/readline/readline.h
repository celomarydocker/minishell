/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:11:50 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/18 12:18:05 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H
# include <stdlib.h>
# include <unistd.h>

void    end_of_line();
int     readline(char **line);
#endif