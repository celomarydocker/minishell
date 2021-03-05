#ifndef EXECUTION_H
# define EXECUTION_H
# include "../../minishell.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct  s_file
{
                char    *redirect;
                char    *filename;
}               t_file;

typedef struct s_exec
{
    char        *cmd;
    char        **arguments;
    t_clist     *files;
}               t_exec;

#endif