//lseek demo
#include "apue.h"
#include "myerr.h"

int main(void)
{
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        {
	    printf("Can not seek\n");
	}
        else
        {
	    printf("seek Ok\n");
	}
	exit(0);
}
