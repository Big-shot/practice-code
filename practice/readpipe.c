
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    //int outfd = open("tmp_out.txt",O_WRONLY | O_CREAT,0644);
    //if(outfd==-1)
    //    perror("open tmp_out.txt"),exit(1);
    int infd = open("my.p",O_RDONLY);
    if(infd==-1)
        perror("open my.p"),exit(1);
    char buf[1024]={};
    int n = 0;
    while((n = read(infd,buf,1024))>0)
    {
        write(1,buf,n);
        memset(buf,0x00,1024);
    }
    close(infd);
    //close(outfd);
    unlink("my.p");
    return 0;
}

