#ifndef EXECUTION_H
# define EXECUTION_H
# define bool int
# include "../../minishell.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

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

#endif