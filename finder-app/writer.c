#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <syslog.h>

int main(int argc, char **argv)
{
    int fd;
    ssize_t nr;
    if(argc != 3)
    {
       printf("incorrect number of argument passed\n");
       closelog();
       return 1;
    }
    openlog("writer", LOG_PERROR|LOG_PID, LOG_USER|LOG_DEBUG);
    fd = open(argv[1], O_WRONLY);
    if(fd == -1)
    {
        syslog(LOG_ERR, "file does not exist \n");
        closelog();
        printf("file does not exist \n");
        return 1;
    }

    nr = write(fd, argv[2], strlen(argv[2]));
    if(nr == -1)
    {
        syslog(LOG_ERR, "write operation failed \n");
        closelog();
        printf(" write operation failed \n");
        return 1;
    }
    else
    {
        syslog(LOG_INFO, "write operation passed \n");
        closelog();
        printf(" write operation passed \n");
        return 0;
    }

   
}