#ifndef EXECUTION_H
# define EXECUTION_H
# define bool int
# include "../../minishell.h"
/* TESTING STUFF */
# include <stdio.h>
/* END */

typedef enum e_enum {INPUT, OUTPUT, APPEND} t_enum;
typedef enum e_permessions {NOT_FOUND = -1, BUILTINS, FILE_EXEC} t_permessions;
typedef void (*t_builtin_function)(char **str, int fd);
typedef struct s_pair_files
{
    int         input;
    int         output;
}              t_pair_files;

typedef struct  s_file
{
                t_enum  redirect;
                char    *filename;
}               t_file;

typedef struct      s_exec
{
    char            *cmd;
    char            **arguments;
    t_permessions   perm;
    t_clist         *files;
}                   t_exec;

t_cmap              *g_builtins;

int                 check_if_builtins(const char *str);
void                ft_exec_echo(char **str, int fd);
void                ft_exec_pwd(char **str, int fd);
int                 ft_pipe(t_clist *pipe_exec, bool is_first, int old_stdin);
t_clist		        *from_parsing2exec(const t_clist *lst, const char *path);
t_permessions       check_existance(const char *command, const char *path, char **line);
void                free_exec(void *exec);
t_pair_files        iofile(t_clist *files, int *error);
int                 ft_pipe_return(int status);
void                init_builtins(t_cmap **map);
void                insert_builtins(t_cmap *map, const char *builtin_name, t_builtin_function builtin_funcn);
t_builtin_function  get_builtins(t_cmap *mp, const char *key);
#endif
