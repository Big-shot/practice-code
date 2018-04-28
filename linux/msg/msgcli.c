#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<stdlib.h>

struct msgbuf{
    long channal;
    char mtext[100];
};

int main()
{
  ////key_t _key = ftok(".", a);
  //  if(_key < 0){
  //      perror("ftok");
  //      return -1;

  //  }
  // int id = msgget(_key,IPC_CREAT|0644);
    int id = msgget(123,IPC_CREAT|0644);
    if(id==-1)
        perror("msgget"),exit(1);
    struct msgbuf mb;
    memset(mb.mtext,0,sizeof(mb));
    
    while(1)
    {
        printf("cli say#");
        *(long *)mb.mtext = (long)getpid();

        scanf("%s",mb.mtext+sizeof(long));
        mb.channal = 1;
        msgsnd(id,&mb,strlen(mb.mtext+sizeof(long))+sizeof(long),0);
        msgrcv(id,&mb,100,(long)getpid(),0);
        printf("%s\n",mb.mtext+sizeof(long));
    } 
    return 0;
}

