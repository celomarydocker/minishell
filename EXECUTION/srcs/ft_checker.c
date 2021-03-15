/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:38:21 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/15 12:39:01 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int is_lower(char c)
{
    if (c < 'a' || c > 'z')
        return (0);
    return (1);
}

int is_upper(char c)
{
    if (c < 'A' || c > 'Z')
        return (0);
    return (1);
}

int is_digits(char c)
{
    if (c < '0' || c > '9')
        return (0);
    return (1);
}

int is_variable_not_valid(const char *variable_name)
{
    unsigned int    iter;


    if (!is_lower(variable_name[0]) && !is_upper(variable_name[0]) &&
    variable_name[0] != '_')
        return (1);
    iter = 1;
    while (variable_name[iter])
    {
        if (!is_lower(variable_name[iter]) && !is_upper(variable_name[iter]) &&
        !is_digits(variable_name[iter]) && variable_name[iter] != '_')
            return (1);
        iter++;
    }
    return (0);
}