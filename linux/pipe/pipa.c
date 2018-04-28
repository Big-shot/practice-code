#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>



int main()
{
    int fds[2];
    if(pipe(fds)==-1)
        perror("pipe"),exit(1);

    if( fork()==0)
    {
        close(fds[0]);

        sleep(3);
        write(fds[1],"change world!",20);

        close(fds[1]);
    }
    else
    {
        close(fds[1]);

        char buf[100];
        int r = read(fds[0],buf,100);
        printf("r=%d %s\n",r,buf);
        close(fds[0]);
    }
    return 0;
}

