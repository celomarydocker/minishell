/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:48:20 by mel-omar@st       #+#    #+#             */
/*   Updated: 2021/03/31 19:13:32 by mel-omar@st      ###   ########.fr       */
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
