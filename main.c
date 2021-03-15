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
  io = iofile(lst, &error, &type);
  print("error %d\n", error);
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

    parser_pipe = get_command_line((char *)command, (t_cmap *)envs);
    exec_list = from_parsing2exec(parser_pipe, get((t_cmap *)envs, "PATH"));
    clear_list(&parser_pipe, free_ccommand);
    return (exec_list);
}

int      is_equal(const char *s1, const char *s2)
{
    unsigned int iterator;

    iterator = 0;
    while (s1[iterator] && s1[iterator] == s2[iterator])
        iterator++;
    if (s1[iterator] != s2[iterator])
        return (0);
    return (1);
}

bool     is_not_making_change(t_exec *exec)
{
    if (exec->perm != BUILTINS)
        return (1);
    return (!(is_equal(exec->cmd, "cd") ||
    is_equal(exec->cmd, "export") ||
    is_equal(exec->cmd, "unset") || is_equal(exec->cmd, "exit")));
}

void     exec_command(const t_clist *commands, t_cmap *envs)
{
    t_clist       *iter_lst;
    int            pipe_ret;
    int            stdfd[2];

    iter_lst = (t_clist *)commands;
    if (iter_lst->next || is_not_making_change(iter_lst->data))
    {
        pipe_ret = ft_pipe(iter_lst, 1, 0, envs);
        setv(envs, "?", ft_itoa(pipe_ret));
    }
    else
    {
        t_exec *ex = iter_lst->data;
        get_builtins(g_global.g_builtins, ex->cmd)(ex->arguments + 1, 0 ,1, envs);
        //setv(envs, "_", ft_cstrdup(ex->cmd));
    }
   //display(iter_lst->data, envs);
    /*while (iter_lst)
    {
       
        iter_lst = iter_lst->next;
    }*/
}

void     all_commands(char *s, t_cmap *global_env)
{
    t_clist     *exec_pipe;
    char        **cmds;
    int         iter;

    cmds = csplit(s, ';');
    iter = 0;
    while (cmds[iter])
    {
       exec_pipe = put_data_into_struct(cmds[iter], global_env);
       exec_command(exec_pipe, global_env);
       clear_list(&exec_pipe, free_exec);
       iter++;
    }
    free_split(cmds);
}

void    ft_print_char(int times, char c)
{
    int    iter;

    iter = 0;
    while (iter++ < times)
        write(2, &c, 1);
}

int    print_error(int error, char c)
{
    
    if (error)
    {
        ft_putstr_fd("CSHELL: syntax error near unexpected token `", 2);
        ft_print_char(error, c);
        ft_putstr_fd("'\n", 2);
    }
    return (error);
}

int    print_error_quote(int error)
{
    if (error)
        ft_putstr_fd("CSHELL: syntax error quotes not closed\n", 2);
    return (error);
}

int    print_error_backslash(int error)
{
    if (error)
        ft_putstr_fd("CSHELL: unxpected backslash at the end\n", 2);
    return (error);
}

int     print_error_redirection(int error)
{
    if (error)
    {
        if (error == 4)
            ft_putstr_fd("CSHELL: syntax error near unexepected token `newline'\n", 2);
        else if (error == 3)
            ft_putstr_fd("CSHELL: syntax error near unexepected token `>'\n", 2);
        else if (error == 2)
            ft_putstr_fd("CSHELL: syntax error near unexepected token `<'\n", 2);
        else if (error == 5)
            ft_putstr_fd("bash: syntax error near unexpected token `|'\n", 2);
        else if (error == 6)
            ft_putstr_fd("bash: syntax error near unexpected token `;'\n", 2);
    }
    return (error);
}

int     error_parsing(const char *line)
{
    int error;

    if ((error = print_error(semi_colon_dup(line), ';')))
        return (258);
    if ((error = print_error(pipe_dup(line), '|')))
        return (258);
    if ((error= print_error_quote(check_quotes(line))))
        return (1);
    if ((error= print_error_backslash(check_backslash(line))))
        return (1);
    if ((error= print_error_redirection(check_redirection(line))))
        return (2);
    return (0);
}

void signal_handler(int sig)
{

    char buffer[100];
    int  id;
    if (sig == SIGINT)
    {
        if (g_global.g_pid != 1)
        {
             write(1, "\r\n", 2);
            print("%s> ", getcwd(buffer, 100));
        }
    }
    else if (sig == SIGQUIT)
        print("\b\b  \b\b");
}

void    prompt(void)
{
    char buffer[100];

    print("\r%s> ",getcwd(buffer, 100));
}

char     *get_line(int check_before)
{
    char *line;
    int ret;
    char    *args[] = {"exit", "1"};

    ret = get_next_line(0, &line);
    if (ret == 0)
    {
        if (!*line && !check_before)
            get_builtins(g_global.g_builtins, "exit")(args, 0, 1, NULL);
        else
            line = ft_cstrjoin(line, get_line(1));
    }
    return (line);
}

int     main()
{
	char 	*line;
    int     error;
    t_cmap *envs;

	line = NULL;
    envs = put_vars(environ);
    setv(envs, "?", ft_itoa(0));
    setv(envs, "$", ft_itoa(getpid()));
    signal(SIGINT, signal_handler);
    signal(SIGQUIT, signal_handler);

    //tgetent(NULL, get(envs, "TERM"));
    /*** TEST BUILTINS ***/
    init_builtins(&g_global.g_builtins);
    insert_builtins(g_global.g_builtins, "echo", ft_exec_echo);
    insert_builtins(g_global.g_builtins, "pwd", ft_exec_pwd);
    insert_builtins(g_global.g_builtins, "cd", ft_exec_cd);
    insert_builtins(g_global.g_builtins, "unset", ft_unset);
    insert_builtins(g_global.g_builtins, "exit", ft_exec_exit);
    insert_builtins(g_global.g_builtins, "env", ft_exec_env);
    insert_builtins(g_global.g_builtins, "export", ft_export);
    //ft_unset(envs, "HOME");
    //print("getpwd %s\n", get(envs, "PWD"));
    //insert_builtins(g_global.g_builtins, "unset", ft_exec_cd);
    /*** END TEST ***/
    g_global.g_pid = 0;
    g_global.pid = getpid();
    //print("%d\n", getpid());
    prompt();
    while (1)
	{
        line = get_line(0);
        if (!(error=error_parsing(line)))
		    all_commands(line, envs);
        else
            setv(envs, "?", ft_itoa(error));
        free(line);
        line = NULL;
        g_global.g_pid = 0;
        prompt();
	}
    clear_map(&g_global.g_builtins, free_builtins);
    clear_map(&envs, free_vars);
    return (0);
}
