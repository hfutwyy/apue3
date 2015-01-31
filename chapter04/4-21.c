#include "apue.h"
#include "myerr.h"
#include "fcntl.h"

//futimens及utimensat修改文件修改时间及访问时间
int main(int argc, char *argv[])
{
    int i,fd;
    struct stat statbuf;
    struct timespec times[2];

    for (i = 1; i < argc; i++) {
        if (stat(argv[i], &statbuf) < 0) {  //fetch current time
            err_ret("%s: stat error", argv[i]);
            continue;
        }
        if ((fd = open(argv[1], O_RDWR | O_TRUNC)) < 0) { //truncate file
            err_ret("%s: open error", argv[i]);
            continue;
        }
        times[0] = statbuf.st_atim;  //fetch original access time
        times[1] = statbuf.st_mtim;  //fetch original motify time
        if (futimens(fd, times) < 0) { //reset time
            err_ret("%s: futimens error", argv[i]);
        }
        close(fd);
    }
    exit(0);
}
