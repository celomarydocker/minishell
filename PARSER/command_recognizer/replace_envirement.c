/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_envirement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:18:25 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/20 23:57:57 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

static void     init_v(int *a, int *b, size_t *c, int *d)
{
    *a = 0;
    *b = 0;
    *c = 0;
    *d = 0;
}

static void     init_v2(int *a, int *b, int *c, int *d)
{
    *a = 0;
    *b = 0;
    *c = 0;
    *d = 0;
}

static size_t  count_length(char *line, t_cmap *envs)
{
    int         iterator;
    size_t      length;
    int         quote;
    int         back;

    init_v(&iterator, &quote, &length, &back);
    while (line[iterator])
    {
        if (line[iterator] == '$' && back % 2 == 0 && !quote)
            length += (size_t)var_len(line + iterator, &iterator, envs);
        else
        {
            if (line[iterator] == '\'' && back % 2 == 0)
                quote = 1;
            check_back(&back, line, (unsigned int)iterator);
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
    init_v2(&back, &iterator, &quote, &len);
    while (line[iterator])
    {
        if (line[iterator] == '$' && back % 2 == 0 && !quote)
            len += variables(cmd + len, line + iterator, &iterator, envs);
        else
        {
            if (line[iterator] == '\'' && back % 2 == 0)
                quote = 1;
            check_back(&back, line, (unsigned int)iterator);
            cmd[len] = line[iterator];
            len++;
            iterator++;
        }
    }
    cmd[len] = 0;
    return (cmd); 
}