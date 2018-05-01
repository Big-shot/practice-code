#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<ctype.h>

char *argv[10];
int argc;

void do_str(char *buf)
{
    int i = 0;
    argc = 0;
    int status = 0;
    for(i=0; buf[i] ; i++)
    {
        if(!isspace(buf[i]) && status==0)
        {
            argv[argc++]=buf+i;
            status = 1;
        }
        else if(isspace(buf[i]))
        {
            status = 0;
            buf[i] = '\0';
        }
    }
    argv[argc]=NULL;
}

void do_exec()
{
    pid_t pid = fork();
    if(pid==-1)
    {
        perror("fork");
        exit(1);
    }
    else if(pid==0)
    {
        execvp(argv[0],argv);
        exit(0);
    }
    else
    {
        int status;
        while(wait(&status) != pid);
    }
}

int main()
{
    char buf[1024]={};

    while(1)
    {
        printf("myshell#");
        fgets(buf,1024,stdin);
        do_str(buf);
        do_exec();
    }
    return 0;
}
