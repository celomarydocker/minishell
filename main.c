#include "minishell.h"
#include <stdio.h>

void     display(const t_exec *exec)
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
    io = iofile(lst, &error);
    print("%d %d\n", io.input, io.output);
    if (io.input != -1)
        close(io.input);
    if (io.output != -1)
        close(io.output);
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
t_clist     *put_data_into_struct(const char *command, const t_cmap *envs)
{
    t_clist     *exec_list;
    t_clist     *parser_pipe;

    parser_pipe = get_command_line(command, envs);
    exec_list = from_parsing2exec(parser_pipe, get(envs, "PATH"));
    clear_list(&parser_pipe, free_ccommand);
    return (exec_list);
}

void     exec_command(const t_clist *commands)
{
    t_clist       *iter_lst;

    while (iter_lst)
    {
        display(iter_lst->data);
        iter_lst = iter_lst->next;
    }
}
void     all_commands(char *s, t_cmap *global_env)
{
    t_clist     *exec_pipe;
    char        **cmds;
    int         iter;
    
    //get_builtins(g_builtins, "pwd")(ft_csplit(get(global_env, "PWD"), ' ', NULL), 1);
    cmds = csplit(s, ';');
    iter = 0;
    while (cmds[iter])
    {
       //print("%s\n", cmds[iter]);
       exec_pipe = put_data_into_struct(cmds[iter], global_env);
       exec_command(exec_pipe);
       clear_list(&exec_pipe, free_exec);
       iter++;
    }
    free_split(cmds);
}

int     main(void)
{
	char 	*line;
    t_cmap *envs;

	line = NULL;
    envs = put_vars(environ);
    /*** TEST BUILTINS ***/
    init_builtins(&g_builtins);
    insert_builtins(g_builtins, "echo", ft_exec_echo);
    insert_builtins(g_builtins, "pwd", ft_exec_pwd);
    /*** END TEST ***/
	while (1)
	{
		print(">>> ");
		get_next_line(1, &line);
		all_commands(line, envs);
        free(line);
        line = NULL;
	}
    clear_map(&g_builtins, free_builtins);
    clear_map(&envs, free_vars);
    return (0);
}
