#include<unistd.h>
#include<stdio.h>


int main()
{
    //while(1){
    pid_t pid = fork();
    if(pid==0)
    {
        sleep(1);
        printf("child = %d\n",getpid());
    }
    else
    {
        sleep(10);
        printf("parent = %d\n\n",getppid());
    }
    //}
    return 0;
}
