#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

SeqList list;

void test1() //≤Â»Î≤‚ ‘

{
    InitList(&list);
    PrintList(&list);
    printf("\n");
    ListInsert(&list,0,4);
    ListInsert(&list,1,1);
    ListInsert(&list,2,2);
    ListInsert(&list,2,5);
    ListInsert(&list,2,6);
    ListInsert(&list,3,3);
    ListInsert(&list,5,10);
    ListInsert(&list,2,0);
    PrintList(&list);
    printf("\n");
}

void test2()  //…æ≥˝≤‚ ‘
{
    SeqListDelete(&list,1);
    SeqListDelete(&list,4);
    PrintList(&list);
    printf("\n");
}
 
void test3()  //±È¿˙≤È’“≤‚ ‘
{
    printf("%d ",SeqListSearch(&list,4));
    printf("%d ",SeqListSearch(&list,1));
    printf("%d ",SeqListSearch(&list,6));
    printf("%d ",SeqListSearch(&list,5));
    printf("%d ",SeqListSearch(&list,3));
    printf("%d ",SeqListSearch(&list,2));
    printf("%d ",SeqListSearch(&list,0));
    printf("%d ",SeqListSearch(&list,8));
    printf("\n");
}

void test4()  //–ﬁ∏ƒ≤‚ ‘
{
    SeqListChange(&list,2,16);
    SeqListChange(&list,6,46);
    SeqListChange(&list,5,16);
    PrintList(&list);
    printf("\n");
}

void test5()  //√∞≈›≤‚ ‘
{
    SeqListBubbleSort(&list);
    PrintList(&list);
    printf("\n");
}

void test6()  //—°‘Ò≈≈–Ú≤‚ ‘
{
    SeqListSelectSort(&list);
    PrintList(&list);
    printf("\n");

}

void test7()  //’€∞Î≤È’“≤‚ ‘
{
    printf("%d ",SeqListBinarySearch(&list,4));
    printf("%d ",SeqListBinarySearch(&list,1));
    printf("%d ",SeqListBinarySearch(&list,6));
    printf("%d ",SeqListBinarySearch(&list,5));
    printf("%d ",SeqListBinarySearch(&list,3));
    printf("%d ",SeqListBinarySearch(&list,2));
    printf("%d ",SeqListBinarySearch(&list,0));
    printf("%d ",SeqListBinarySearch(&list,8));
    printf("\n");
}

void test8()
{
    
}

int main ()

{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
  return 0;
}