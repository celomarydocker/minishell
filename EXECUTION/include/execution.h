/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:44:11 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/04/01 15:21:49 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include "../../minishell.h"
# include <stdio.h>
# define BOOL int
typedef enum e_enum {INPUT, OUTPUT, APPEND}	t_enum;
typedef enum e_permessions
{
	NOT_FOUND = -1,
	BUILTINS,
	FILE_EXEC,
	PERMISSION_DENIED,
	WITHOUT
}	t_permessions;
typedef int	(*t_builtin_function)(char **str,
			int is_pipe, int fd, t_cmap *envs);

typedef struct s_pair_files
{
	int			input;
	int			output;
}	t_pair_files;

typedef struct s_file
{
	t_enum		redirect;
	char		*filename;
}	t_file;

typedef struct s_exec
{
	char			*cmd;
	char			**arguments;
	t_permessions	perm;
	t_clist			*files;
	int				error;
}	t_exec;

int					check_if_builtins(const char *str);
int					ft_exec_echo(char **str, int is_pipe, int fd, t_cmap *envs);
int					ft_exec_pwd(char **str, int is_pipe, int fd, t_cmap *envs);
int					ft_exec_cd(char **str, int is_pipe, int fd, t_cmap *envs);
int					ft_pipe(t_clist *pipe_exec,
						BOOL is_first, int old_stdin, t_cmap *envs);
t_clist				*from_parsing2exec(const t_clist *lst,
						const char *path);
t_permessions		check_existance(const char *command,
						const char *path, char **line);
void				free_exec(void *exec);
void				free_envs(t_key_value *kv);
t_pair_files		iofile(t_clist *files, int *error, char **file_error);
int					non_pipe_builtins(const t_exec *ex, t_cmap *envs);
int					just_create_files(t_clist *files);
int					ft_pipe_return(int status);
int					ft_exec_env(char **str, int is_pipe, int fd, t_cmap *envs);
int					ft_export(char **args, int is_pipe, int fd, t_cmap *envs);
void				init_builtins(t_cmap **map);
void				insert_builtins(t_cmap *map, const char *builtin_name,
						t_builtin_function builtin_funcn);
t_builtin_function	get_builtins(t_cmap *mp, const char *key);
void				free_builtins(void *data);
int					ft_unset(char **arguments, int is_pipe, int fd,
						t_cmap *envs);
int					ft_exec_exit(char **str, int is_pipe, int fd, t_cmap *envs);
char				**from_map_to_array_2d(t_cmap *map, const char *cmd);
int					is_variable_not_valid(const char *variable_name);
int					is_digits(char c);
int					is_upper(char c);
int					is_lower(char c);
void				signal_handler(int sig);
void				ft_init_builtins(void);
void				init_parent_signals(void);
BOOL				is_not_making_change(t_exec *exec);
void				all_commands(char *s, t_cmap *global_env);
void				file_not_found(const char *file, t_pair_files io);
void				ft_disable_unused(char ***str, int *is_pipe,
						int *fd, t_cmap **envs);
void				init_child_signal(void);
void				init_ft_pipe_vars(int vars[7], int is_first,
						const t_clist *pipe_exec, int old);
void				ft_child_helper(t_exec *data, t_cmap *envs);
int					is_command(const char *cmd);
t_clist				*sorted_keys(t_clist *keys);
int					ft_cstrcmp(const char *s1, const char *s2);

#endif
