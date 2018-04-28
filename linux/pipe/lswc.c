#include<unistd.h>

int main()
{
    int fds[2];
    pipe(fds);
    if(fork()==0)
    {
        close(1);
        close(fds[0]);
        dup(fds[1]);

    }
    else
    {

    }
    return 0;
}
