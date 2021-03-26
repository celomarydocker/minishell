#ifndef MINISHELL
# define MINISHELL


extern char **environ;

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
# include <termio.h>
# include <termcap.h>

struct s_line
{
        t_stack         *left;
        t_stack         *right;
        int             len;
        int             iterator;
};

struct s_history
{
    t_stack             *up;
    t_stack             *down;
};

struct          s_global
{
    int                 g_pid;
    struct s_line       *g_line;
    struct s_history    g_history;
    int                 sigint_ret;
    t_cmap              *g_builtins;
}                       g_global;

void    prompt(void);
#endif
