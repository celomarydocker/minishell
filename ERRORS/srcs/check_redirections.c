/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:46:44 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/15 09:50:44 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"

static int      check_before(const char *line, int pos)
{
    int     is_space; 

    if (pos > 1 && line[pos] == '\0')
        is_space = 1;
    else
        is_space = 0;
    
    while (--pos >= 0)
    {
        if (line[pos] != ' ' && line[pos] != '>' && line[pos] != '<')
            return (0);
        if (line[pos] == ' ')
            is_space = 1;
        else if ((line[pos] == '>' || line[pos] == '<') && is_space)
            return (1);
    }
    return (0);
}

int check_for_redirection(const char *s, unsigned int *iter, char red_char)
{
    int    count_red;

    count_red = 0;
    while (s[*iter] == '>' || s[*iter] == '<')
    {
        if (s[*iter] != red_char)
        {
            if (s[*iter] == '<')
                return (2);
            return (3);
        }
        count_red++;
        (*iter)++;
    }
    if (count_red > 1 && red_char == '<')
        return (2);
    if (count_red > 2 && red_char == '>')
        return (3);
    return (1);
}

int check_for_file(const char *s, unsigned int *i)
{
    while (s[*i])
    {
        if (s[*i] == '>' || s[*i] == '<')
            return (0);
        if (s[*i] == '|')
            return (5);
        if (s[*i] == ';')
            return (6);
        if (s[*i] != ' ')
            return (1);
        (*i)++;
    }
    return (0);
}

int check_redirection(const char *line)
{
    unsigned int        iterator;
    int                 redirect;
    int                 file;
    int                 back_slash;
    int                 is_quote;

    iterator = 0;
    is_quote = 0;
    back_slash = 0;
    file = 0;
    redirect = 0;

    while (line[iterator])
    {
        if (back_slash % 2 == 0)
        {
            if (line[iterator] == '\'' || line[iterator] == '"')
            {
                if (!is_quote)
                    is_quote = line[iterator];
                else if(line[iterator] == is_quote)
                    is_quote = 0;
            }
            if ((line[iterator] == '>' || line[iterator] == '<') && !is_quote)
            {
                redirect = check_for_redirection(line, &iterator, line[iterator]);
                file = check_for_file(line, &iterator);
                if (redirect != 1 || file != 1)
                {
                    if (redirect == 1 && file > 1)
                        return (file);
                    if (!line[iterator] && redirect==1)
                        return (4);
                    return (redirect);
                }
                if (!line[iterator])
                    break;
            }
        }
        if (line[iterator] != '\\')
            back_slash = 0;
        else
            back_slash++;
        iterator++;
    }
    return (0);
}