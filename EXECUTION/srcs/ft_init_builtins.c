/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:26:42 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/01 18:26:47 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void	ft_init_builtins(void)
{
	init_builtins(&g_global.g_builtins);
	insert_builtins(g_global.g_builtins, "echo", ft_exec_echo);
	insert_builtins(g_global.g_builtins, "pwd", ft_exec_pwd);
	insert_builtins(g_global.g_builtins, "cd", ft_exec_cd);
	insert_builtins(g_global.g_builtins, "unset", ft_unset);
	insert_builtins(g_global.g_builtins, "exit", ft_exec_exit);
	insert_builtins(g_global.g_builtins, "env", ft_exec_env);
	insert_builtins(g_global.g_builtins, "export", ft_export);
}
