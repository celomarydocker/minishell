#include "minishell.h"

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
       cmd_pipes = get_command_line(cmds[iter], global_env);
       iter++;
    }
    free_split(&cmds);
    clear_map(&global_env, free_vars);
}

// int     main(void)
// {
//     return (0);
// }
