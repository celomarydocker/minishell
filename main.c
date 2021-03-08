#include "minishell.h"
#include <stdio.h>

void     display(const t_exec *exec, char *path)
{
    t_file          *file;
    char            *type;
    int             error;
    t_permessions   perm;
    t_pair_files    io;

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

void     all_commands(char *s, char **envs)
{
    t_clist     *cmd_pipes;
    t_cmap      *global_env;
    char        **cmds;
    int         iter;
    
    global_env = put_vars(envs);
    get_builtins(g_builtins, "pwd")(ft_csplit(get(global_env, "PWD"), ' ', NULL), 1);
    cmds = csplit(s, ';');
    iter = 0;
   while (cmds[iter])
    {
       //print("%s\n", cmds[iter]);
       cmd_pipes = get_command_line(cmds[iter], global_env);
       cmd_pipes = from_parsing2exec(cmd_pipes, get(global_env, "PATH"));
       while (cmd_pipes)
       {
           display(cmd_pipes->data, get(global_env, "PATH"));
           cmd_pipes = cmd_pipes->next;
       }
       iter++;
    }
    free_split(&cmds);
    clear_map(&global_env, free_vars);
}

int     main(void)
{
	char 	*line;

	line = NULL;

    /*** TEST BUILTINS ***/
    init_builtins(&g_builtins);
    insert_builtins(g_builtins, "echo", ft_exec_echo);
    insert_builtins(g_builtins, "pwd", ft_exec_pwd);
  
    /*** END TEST ***/
	while (1)
	{
		print(">>> ");
		get_next_line(1, &line);
		all_commands(line, environ);
	}
    clear_map(&g_builtins, free_builtins);
    return (0);
}
