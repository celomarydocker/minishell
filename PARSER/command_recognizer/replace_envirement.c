/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_envirement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:18:25 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/19 18:11:39 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

static size_t  count_length(char *line, t_cmap *envs)
{
    int         iterator;
    size_t      length;
    int         quote;
    int         back;

    length = 0;
    iterator = 0;
    back  = 0;
    quote = 0;
    while (line[iterator])
    {
        if (line[iterator] == '$' && back % 2 == 0 && !quote)
            length += (size_t)var_len(line + iterator, &iterator, envs);
        else
        {
            if (line[iterator] == '\'' && back % 2 == 0)
                quote = 1;
            if (line[iterator] == '\\')
                back++;
            else
                back = 0;
            length++;
            iterator++;
        }
    }
    return (length);
}

char    *ft_replace_envs(char *line, t_cmap *envs)
{
    char        *cmd;
    int         iterator;
    int         quote;
    int         back;
    int         len;

    cmd = malloc(sizeof(char) * (count_length(line, envs) + 1));
    back = 0;
    iterator = 0;
    quote = 0;
    len = 0;
    while (line[iterator])
    {
        if (line[iterator] == '$' && back % 2 == 0 && !quote)
            len += variables(cmd + len, line + iterator, &iterator, envs);
        else
        {
            if (line[iterator] == '\'' && back % 2 == 0)
                quote = 1;
            if (line[iterator] == '\\')
                back++;
            else
                back = 0;
            cmd[len] = line[iterator];
            len++;
            iterator++;
        }
    }
    cmd[len] = 0;
    return (cmd); 
}