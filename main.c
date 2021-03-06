#include "minishell.h"

void     display(const t_exec *exec, char *path)
{
    t_file          *file;
    char            *type;
    t_permessions   perm;

    print("cmd %s\n", exec->cmd);
    perm = check_existance(exec->cmd, path, &type);
    if (perm == FILE_EXEC || perm == BUILTINS)
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

void     all_commands(char *s, char **envs)
{
    t_clist     *cmd_pipes;
    t_cmap      *global_env;
    char        **cmds;
    int         iter;
    
    global_env = put_vars(envs);
    cmds = csplit(s, ';');
    iter = 0;
    while (cmds[iter])
    {
       //print("%s\n", cmds[iter]);
       cmd_pipes = get_command_line(cmds[iter], global_env);
       cmd_pipes = from_parsing2exec(cmd_pipes);
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
	while (1)
	{
		print(">>> ");
		get_next_line(1, &line);
		all_commands(line, environ);
	}
    return (0);
}
