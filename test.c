#include <stdio.h>
#include <termio.h>
#include <unistd.h>
#include <termcap.h>
#include <stdlib.h>
#include <signal.h>



/**** line ****/




struct s_line   g_line;

/** **/

void    seg_handle(int segnal)
{
        clear_line(&g_line);
        write(1, "\n", 1);
}

/*** ***/



/*** FUNCTION STACK***/

/*** ***/



int             main(void)
{

        return (0);
}