#include "apue.h"
#include "myerr.h"
#include "limits.h"

#ifdef   PATH_MAX
static int   pathmax = PATH_MAX;
#else
static int   pathmax = 0;
#endif
#define SUSV3 200112L
static long posix_version = 0;
/* If PATH_MAX is indeterminate, no guarantee this is adequate */
#define PATH_MAX_GUESS   1024
char* path_alloc(size_t* size);

int main(int argc, char *argv[])
{
    char *ptr;
    size_t size;
    if (chdir("/home/weiyanyan/") < 0)
        err_sys("chdir failed");
    ptr = path_alloc(&size);
    if (getcwd(ptr, size) == NULL)
        err_sys("getcwd failed");
    printf("cwd = %s\n", ptr);

    exit(0);
}


char* path_alloc(size_t* size)
{
    char *p = NULL;
    if(!size) return NULL;
    p = malloc(256);
    if(p)
        *size = 256;
    else
        *size = 0;
    return p;
}
