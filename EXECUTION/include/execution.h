#ifndef EXECUTION_H
# define EXECUTION_H
# define bool int
# include "../../minishell.h"
/* TESTING STUFF */
# include <stdio.h>
/* END */

typedef enum e_enum {INPUT, OUTPUT, APPEND} t_enum;
typedef enum e_permessions {NOT_FOUND = -1, BUILTINS, FILE_EXEC} t_permessions;
typedef int (*t_builtin_function)(char **str, int is_pipe, int fd, t_cmap *envs);
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



int                 check_if_builtins(const char *str);
int                 ft_exec_echo(char **str, int is_pipe, int fd, t_cmap *envs);
int                 ft_exec_pwd(char **str, int is_pipe, int fd, t_cmap *envs);
int                 ft_exec_cd(char **str, int is_pipe, int fd, t_cmap *envs);
int                 ft_pipe(t_clist *pipe_exec, bool is_first, int old_stdin, t_cmap *envs);
t_clist		        *from_parsing2exec(const t_clist *lst, const char *path);
t_permessions       check_existance(const char *command, const char *path, char **line);
void                free_exec(void *exec);
void                free_envs(t_key_value *kv);
t_pair_files        iofile(t_clist *files, int *error);
int                 ft_pipe_return(int status);
void                init_builtins(t_cmap **map);
void                insert_builtins(t_cmap *map, const char *builtin_name, t_builtin_function builtin_funcn);
t_builtin_function  get_builtins(t_cmap *mp, const char *key);
void                free_builtins(void *data);
int                 ft_unset(char **arguments, int is_pipe, int fd, t_cmap *envs);
int                 ft_exec_exit(char **str, int is_pipe, int fd, t_cmap *envs);
char                **from_map_to_array_2d(t_cmap *map, const char *cmd);
#endif
