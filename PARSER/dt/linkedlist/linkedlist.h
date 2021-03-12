/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:36:38 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/12 11:23:05 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include <stdlib.h>

typedef struct		s_clist
{
	void			*data;
	struct s_clist	*next;
}					t_clist;

void				*free_node(t_clist **list);
void				append(t_clist **list, void *data);
void				*pop(t_clist **list);
void				iterate_list(const t_clist *list, void func(void *data));
void				clear_list(t_clist **list, void free_data(void *data));
size_t				length(const t_clist *lst);
t_clist				*joined_list(t_clist *lst1, t_clist *lst2);
#endif
