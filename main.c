#include "minishell.h"
#include <stdio.h>

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



void    prompt(void)
{
    char buffer[100];

    print("\033[0;32m$%s> \033[0;37m",getcwd(buffer, 100));
}

void    init_bash(char **line, t_cmap **envs)
{
    *line = NULL;
    *envs = put_vars(environ);
    setv(*envs, "?", ft_itoa(0));
    setv(*envs, "$", ft_itoa(getpid()));
    init_parent_signals();
    g_global.sigint_ret = 0;
    ft_init_builtins();
    g_global.g_pid = 0;
    g_global.pid = getpid();
    prompt();
}

void    clear_all(t_cmap **envs)
{
    clear_map(&g_global.g_builtins, free_builtins);
    clear_map(envs, free_vars);
}
void    reset_vars(char **line)
{
    free(*line);
    *line = NULL;
    g_global.g_pid = 0;
    prompt();
}
int     main()
{
	char 	*line;
    int     error;
    t_cmap *envs;

    init_bash(&line, &envs);
    while (1)
	{
        if (readline(&line))
            end_of_line();
        if (g_global.sigint_ret)
            setv(envs, "?", ft_itoa(g_global.sigint_ret));
        g_global.sigint_ret = 0;
        if(line)
        {
            error = error_parsing(line);
            if (!error)
		        all_commands(line, envs);
            else
                setv(envs, "?", ft_itoa(error));
        }
        reset_vars(&line);
	}
    clear_all(&envs);
    return (0);
}
