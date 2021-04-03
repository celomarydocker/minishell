/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:12:10 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/03 18:49:00 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include "../minishell.h"
# define KEY_UP 183
# define KEY_DOWN 184
# define KEY_LEFT  186
# define KEY_RIGHT 185
# define ENTER 10
# define KEY_REMOVE 127
# define KEY_TAB 9
# define CTRL_D 4
# define CTRL_L 12

void				from_second_to_first(t_stack **first, t_stack **second);
size_t				length_st(const t_stack *st);
void				ctrl_d(t_stack *left, t_stack *right);
void				transfer_one_char(t_stack **first, t_stack **second);
void				delete_one_char(t_stack **st);
void				insert_char(t_stack **stack, int c);
struct s_line		*init_line(void);
void				clear_line(struct s_line *line);
int					get_char(void);
void				key_up(void);
void				key_down(void);
void				key_left(void);
void				key_right(void);
void				enter_key(char **line);
void				key_remove_char(void);
int					ft_puts(int d);
void				ft_putchar(void *dt);
void				set_char(int c);
void				init_history(void);
void				clear_history(void);
void				froma2b(t_stack **a, t_stack **b);
void				reset_history(t_stack **up, t_stack **down);
void				reset_line(struct s_line *line);
void				display_history_line(void);
void				tcapply(const char *id);
void				clear_st_line(void *data);
void				copyhistory(void);
void				cleartemp(void);
void				reverse_stack(t_stack **st);
void				ctrl_l(void);
char				*readline(t_cmap *envs);
#endif