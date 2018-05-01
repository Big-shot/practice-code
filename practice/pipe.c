#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

////匿名管道
//int main()
//{
//    int fds[2];
//    int len;
//    char buf[100]={};
//    if(pipe(fds)==-1)
//        perror("pipe"),exit(1);
//    while(fgets(buf,100,stdin))
//    {
//        len = strlen(buf);
//        if(write(fds[1],buf,len)==-1)
//            perror("write"),exit(1);
//        memset(buf,0x00,sizeof(char)*100);
//        if(read(fds[0],buf,len)==-1)
//            perror("read"),exit(1);
//        if(write(1,buf,len)==-1)
//            perror("write"),exit(1);
//    }
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
//int main( void )
//{
//    int fds[2];
//    char buf[100];
//    int len;
//    if ( pipe(fds) == -1 )
//        perror("make pipe"),exit(1);
//    //read from stdin
//    while ( fgets(buf, 100, stdin) ) {
//        len = strlen(buf);
//        // write into pipe
//        if ( write(fds[1], buf, len) != len ) {
//            perror("write to pipe");
//            break;
//        }
//        memset(buf, 0x00, sizeof(buf));
//        // read from pipe
//        if ( (len=read(fds[0], buf, 100)) == -1 ) {
//            perror("read from pipe");
//            break;
//        }
//        // write to stdout
//        if ( write(1, buf, len) != len ) {
//            perror("write to stdout");
//            break;
//        }
//    }
//}

//父子进程通信
int main()
{
    char buf[1024]="change world!\n";
    int fds[2];
    if(pipe(fds)==-1)
        perror("pipe"),exit(1);
    pid_t pid = fork();
    if(pid==0)
    {
        sleep(2);
        close(fds[0]);
        if(write(fds[1],buf,1024)==-1)
            perror("write"),exit(1);

        close(fds[1]);
        exit(1);
    }
    else
    {
        memset(buf,0x00,1024);
        close(fds[1]);
        if(read(fds[0],buf,1024)==-1)
            perror("read"),exit(1);
        if(write(1,buf,1024)==-1)
            perror("write"),exit(1);
        close(fds[0]);
        exit(1);
    }
    return 0;
}
