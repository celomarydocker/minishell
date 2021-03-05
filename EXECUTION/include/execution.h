#ifndef EXECUTION_H
# define EXECUTION_H
# define bool int
# include "../../minishell.h"
/* TESTING STUFF */
# include <stdio.h>
/* END */

typedef enum s_enum {INPUT, OUTPUT, APPEND} t_enum;
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


void		ft_pipe(t_clist *pipe_exec, bool is_first, int old_stdin);
char		**convert_list2array2d(const t_clist *lst, size_t size);
t_clist		*from_parsing2exec(const t_clist *lst);

#endif
