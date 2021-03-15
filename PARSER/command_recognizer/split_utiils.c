/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utiils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 23:13:40 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/15 00:23:24 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

int       check_special(char c, char cs, char *special, int *is_back)
{
    int     stoped;

    stoped = (*is_back && c == cs);
    if (!*special && (c == '\'' || c == '"') && !*is_back)
        *special = c;
    else if ((c == '\'' || c == '"') && *special == c && !*is_back)
        *special = 0;
    if (*is_back)
        *is_back = 0;
    else if (c == '\\')
        *is_back = 1;
    return (c == cs && !*is_back && !*special &&
    !stoped);
}

void        free_split(char **sp)
{
    int     iter;

    iter = 0;
    while (sp[iter])
    {
        free(sp[iter]);
        //sp[iter] = NULL;
        iter++;
    }
    free(sp);
}