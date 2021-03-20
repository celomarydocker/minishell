/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 07:08:12 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/20 23:21:58 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

void        enter(char  *str, int *iter, t_clist **lst)
{
    char       *s;

    s = NULL;
    while (str[*iter] && !in_set(str[*iter]," ><"))
    {
        if (str[*iter] == '\'' || str[*iter] == '"')
            s = ft_cstrjoin(s, single_double_quotes(str, iter, str[*iter]));
        else
            s = ft_cstrjoin(s, withback(str, iter));
    }
    append(lst, s);
}

void        get_oper(char *str, int *iter, t_clist **operator)
{
    char        *oper;
    int         len;

    len = 0;
    while (str[*iter + len] == '<' || str[*iter + len] == '>')
        len++;
    oper = malloc(sizeof(char) * (len + 1));
    len = 0;
    while (str[*iter] == '<' || str[*iter] == '>')
    {
        oper[len] = str[*iter];
        len++;
        (*iter)++;
    }
    oper[len] = 0;
    append(operator, oper);
}
