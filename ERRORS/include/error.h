#ifndef ERROR
# define ERROR
# include "../../minishell.h"

int     pipe_dup(const char *line);
int     semi_colon_dup(const char *line);
int     check_quotes(const char *line);
int     check_backslash(const char *line);
int     check_redirection(const char *line);
int     print_error(int error, char c);
int     print_error_quote(int error);
int     print_error_backslash(int error);
int     print_error_redirection(int error);
int     error_parsing(const char *line);
int     export_am(const char *line, t_cmap *envs);
#endif