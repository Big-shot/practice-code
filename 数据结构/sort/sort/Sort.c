
#include "Sort.h"

//��������
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

//ѡ������
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
        if (max == left) //���ֵ�������
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

//��������
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
/*                                  ����                                */
/************************************************************************/

int GetMidKey(DataType*a, int left, int right) //�������������м������±�
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
{                     /* ����ָ�뷨*/
   /************************************************************************
     *ѡȡkey��key����ѡ��ѡ��߻����ұ߷�������㷨����                  
     *���ֵ����key���ұߣ�С��ֵ����key����ߡ�   
     *���bigin��end�ཻʱ����������ֵ��key��
     *���ؽ�����±꣬�ȴ���һ�εݹ�ʹ��
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
    /******************************���ڿӷ���********************************
     *ѡȡ��ʼ���ӣ���ѡȡ����߻������ұߵ�ֵ�������ֵ���ڿӵ��ұߣ�С��ֵ
     *���ڿӵ���ߣ�����������ʱ����ԭʼ�ӵ�ֵ���������ʱ�������ֵ�ȿӴ�
     *�ұ�����ֵ�ȿ�С��������ֳ����룬���εݹ顣
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
    /****************************��ǰ��ָ�뷨��******************************
     *��������ָ�룬���ǰ���a[cur]С��key��prev�͸����ߣ�����a[cur]����keyʱ
     *prevͣ������cur�����ߣ���a[cur]����keyʱ��һ�˽���������key��a[cur]��ƽ��
     *���飬���εݹ顣
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
    /****************************������˼·��********************************
     *����֮���Կ죬�������˶��ֵ�˼��
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

//�ǵݹ�
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

//�鲢����
