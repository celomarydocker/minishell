/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 04:16:34 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/08 18:03:46 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

char        *single_quotes(char *str, int *iter)
{
    int     len;
    char    *s;

    len = 0;
    while (str[len + *iter] && str[len + *iter] != '\'')
        len++;
    if (str[len + *iter] != '\'')
    {
        print("Error!\n");
        return (NULL);
    }
    s = malloc(sizeof(char) * (len + 1));
    len = 0;
    while (str[*iter] != '\0' && str[*iter] != '\'')
    {
        s[len] = str[*iter];
        len++;
        (*iter)++;
    }
    s[len] = 0;
    return (s);
}