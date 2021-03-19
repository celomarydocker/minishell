/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_file_case_export.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:38:56 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/19 18:43:02 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"

int         check_for_space(const char *line, int *iterator, t_cmap *envs)
{
    int len;
    char *name;
    char *value;
    len = len_name((char *)(line + *iterator + 1));
    name = ft_csubstr((char *)(line + *iterator + 1), len);
    *iterator += len + 1;
    len = 0;
    value = get(envs, name);
    free(name);
    if (!value)
        return (0);
    while (value[len])
    {
        if (value[len] == ' ')
            return (1);
        len++;
    }
    return (0);
}

int         export_am(const char *line, t_cmap *envs)
{
    int     red;
    int     quote;
    int     back;
    int     iterator;

    red = 0;
    quote = 0;
    back = 0;
    iterator = 0;
    while (line[iterator])
    {
        if (line[iterator] == '$' && red && back % 2 == 0 && !quote)
        {
            if(check_for_space(line, &iterator, envs))
                return (1);
            red = 0;
        }
        else
        {
            if ((line[iterator] == '>' || line[iterator] == '<') && back % 2 == 0 && !quote)
                red = 1;
            if ((line[iterator] == '\'' || line[iterator] == '"') && back % 2 == 0)
            {
                if (!quote)
                    quote = line[iterator];
                else if (quote == line[iterator])
                    quote = 0;
            }
            if (line[iterator] == '\\')
                back++;
            else
                back = 0;
            iterator++;
        }
    }
    return (0);
}