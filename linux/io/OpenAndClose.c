#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/fcntl.h>
#include<sys/stat.h>

#define DEF_MODE S_IWUSR|S_IRUSR|S_IWGRP|S_IRGRP|S_IROTH

int main()
{

    int fd1 = open("open.txt",O_RDWR,DEF_MODE);
    if(fd1<0)
        perror("open");
    write(fd1,"change world",20);
    printf("\nfd1=%d\n",fd1);
    close(fd1);
    int fd2 = open("open.txt",O_RDWR,DEF_MODE);
        printf("fd2=%d\n",fd2);
    close(fd2);
    return 0;
}
