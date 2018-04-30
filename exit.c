#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

static void fun1(void)
{
    printf("atexitfun1()\n");
}


static void fun2(void)
{
    printf("atexitfun2()\n");
}
static void fun3(void)
{
    printf("atexitfun3()\n");
}

int main()
{
    printf("hello world\n");
    //_exit(0);
    atexit(fun1);
    atexit(fun2);
    atexit(fun3);
    exit(0);
}
