/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:11:45 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/01 18:12:16 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

static void	print_error_unset(char *error)
{
	ft_putstr_fd("CSHELL: unset: `", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("' not a valid identifier\n", 2);
}

static int	nested_unset(char *s, t_cmap *envs)
{
	char			**inside;
	int				ret;
	unsigned int	nested_iterator;

	inside = csplit(s, ' ');
	nested_iterator = 0;
	ret = 0;
	while (inside[nested_iterator])
	{
		if (is_variable_not_valid(inside[nested_iterator]))
		{
			print_error_unset(inside[nested_iterator]);
			ret = 1;
		}
		else
		{
			s = pop_value(envs, inside[nested_iterator],
					ft_strlen(inside[nested_iterator]), free_envs);
			free(s);
		}
		nested_iterator++;
	}
	free_split(inside);
	return (ret);
}

int			ft_unset(char **arguments, int is_pipe, int fd, t_cmap *envs)
{
	unsigned int		iterator;
	int					ret;

	iterator = 0;
	ret = 0;
	while (arguments[iterator])
	{
		if (nested_unset(arguments[iterator], envs))
			ret = 1;
		iterator++;
	}
	ft_disable_unused(&arguments, &is_pipe, &fd, &envs);
	return (ret);
}
