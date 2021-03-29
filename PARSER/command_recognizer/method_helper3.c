/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_helper3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:15:15 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/29 17:44:42 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

t_rec	*init_rec(void)
{
	t_rec	*rec;

	rec = malloc(sizeof(t_rec));
	rec->files = NULL;
	rec->oper = NULL;
	rec->text = NULL;
	return (rec);
}
