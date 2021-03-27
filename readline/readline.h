/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:12:10 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/27 23:05:24 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE
# define READLINE
#include   "../minishell.h"
# define KEY_UP 183
# define KEY_DOWN 184
# define KEY_LEFT  186
# define KEY_RIGHT 185
# define ENTER 10
# define KEY_REMOVE 127
# define KEY_TAB 9
# define CTRL_D 4
# define CTRL_L 12

void                from_second_to_first(t_stack **first, t_stack **second);
size_t              length_st(const t_stack *st);
void                ctrl_d(t_stack *left, t_stack *right);
void                transfer_one_char(t_stack **first, t_stack **second);
void                delete_one_char(t_stack **st);
void                insert_char(t_stack **stack, int c);
struct s_line       *init_line(void);
void                clear_line(struct s_line *line);
int                 get_char();
void                key_up();
void                key_down();
void                key_left();
void                key_right();
void                enter_key(char **line);
void                key_remove_char();
int                 ft_puts(int d);
void                ft_putchar(void *dt);
void                set_char(int c);
void                init_history();
void                clear_history();
void                froma2b(t_stack **a, t_stack **b);
void                reset_line(struct s_line *line);
void                display_history_line();
void                tcapply(const char *id);
void                ctrl_l(void);
char                *readline(t_cmap *envs);
#endif