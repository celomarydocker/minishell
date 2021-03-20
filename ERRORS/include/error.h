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
void    command_not_found_error(const char *cmd);
void    check_back(int *back_vars, const char *line, unsigned int iterator);
void    command_perm_denied(const char *command);
void    init_vars_errors(unsigned int *iterator, int *vars);
void    ds_quotes_checker(int back, char c, int *other, int *ds);
#endif