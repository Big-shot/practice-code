
#include<stdio.h>
#include<malloc.h>
#include<string.h>



void replaceSpace(char *str,int length) 
{
    int count=0;
    char *tmp3=str;
    char *tmp1=str;
    while(*tmp1)
    {
        if(*tmp1==' ')
            count++;
        tmp1++;
    }
    char *tmp2=(char*)malloc(length+count*2);
    if(!tmp2)
        return;
    str=tmp2;
    memset(str,0,length+count*2+1);
    while(*tmp3)
    {
        if(*tmp3==' ')
        {
            char*tmp = "%20";
            while(*tmp)
            {
                *tmp2=*tmp;
                tmp++;
                tmp2++;
            }
            tmp3++;
        }
        else
        {
            *tmp2=*tmp3;
            tmp2++;
            tmp3++;
        }


    }
printf("%s\n",str);
}

int main()
{
    char *str="we are happy";
    replaceSpace(str,strlen(str));
    printf("%s\n",str);
    return 0;
}
