#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char*argv[])
{
    printf("hello world\n");
    write(STDOUT_FILENO,"hello\n",6);

    if(fork()==-1)
        perror("fork");
    exit(EXIT_SUCCESS);
}
