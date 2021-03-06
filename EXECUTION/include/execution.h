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

int         check_if_builtins(char *str);
void        ft_exec_echo(char **str);
void        ft_exec_pwd(char **str);
void        ft_pipe(t_clist  *pipe_exec, bool is_first, int old_stdin);
t_clist     *from_parsing2exec(const t_clist *lst);
t_clist     *combine_files_and_redirections(const t_clist *files, const t_clist *redirections);
void        **convert_list2array2d(const t_clist *lst, size_t  size);

#endif