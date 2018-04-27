// #include<time.h>
// #include<time.h>
// #include<stdio.h>
// int main()
// {
//     struct tm *ptm;
//     time_t ts;
//     char tim[50];
//     ts = time(NULL);
//     ptm = localtime(&ts);
//     sprintf(tim,"(%d-%d-%d %02d:%02d:%02d):",ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday,ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
//     printf("%s",tim);
// }

#include <stdio.h> 
#include <string.h> 
#include <time.h> 
#include <Windows.h>

void Show(void) 
{ 
        char str[50]; 
        time_t t; 
        struct tm *lt; 
        t = time(NULL); 
        lt = localtime(&t);
        lt->tm_min=0;
        while(1)
        {
        strftime(str,100,"%Y-%m-%d  %M:%S ",lt); 
        Sleep(1000);
        lt->tm_isdst++;
        system("cls");
        printf("time:\n%s\n",str); 
        }
} 

void main()
{
    Show();
}