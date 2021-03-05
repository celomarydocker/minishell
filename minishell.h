#ifndef MINISHELL
# define MINISHELL
# include "PARSER/command_recognizer/recognizer.h"
# include "./EXECUTION/include/execution.h"
# include "libft/libft.h"

void    all_commands(char *s, char **envs);
#endif
