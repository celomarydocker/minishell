#ifndef ERROR
# define ERROR
# include "../../minishell.h"

int     pipe_dup(const char *line);
int     semi_colon_dup(const char *line);
int     check_quotes(const char *line);
int     check_backslash(const char *line);
#endif