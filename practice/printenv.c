#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

//int main(int argc,char *argv[],char *env[])
//{
//    int i=0;
//    for(;env[i];i++)
//        printf("%s\n",env[i]);
//    return 0;
//}


//int main(int argc,char *argv[])
//{
//    extern char** environ;
//    int i = 0;
//    for(;environ[i];i++)
//        printf("%s\n",environ[i]);
//    return 0;
//}

////访问特定环境变量
//int main(int argc,char *argv[])
//{
//    printf("%s\n",getenv("PATH"));
//    return 0;
//}

int main()
{
    int val = 0;
    pid_t pid = fork();
    if(pid==0)
    {
        val = 100;
        printf("child:%d %d %p\n",getpid(),val,&val);
    }
    else
    {
        //sleep(5);
        printf("parent:%d %d %p\n",getpid(),val,&val);
    }
    sleep(1);
    return 0;
}
