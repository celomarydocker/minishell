/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:35:57 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/29 17:56:50 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECOGNIZER_H
# define RECOGNIZER_H

# include	"../../minishell.h"

typedef struct s_rec
{
	t_clist		*text;
	t_clist		*files;
	t_clist		*oper;
}				t_rec;
typedef struct s_ccommand
{
	char		*cmd;
	t_rec		*data;
	int			error;
}				t_ccommand;

t_rec			*init_rec(void);
int				in_set(char c, char *set);
char			*ft_cstrjoin(char *text, char *s);
char			*ft_cstrcpy(char *dst, const char *src, int len);
int				ft_cstrlen(const char *s);
char			*ft_csubstr(char *str, int len);
char			*ft_cstrdup(char *str);
void			display_data(void *data);
int				check_special(char c, char cs, char *special, int *is_back);
char			**csplit(const char *s, char separator);
void			free_split(char **sp);
char			*withback(char *str, int *iter);
char			*double_quotes(char *str, int *i);
void			print_rec(t_rec *rec);
void			free_keys(t_clist	**keys);
void			free_cmd_data(t_cmap **cmd_data);
void			free_rec(t_rec **rec);
int				var_len(char *str, int *iter, t_cmap *map);
char			*get(t_cmap *map, const char *key);
void			setv(t_cmap *map, const char *key, char *value);
void			enter(char *str, int *iter, t_clist **lst);
void			get_oper(char *str, int *iter, t_clist **operator);
t_cmap			*put_vars(char **vars);
t_rec			*join_rec(t_rec *rec1, t_rec *rec2);
char			*single_double_quotes(char *str, int *iter, char c);
char			*get_command(char *str, int *iter);
t_rec			*handle_command(char *str, int *iter, int is_found);
void			add_command(char *cmd, t_clist **lst, int err);
t_clist			*get_command_line(char *cmd, t_cmap *global_vars);
int				variables(char *dest, char *str, int *iter, t_cmap *map);
char			*single_quotes(char *str, int *iter);
void			free_ccommand(void *cmd);
int				len_name(char *str);
void			free_all_commands(t_clist **lst);
char			*ft_replace_envs(char *line, t_cmap *envs);
void			free_vars(void *vars);
char			**split_envirement_variable(const char *line);
#endif
