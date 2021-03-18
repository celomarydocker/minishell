/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_coomands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 07:10:13 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/18 16:36:40 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

char        *single_double_quotes(char *str, int *iter, char c, t_cmap *map)
{
    char    *ret;

    (*iter)++;
    if (c == '"')
        ret = (double_quotes(str, iter, map));
    else
        ret = (single_quotes(str, iter));
    (*iter)++;
    return (ret);
}

int         check_for_variables(const char *str, unsigned int iterator)
{
    int     single_quotes;
    int     backslash;

    single_quotes = 0;
    backslash = 0;

    while (str[iterator])
    {
        if (str[iterator] == '$' && backslash % 2 == 0 && !single_quotes)
            return (1);
        if ((str[iterator] == '\'' || str[iterator] == '"') && backslash % 2 == 0)
        {
            if (single_quotes)
                single_quotes = 0;
            else
                single_quotes = 1;
        }
        if (str[iterator] == '\\')
            backslash++;
        else
            backslash = 0;
        iterator++;
    }
    return (0);
}

char        *get_command(char *str, int *iter, t_cmap *map, t_clist **text_lst)
{
    char                *s;
    unsigned int        iterator;
    char                **export_case;
    s = NULL;
    iterator = *iter;
    while (str[*iter] == ' ')
        (*iter)++;
    while (str[*iter] && !in_set(str[*iter]," ><"))
    {
        if (str[*iter] == '\'' || str[*iter] == '"')
            s = ft_cstrjoin(s, single_double_quotes(str, iter, str[*iter], map));
        else
            s = ft_cstrjoin(s, withback(str, map, iter));
    }
    if (check_for_variables(str, iterator))
    {
        export_case = csplit(s, ' ');
        free(s);
        s = export_case[0];
        iterator = 1;
        while (export_case[iterator])
        {
            append(text_lst, export_case[iterator]);
            iterator++;
        }
        free(export_case);
    }
    return (s);
}

void    copy(t_clist **a, t_clist *b)
{
    while (b)
    {
        append(a, ft_cstrdup((char *)b->data));
        b = b->next;
    }
}

t_rec       *join_rec(t_rec *rec1, t_rec *rec2)
{
    t_rec   *rec;

    rec = init_rec();
    if (rec1)
    {
        copy(&rec->files, rec1->files);
        copy(&rec->text, rec1->text);
        copy(&rec->oper, rec1->oper);
    }
    if (rec2)
    {
        copy(&rec->files, rec2->files);
        copy(&rec->text, rec2->text);
        copy(&rec->oper, rec2->oper);
    }
    free_rec(&rec1);
    free_rec(&rec2);
    return  (rec);
}

t_rec       *handle_command(char *str, t_cmap *map, int *iter, int is_found)
{
    int         is_file;
    t_rec       *rec;
    char        *s;

    is_file = 0;
    rec = init_rec();
    s = NULL;
    while (str[*iter])
    {
       if (str[*iter] == '>' || str[*iter] == '<')
       {
           get_oper(str, iter, &rec->oper);
           is_file = 1;
       }
       else if (str[*iter] == ' ')
            while (str[++(*iter)] == ' ');
        else if (is_file)
        {
            enter(str, iter, map,&rec->files);
            is_file = 0;
        }
        else if (!is_found)
            break;
        else
            enter(str, iter, map, &rec->text);
    }
    return (rec);
}

t_clist       *join_command(t_clist **first, t_clist **second)
{
    t_clist *lst;

    lst = joined_list(*first, *second);
    clear_list(first, NULL);
    clear_list(second, NULL);
    return (lst);
}

void       add_command(char *cmd, t_clist **lst, t_cmap *global_vars)
{
    int             i;
    int             is_found;
    t_ccommand      *command;
    t_clist         *text_front;

    is_found = 0;
    i = 0;
    command = malloc(sizeof(t_ccommand));
    command->cmd = NULL;
    command->data = NULL;
    text_front = NULL;
    while (cmd[i] == ' ')
        i++;
    while (!is_found)
    {
        if (!in_set(cmd[i], "><"))
        {
            command->cmd =  get_command(cmd, &i, global_vars, &text_front);
            is_found = 1;
        }
        command->data = join_rec(command->data,
        handle_command(cmd, global_vars, &i, is_found));
    }
    command->data->text = join_command(&text_front, &command->data->text);
    append(lst, command);
}

t_clist      *get_command_line(char *cmd, t_cmap *global_vars)
{
    t_clist         *all_cmds;
    char            **commands;
    int             iter;

    all_cmds = NULL;
    commands = csplit(cmd,'|');
    iter = 0;
    while (commands[iter])
    {
        add_command(commands[iter], &all_cmds, global_vars);
        iter++;
    }
    free_split(commands);
    return (all_cmds);
}