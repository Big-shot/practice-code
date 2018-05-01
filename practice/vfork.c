
#include<stdio.h>
#include<unistd.h>

int val = 10;

int main()
{
    if(vfork()==0)
    {
        //close(1);
        sleep(1);
        val = 100;
        printf("%d %p child = %d\n",val,&val,getpid());
        _exit(1);
    }
    else
    {

        sleep(1);
        printf("%d %p parent = %d\n",val,&val,getppid());
    }
    return 0;
}
