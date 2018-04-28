#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
    if(fork()==0)
    {
        sleep(10);
        printf("child=%d\n",getpid());
    }
    else
    {
        printf("parent=%d\n",getppid());
        waitpid(-1,NULL,0);
        exit(0);
    }
    return 0;
}
