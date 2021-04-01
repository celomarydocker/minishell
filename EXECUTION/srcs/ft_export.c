/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:24:56 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/01 18:26:13 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void		print_value(const char *value)
{
	int		iter;

	iter = 0;
	while (value[iter])
	{
		if (is_inset(value[iter], "\"\\$"))
			ft_putchar_fd('\\', 1);
		ft_putchar_fd(value[iter], 1);
		iter++;
	}
}

void		helper_function(t_clist *iter_key, t_cmap *envs, int fd)
{
	char		*value;

	if (ft_strncmp(iter_key->data, "?", 1)
		&& ft_strncmp(iter_key->data, "$", 1))
	{
		value = get(envs, iter_key->data);
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(iter_key->data, fd);
		if (value)
		{
			ft_putstr_fd("=\"", fd);
			print_value(value);
			ft_putstr_fd("\"\n", fd);
		}
		else
			ft_putstr_fd("\n", fd);
	}
}

void		print_variables(t_cmap *envs, int fd)
{
	t_clist		*keys;
	t_clist		*iter_key;

	keys = sorted_keys(get_keys(envs));
	iter_key = keys;
	while (iter_key)
	{
		helper_function(iter_key, envs, fd);
		iter_key = iter_key->next;
	}
	clear_list(&keys, NULL);
}

static int	check_varibales(char *s, t_cmap *envs)
{
	int		ret;
	int		v_ret;
	char	**splt;

	splt = split_envirement_variable(s);
	v_ret = is_variable_not_valid(splt[0]);
	ret = 0;
	if (v_ret)
	{
		if (v_ret == 1)
		{
			ft_putstr_fd("CSHELL: export: `", 2);
			ft_putstr_fd(s, 2);
			ft_putstr_fd("' not a valid identifier\n", 2);
			ret = 1;
		}
	}
	else
		setv(envs, splt[0], ft_cstrdup(splt[1]));
	free_split(splt);
	return (ret);
}

int			ft_export(char **args, int is_pipe, int fd, t_cmap *envs)
{
	int				ret;
	unsigned int	iterator;

	ret = 0;
	if (!*args)
	{
		print_variables(envs, fd);
		return (0);
	}
	iterator = 0;
	while (args[iterator])
	{
		if (check_varibales(args[iterator], envs))
			ret = 1;
		iterator++;
	}
	ft_disable_unused(&args, &is_pipe, &fd, &envs);
	return (ret);
}
