/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:47:33 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/04/03 15:28:44 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "PARSER/print/print.h"
# include "PARSER/dt/linkedlist/linkedlist.h"
# include "PARSER/dt/hash_table/hash_map.h"
# include "libft/libft.h"
# include "PARSER/command_recognizer/recognizer.h"
# include "PARSER/dt/stack/stack.h"
# include "readline/readline.h"
# include "EXECUTION/include/execution.h"
# include "ERRORS/include/error.h"
# include <errno.h>
# include <termios.h>
# include <termcap.h>

struct s_line
{
	t_stack			*left;
	t_stack			*right;
	int				len;
	int				iterator;
};

struct s_history
{
	t_stack				*up;
	t_stack				*down;
};

struct s_global
{
	int					g_pid;
	struct s_line		*g_line;
	struct s_history	g_history;
	struct s_history	g_temp;
	int					count_prompt;
	int					is_prompt;
	int					sigint_ret;
	int					g_total;
	t_cmap				*g_builtins;
}	g_global;

void	prompt(void);
#endif
