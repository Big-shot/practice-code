#include<stdio.h>
#include<sys/ipcs.h>
#include<unistd.h>

struct msgbuf
{
    long channal;
    char mtext[100];
}

int main()
{
    
    struct msgbuf mb;
    printf("channal:");
    scanf("%d",mb.channal);
    printf("mtext:");
    scanf("%s",mb.mtext);
    msgsnd(,mb.mtext,strlen(mb.mtext),0);
    return 0;
}
