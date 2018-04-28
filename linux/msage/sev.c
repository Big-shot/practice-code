#include<sys/ipc.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/fcntl.h>
#include<sys/msg.h>

struct msgbuf
{
    long channal;
    char mtaxt[100];
}

int main()
{
    int id = msgget(123,IPC_CREAT|0644);
    if(id==-1)
        perror("msgget"),exit(1);
    while(1)
    {
       struct msgbuf mb;
       if(msgrcv(id,&mb,100,1,0)==-1)
           perror("msgrcv"),exit(1);
       mb.channal =(long *)mb.msgbuf;
      
       msgsnd(id,&mb,100,0);
    }

    return 0;
}

