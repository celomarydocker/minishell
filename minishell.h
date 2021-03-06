#ifndef MINISHELL
# define MINISHELL
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "PARSER/gnl/get_next_line.h"
# include "PARSER/print/print.h"
# include "PARSER/split/ft_split.h"
# include "PARSER/dt/linkedlist/linkedlist.h"
# include "PARSER/dt/hash_table/hash_map.h"
# include "libft/libft.h"
# include "PARSER/command_recognizer/recognizer.h"
# include "./EXECUTION/include/execution.h"

extern char **environ;
#endif
