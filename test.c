#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <string.h>
#include <signal.h>
#include <curses.h>
#include <term.h>
#include <stdlib.h>

void    get_line(char *buffer)
{
    int c;
    int i;
    c = getchar();
    i = 0;
    while (c != '\n')
    {
        buffer[i] = c;
        i++;
        c = getchar();
    }
    buffer[i] = 0;
}

int     main(void)
{
    char buffer[100];

    int a = tgetent(buffer, getenv("TERM"));
    get_line(buffer);
    printf("%s\n", buffer);
    return (0);
}