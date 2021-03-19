#ifndef MINISHELL
# define MINISHELL

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "PARSER/readline/readline.h"
# include "PARSER/print/print.h"
# include "PARSER/split/ft_split.h"
# include "PARSER/dt/linkedlist/linkedlist.h"
# include "PARSER/dt/hash_table/hash_map.h"
# include "libft/libft.h"
# include "PARSER/command_recognizer/recognizer.h"
# include "EXECUTION/include/execution.h"
# include "ERRORS/include/error.h"
# include <errno.h>

# define ICANON 0x00000100
# define ECHO 0x00000008

extern char **environ;


struct          s_global
{
    int                 g_pid;
	int					sigint_ret;
    int                 cerrno;
    char                *g_line;
    size_t              g_len_line;
    pid_t               pid;
    t_cmap              *g_builtins;
}                       g_global;
#endif
