/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:27:54 by hfadyl            #+#    #+#             */
/*   Updated: 2021/04/03 15:17:07 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

/*
void     display(const t_exec *exec, t_cmap *envs)
{
    t_file          *file;
    char            *type;
    int             error;
    t_permessions   perm;
    t_pair_files    io;

    type = NULL;
    print("cmd %s\n", exec->cmd);
    if (exec->perm == FILE_EXEC || exec->perm == BUILTINS)
        print("COMMAND %s EXIST %s\n", exec->cmd, type);
    else
        print("COMMAND NOT FOUND\n");
   char **args = exec->arguments;
    print("ARGUMENTS\n");
    while (*args)
    {
        print("-- %s\n", *args);
        args++;
    }
    t_clist *lst = exec->files;
    print("FILES\n");
    while (lst)
    {
        file = (t_file *)lst->data;
        if (file->redirect == INPUT)
            type = "INPUT";
        else if (file->redirect == OUTPUT)
            type = "OUTPUT";
        else
            type = "APPEND";
       print("- %s %s\n", file->filename, type);
        lst = lst->next;
    }
}
*/

static t_clist	*put_data_into_struct(const char *command, const t_cmap *envs)
{
	t_clist	*exec_list;
	t_clist	*parser_pipe;

	parser_pipe = get_command_line((char *)command, (t_cmap *)envs);
	exec_list = from_parsing2exec(parser_pipe, getenv("PATH"));
	clear_list(&parser_pipe, free_ccommand);
	return (exec_list);
}

static int	exec_command(const t_clist *commands, t_cmap *envs)
{
	t_clist			*iter_lst;
	int				pipe_ret;

	iter_lst = (t_clist *)commands;
	if (iter_lst)
	{
		if ((iter_lst->next || is_not_making_change(iter_lst->data)))
		{
			pipe_ret = ft_pipe(iter_lst, 1, 0, envs);
			setv(envs, "?", ft_itoa(pipe_ret));
		}
		else
		{
			pipe_ret = non_pipe_builtins(iter_lst->data, envs);
			setv(envs, "?", ft_itoa(pipe_ret));
			if (pipe_ret > 10000)
			{
				setv(envs, "?", ft_itoa(pipe_ret - 10000));
				return (1);
			}
			else
				setv(envs, "?", ft_itoa(pipe_ret));
		}
	}
	return (0);
}

void	all_commands(char *s, t_cmap *global_env)
{
	t_clist		*exec_pipe;
	char		**cmds;
	int			iter;
	int			exit_cmd;

	cmds = csplit(s, ';');
	iter = 0;
	while (cmds[iter])
	{
		exec_pipe = put_data_into_struct(cmds[iter], global_env);
		exit_cmd = exec_command(exec_pipe, global_env);
		clear_list(&exec_pipe, free_exec);
		if (exit_cmd)
			break ;
		iter++;
	}
	free_split(cmds);
}
