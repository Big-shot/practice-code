#include<string.h>
#include<stdio.h>

int main()
{
    int  i = 0;
    char arr[102]={};
    char* str = "/-\\-";
    for(i=0;i<100;i++)
    {
        arr[i]='#';
        printf("\r\033[47;35m%-100s]\033[0m%c \033[47;32m%d%% \033[0m %c",\
                arr,arr[101],i+1,str[i%4]);
        fflush(stdout);//刷新缓存区
        usleep(100000);//休眠100毫秒
    }
    printf("\n");
    return 0;
}
