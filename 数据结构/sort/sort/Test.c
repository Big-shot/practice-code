#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

void PrintArry(DataType* a,size_t len)
{
    size_t i = 0;
    for (i=0; i<len; i++)
        printf("%d ",a[i]);
    printf("\n\n");
}

void TestInsertSort()
{
	DataType a[] = {9, 5, 6, 2, 3, 1, 7, 8, 0};
    //DataType a[] = {9,8,7,6,5,4,3,2,1};
    int len = sizeof(a)/sizeof(a[0]);
    PrintArry(a,len);
    //InsertSort(a,len);
    //ShellSort(a,len);
    //SelectSort(a,len);
    //HeadSort(a,len);
    //BubbleSort(a,len);
    //QSortR(a,0,len-1);
    QSort(a,0,len-1);
    PrintArry(a,len);
}

int main()
{
    TestInsertSort();
    return 0;
}