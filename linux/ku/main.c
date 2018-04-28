
#include<stdio.h>
#include"add.h"
#include"sub.h"
#include"mul.h"
#include"dev.h"

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d + %d = %d\n",a,b,add(a,b));
    printf("%d - %d = %d\n",a,b,sub(a,b));
    printf("%d * %d = %d\n",a,b,mul(a,b));
    printf("%d / %d = %d\n",a,b,dev(a,b));
    return 0;
}
