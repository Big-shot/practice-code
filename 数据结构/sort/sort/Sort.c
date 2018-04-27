
#include "Sort.h"

//插入排序
void InsertSort(DataType *a,size_t n)
{
    size_t i = 0;
    assert(a);
    for (i=0; i<n-1; ++i)
    {
        int end = i;
        DataType tmp = a[end+1];
        while (end>=0 && a[end] > tmp)
        {
            a[end+1] = a[end];
            end--;
        }

        a[end+1] = tmp;
    }
}

void ShellSort(DataType *a,size_t n)
{
    int gap = n;
    size_t i = 0;
    while (gap>1)
    {
        gap = gap/3 + 1;
        for (i=0; i<n-gap; i++)
        {
            int end = i;
            DataType tmp = a[end+gap];
            while (end >= 0 && a[end] > tmp)
            {
                a[end+gap] = a[end];
                end-= gap;
            }

            a[end+gap] = tmp;
        }
    }
}

//选择排序
void static Swap(DataType *a,DataType *b)
{
    DataType c = *a;
    *a = *b;
    *b = c;
}

void SelectSort(DataType *a,size_t n)
{
    size_t left = 0;
    size_t right = n-1;
    assert(a);
    while (left<right)
    {
        DataType min = left;
        DataType max = left;
        size_t i = left;
        for (i=left; i<=right;++i)
        {
            if (a[min] > a[i])
                min = i;
            if (a[max] < a[i])
                max = i;
        }
        Swap(&a[left],&a[min]); 
        if (max == left) //最大值在最左边
            max = min;
        Swap(&a[right],&a[max]);
        left++;
        right--;
    }
}

void AdjustDown(DataType *a,size_t n,size_t root)
{
    size_t parent = root;
    size_t child = parent *2+1;
    while (child<n)
    {
        if (a[child]<a[child+1] && child+1 <n)
            child++;
        if(a[parent] < a[child])
            Swap(&a[parent],&a[child]);

        parent = child;
        child = parent*2+1;
    }
}

void HeadSort(DataType *a,size_t n)
{
    size_t i =0;
    size_t end = n-1;
    for (i=(n-2)>>1; i>0; --i)
        AdjustDown(a,n,i);

    while (end)
    {
        Swap(&a[0],&a[end]);
        AdjustDown(a,end,0);
        end--;
    }
}

//交换排序
void BubbleSort(DataType *a,size_t n)
{
    size_t i,j,flag = 0;
    assert(a);
    for (i=0; i<n-1; i++)
    {
        flag = 0;
        for (j=0; j<n-i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                Swap(&a[j],&a[j+1]);
                flag = -1;
            }
        }
        if (!flag)
            break;
    }
}

/************************************************************************/
/*                                  快排                                */
/************************************************************************/

int GetMidKey(DataType*a, int left, int right) //返回三个数的中间数的下标
{
    int mid = left + ((right - left) >> 1);

    if ((a[left] < a[mid] && a[mid] < a[right])
        || (a[right] < a[mid] && a[mid] < a[left]))
    {
        return mid;
    }

    else if ((a[right] < a[left] && a[left] < a[mid])
        || (a[mid] < a[left] && a[left] < a[right]))
    {
        return left;
    }
    else
    {
        return right;
    }
}

int PartSort1(DataType *a,int left,int right)
{                     /* 左右指针法*/
   /************************************************************************
     *选取key（key随意选择，选左边或者右边方便设计算法），                  
     *大的值放在key的右边，小的值放在key的左边。   
     *最后当bigin和end相交时，交换交点值和key。
     *返回交点的下标，等待下一次递归使用
    /************************************************************************/
    int key = a[right];
    int begin = left;
    int end = right;
    while (begin<end)
    {
        while(a[begin] <= key && begin < end)
            begin++;
        while(a[end] >= key && begin < end)
            end--;
        Swap(&a[begin],&a[end]);
    }
    Swap(&a[begin],&a[right]);
    return end;
}

int PartSort2(DataType *a,int left,int right)
{
    /******************************【挖坑法】********************************
     *选取初始化坑，（选取最左边或者最右边的值），大的值放在坑的右边，小的值
     *放在坑的左边，当左右相遇时，把原始坑的值放在这里。此时左边所有值比坑大
     *右边所有值比坑小，把数组分成两半，依次递归。
     ************************************************************************/
    int begin = left;
    int end = right;
    DataType key = a[right];
    while (begin < end)
    {
        while(a[begin] <= key && begin  < end)
            begin++;
        a[right] = a[begin];
        while(a[end] >= key && begin < end)
            end--;
        a[begin] = a[end];
    }
    a[end] = key;
    return end;
}



int PartSort3(DataType *a,int left,int right) 
{
    /****************************【前后指针法】******************************
     *定义两个指针，如果前面的a[cur]小于key，prev就跟着走，遇到a[cur]大于key时
     *prev停下来，cur继续走，当a[cur]等于key时，一趟结束，交换key和a[cur]，平分
     *数组，依次递归。
     ************************************************************************/
    int prev = left-1;
    int cur = left;
    while (cur < right)
    {
        if (a[cur] < a[right] && a[cur] != a[++prev])
            Swap(&a[cur],&a[prev]);

        cur++;
    }
    Swap(&a[++prev],&a[right]);
    return prev;
}

void QSortR(DataType *a,int left, int right)
{
    /****************************【快排思路】********************************
     *快排之所以快，是利用了二分的思想
     ************************************************************************/
    assert(a);
    if (left<=right)
    {
        int mid = PartSort3(a,left,right);
        QSortR(a,left,mid-1);
        QSortR(a,mid+1,right);
    }
}
#include "stack.h"

//非递归
void QSort(DataType *a,int left,int right)
{
	Stack s;
	StackInit(&s);
	StackPush(&s, right);
	StackPush(&s, left);
	while (StackEmpty(&s))
	{
		int begin = StackTop(&s);
		StackPop(&s);
		int end = StackTop(&s);
		StackPop(&s);
		int div = PartSort1(a, begin, end);
		if (begin < div-1)
		{
			StackPush(&s, div - 1);
			StackPush(&s, begin);
		}
		else if(end > div + 1)
		{
			StackPush(&s, end);
			StackPush(&s, div+1);
		}
	}
}

//归并排序
