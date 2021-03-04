/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_coomands2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 07:12:10 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/04 14:41:07 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recognizer.h"

t_ccommand  *get_command_key_val(char *cmd, t_cmap *envs)
{
    t_ccommand  *key_val;

    key_val = malloc(sizeof(t_ccommand));
    key_val->keys = NULL;
    key_val->full_command = get_command_line(cmd, envs, &key_val->keys);
    return (key_val);
}

