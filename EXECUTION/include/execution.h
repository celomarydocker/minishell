#ifndef EXECUTION_H
# define EXECUTION_H
# define bool int
# include "../../minishell.h"
/* TESTING STUFF */
# include <stdio.h>
/* END */

typedef enum s_enum {INPUT, OUTPUT, APPEND} t_enum;
typedef enum s_permessions{NOT_FOUND = -1, BUILTINS, FILE_EXEC} t_permessions;

typedef struct  s_file
{
                t_enum  redirect;
                char    *filename;
}               t_file;

typedef struct s_exec
{
    char        *cmd;
    char        **arguments;
    t_clist     *files;
}               t_exec;

int                 check_if_builtins(const char *str);
void		        ft_pipe(t_clist *pipe_exec, bool is_first, int old_stdin);
t_clist		        *from_parsing2exec(const t_clist *lst);
t_permessions       check_existance(const char *command, const char *path, char **line);
#endif
