#include "SeqList.h"

void InitList(SeqList *Seq)  //初始化顺序表
{
    Seq->size = 0;
    Seq->capicity=1;
    Seq->data=(DateType*)malloc(Seq->capicity *sizeof(DateType));
    memset(Seq->data,0,Seq->size *sizeof(DateType));
}

void PrintList(SeqList *Seq)  //打印顺序表
{
    size_t i =0;

    assert(Seq);
    for (i=0; i<Seq->size; i++)
        printf("%d ",Seq->data[i]);
    printf("\n");
}

void ListCheckFull(SeqList *Seq)  //检查容量，并扩容
{
    DateType *tmp;
    assert(Seq);

    if (Seq->size==Seq->capicity)
    {
        tmp= (DateType*)realloc(Seq->data,2*Seq->capicity*sizeof(DateType)+3*sizeof(DateType));
        if (NULL==tmp)
        {
            printf("扩容失败 !\n");
            return;
        }
        else
        {
            Seq->capicity=Seq->capicity*2+3;
            Seq->data=tmp;
        }
    }
}

void ListInsert(SeqList *Seq,size_t pos,DateType x)  //插入(包括头插和尾插)

{
    DateType end=0;
    assert(Seq);
    ListCheckFull(Seq);
    if (pos>Seq->size)
        printf("插入位置无意义\n");
    else
    {
        if (0==Seq->size)  //头插情况
        {
            Seq->data[Seq->size]=x;
            Seq->size++;
        }
        else if(pos==Seq->size)  //尾插情况
        {
            Seq->data[Seq->size]=x;
            Seq->size++;
        }
        else  //随机插入
        {
            end=Seq->size;
            while ((DateType)pos<end)
            {
                Seq->data[end]=Seq->data[end-1];
                end--;
            }
            Seq->data[end]=x;
            Seq->size++;
        }
    }
}


 void SeqListDelete(SeqList *Seq,size_t pos)  //删除
 {
     size_t tmp=pos-1;;
     assert(Seq);
     
     if (pos>=Seq->size)
     {
         printf("删除数据不存在 ！");
         return ;
     }
     else if (Seq->size==pos)  //尾删
     {
         Seq->size--;
     }
     else
     {
         while (tmp<Seq->size)  //任意位置删除
         {
             Seq->data[tmp]=Seq->data[tmp+1];
             tmp++;
         }
         Seq->size--;
     }
 }
 
DateType SeqListSearch(SeqList *Seq,DateType x)  //遍历查找
{
    DateType i = 0;
    assert(Seq);

    while (i<(int)Seq->size)
    {
        if (Seq->data[i]==x)
            return i;
        i++;
    }
    return -1;
} 

DateType SeqListBinarySearch(SeqList *Seq,DateType x)  //折半查找
{
    DateType start = 0;
    DateType end =Seq->size-1;
    DateType mid = 0;   
    assert(Seq);
    
    while (start<end)
    {
        mid = start+((end-start)>>1);
        if (x<Seq->data[mid])
            end=mid-1;
        else if (x>Seq->data[mid])
            start=mid+1;
        else
           return Seq->data[mid];
    }
    return -1;
}

void SeqListChange(SeqList *Seq,DateType pos, DateType x)  //修改
{
    size_t tmp;
    assert(Seq);

    tmp = SeqListSearch(Seq,pos);  //找到要修改的位置
    if (tmp != -1)
        Seq->data[tmp]=x;
    else
        printf("修改数不存在！");
}

void SeqListBubbleSort(SeqList *Seq)  //冒泡排序
{
    size_t i = 0;
    size_t j = 0;
    size_t flag =0;

    assert(Seq);

    for (i=0; i<Seq->size-1; i++)
    {
        for (j=0; j<Seq->size-1-i; j++)
        {
            if (Seq->data[j]>Seq->data[j+1])
            {
                flag=1;
                Seq->data[j]^=Seq->data[j+1];
                Seq->data[j+1]^=Seq->data[j];
                Seq->data[j]^=Seq->data[j+1];
            }
        }
        if (flag==0)  //优化冒泡次数
        {
            break;
        }
    }
}

void SeqListSelectSort(SeqList *Seq)  //选择排序
{
    DateType min;
    DateType max;
    size_t i=0;
    size_t j=0;
    size_t end;
    assert(Seq);

    end=Seq->size-1;
    for (i=0; i<=end; i++)
    {
        min=i;
        max=i;
        for (j=i; j<=end; j++)
        {
            if (Seq->data[j]<Seq->data[min])
                min=j;
            if (Seq->data[max]<Seq->data[j])
                max=j;
        }
        if (min!=i)
        {
            Seq->data[i]^=Seq->data[min];
            Seq->data[min]^=Seq->data[i];
            Seq->data[i]^=Seq->data[min];
        }
         if (max==i)
             max=min;
         if (max!=end)
         {
             Seq->data[end]^=Seq->data[max];
             Seq->data[max]^=Seq->data[end];
             Seq->data[end]^=Seq->data[max];
         }
         end--;
    }

}

