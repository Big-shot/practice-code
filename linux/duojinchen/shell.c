#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<ctype.h>

void do_pid(int argc,char** argv)
{
    pid_t pid = fork();
    if(pid==0)
    {
        execvp(argv[0],argv);
        perror("execvp");

    }
    wait(NULL);
}
void do_str(char *buf)
{
    int i;
    int status = 0;
    char *argv[8] = {};
    int argc = 0;
    for(i=0;buf[i]!=0;i++)
    {
        if(status==0 && !isspace(buf[i]) )
            {
                argv[argc++] = buf+i;
                status = 1;
            }          
        else if(isspace(buf[i]))
        {
            status = 0;
            buf[i]= 0;
        }
    }
    argv[argc]=NULL;

    do_pid(argc,argv);
    
}

int main()
{
    char buf[1024];
    while(1)
    {
        printf("shell>");
        memset(buf,0,sizeof(buf));
        while(scanf("%[^\n]%*c",buf)==0)
        {
            printf("shell>");
            while(getchar()!='\n');
        }
        do_str(buf);
    }
    return 0;
}
