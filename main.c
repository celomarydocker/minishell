#include "minishell.h"

void    all_commands(char *s, char **envs)
{
    t_clist     *all;
    t_cmap      *global_env;
    t_ccommand  *cmd;
    char        **cmds;
    int         iter;

    global_env = put_vars(envs);
    all = NULL;
    cmds = csplit(s, ';');
    iter = 0;
    while (cmds[iter])
    {
       cmd = get_command_key_val(cmds[iter], global_env);
       
       free_ccommand(cmd);
       iter++;
    }
    free_split(&cmds);
    clear_map(&global_env, free_vars);
}

// int         main(void)
// {
    
//     return (0);
// }