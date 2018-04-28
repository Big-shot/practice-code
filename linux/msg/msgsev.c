#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>

struct msgbuf{
    long channal;
    char mtext[100];
};

int main()
{
  //  key_t _key = ftok("./",a);
  //  if(_key < 0){
  //      perror("ftok");
  //      return -1;

  //  }
    int id = msgget(123,IPC_CREAT|0644);
    if(id==-1)
        perror("msgget"),exit(1);

    while(1)
    {
       struct msgbuf mb;
       memset(mb.mtext,0,sizeof(mb));
       int r = msgrcv(id,&mb,100,1,0);
       if(r==-1)
           perror("msgrcv"),exit(1);
       printf("%s\n",mb.mtext+sizeof(long));
       printf("sev#");
       mb.channal = *(long *) mb.mtext;
       memset(mb.mtext,0,sizeof(mb.mtext));
       scanf("%s",mb.mtext+sizeof(long));
       msgsnd(id,&mb,strlen(mb.mtext+sizeof(long))+sizeof(long),0);
    }
    return 0;
}
