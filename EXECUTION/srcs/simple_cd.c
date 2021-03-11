#include "../include/execution.h"

// this cd function for relative path and absolute.
int    ft_exec_cd1(char **str, int fd, t_cmap *envs)
{
    // mohammed initial 'OLDPWD' b "cd: OLDPWD not set" and don't print it in envs untill 'OLDPWD' has another value.
    char    *to_der;
    char    *buffer;
    buffer = malloc(64);
    if (!*str)
    {
        to_der = get(envs, "HOME");
        print("old pwd %s\n", get(envs, "PWD"));
        // print("old pwd %s\n", get(envs, "PWD"));
        chdir(to_der);
        getcwd(buffer, 64);
        setv(envs, "PWD", buffer);
        print("new pwd %s\n", get(envs, "PWD"));
        // print("new pwd %s\n", get(envs, "PWD"));
    }
    else
    {
        if (!(chdir(*str)))
        {
            print("old pwd %s\n", get(envs, "PWD"));
            // print("old pwd %s\n", get(envs, "PWD"));
            getcwd(buffer, 64);
            setv(envs, "PWD", buffer);
            print("new pwd %s\n", get(envs, "PWD"));
            // print("new pwd %s\n", get(envs, "PWD"));
        }
        else
        {
            ft_putstr_fd("cd : no such file or directory ", fd);
            write(1, "\n", 1);
        }
    }

    return (0);
}