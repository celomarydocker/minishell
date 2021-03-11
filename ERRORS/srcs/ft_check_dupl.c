/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dupl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:58:13 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/11 22:16:11 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
-- 1 one pipe
-- 2 pipe on the middle
*/
int     pipe_dup(const char *line)
{
    int                 lock;
    unsigned int        iterator;
    int                 backslash;
    int                 pipe_count;
    int                 other_char;

    lock = 0;
    iterator = 0;
    backslash = 0;
    other_char = 0;
    pipe_count = 0;
    while (line[iterator])
    {
        if (pipe_count > 1)
            return (2);
        if (!other_char && pipe_count == 1 && line[iterator] != '|')
            return (1);
        if (backslash % 2 == 0 && (line[iterator] == '"' || line[iterator] == '\''))
        {
            if (lock == line[iterator])
                lock = 0;
            else if(!lock)
                lock = line[iterator];
            other_char = 1;
        }
        if (line[iterator] == '|' && !lock && backslash % 2 == 0)
            pipe_count++;
        else
        {
            other_char = 1;
            pipe_count = 0;
        }
        if (line[iterator] == '\\')
            backslash++;
        else
            backslash = 0;
        iterator++;
    }
    return (pipe_count);
}

int    semi_colon_dup(const char *line)
{
    int                 lock;
    unsigned int        iterator;
    int                 backslash;
    int                 pipe_count;
    int                 other_char;

    lock = 0;
    iterator = 0;
    backslash = 0;
    other_char = 0;
    pipe_count = 0;
    while (line[iterator])
    {
        if (backslash % 2 == 0 && (line[iterator] == '"' || line[iterator] == '\''))
        {
            if (lock == line[iterator])
                lock = 0;
            else if(!lock)
                lock = line[iterator];
            other_char = 1;
        }
        if (line[iterator] == ';' && !lock && backslash % 2 == 0)
            pipe_count++;
        else
        {
            other_char = 1;
            pipe_count = 0;
        }
        if (pipe_count > 1)
            return (2);
        if (!other_char && pipe_count == 1 && line[iterator] != ';')
            return (1);
        if (line[iterator] == '\\')
            backslash++;
        else
            backslash = 0;
        iterator++;
    }
    if (!other_char && pipe_count == 1 && line[iterator] != ';')
        return (1);
    return (0);
}