/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_helper3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:15:15 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/18 15:44:21 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

t_rec		*init_rec(void)
{
	t_rec	*rec;

	rec = malloc(sizeof(t_rec));
	rec->files = NULL;
	rec->oper = NULL;
	rec->text = NULL;
	return (rec);
}
/*
void		display_data(void *data)
{
	print("%s ", (char *)data);
}

void		print_rec(t_rec *rec)
{
	print("\n**********************************************\n");
	print("oper------------------------------------------\n");
	iterate_list(rec->oper, display_data);
	print("\n");
	print("files-----------------------------------------\n");
	iterate_list(rec->files, display_data);
	print("\n");
	print("texts-----------------------------------------\n");
	iterate_list(rec->text, display_data);
	print("\n**********************************************\n");
}
*/