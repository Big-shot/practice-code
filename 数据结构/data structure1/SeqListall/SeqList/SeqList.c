#include "SeqList.h"

void InitList(SeqList *Seq)  //��ʼ��˳���
{
    Seq->size = 0;
    Seq->capicity=1;
    Seq->data=(DateType*)malloc(Seq->capicity *sizeof(DateType));
    memset(Seq->data,0,Seq->size *sizeof(DateType));
}

void PrintList(SeqList *Seq)  //��ӡ˳���
{
    size_t i =0;

    assert(Seq);
    for (i=0; i<Seq->size; i++)
        printf("%d ",Seq->data[i]);
    printf("\n");
}

void ListCheckFull(SeqList *Seq)  //���������������
{
    DateType *tmp;
    assert(Seq);

    if (Seq->size==Seq->capicity)
    {
        tmp= (DateType*)realloc(Seq->data,2*Seq->capicity*sizeof(DateType)+3*sizeof(DateType));
        if (NULL==tmp)
        {
            printf("����ʧ�� !\n");
            return;
        }
        else
        {
            Seq->capicity=Seq->capicity*2+3;
            Seq->data=tmp;
        }
    }
}

void ListInsert(SeqList *Seq,size_t pos,DateType x)  //����(����ͷ���β��)

{
    DateType end=0;
    assert(Seq);
    ListCheckFull(Seq);
    if (pos>Seq->size)
        printf("����λ��������\n");
    else
    {
        if (0==Seq->size)  //ͷ�����
        {
            Seq->data[Seq->size]=x;
            Seq->size++;
        }
        else if(pos==Seq->size)  //β�����
        {
            Seq->data[Seq->size]=x;
            Seq->size++;
        }
        else  //�������
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


 void SeqListDelete(SeqList *Seq,size_t pos)  //ɾ��
 {
     size_t tmp=pos-1;;
     assert(Seq);
     
     if (pos>=Seq->size)
     {
         printf("ɾ�����ݲ����� ��");
         return ;
     }
     else if (Seq->size==pos)  //βɾ
     {
         Seq->size--;
     }
     else
     {
         while (tmp<Seq->size)  //����λ��ɾ��
         {
             Seq->data[tmp]=Seq->data[tmp+1];
             tmp++;
         }
         Seq->size--;
     }
 }
 
DateType SeqListSearch(SeqList *Seq,DateType x)  //��������
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

DateType SeqListBinarySearch(SeqList *Seq,DateType x)  //�۰����
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

void SeqListChange(SeqList *Seq,DateType pos, DateType x)  //�޸�
{
    size_t tmp;
    assert(Seq);

    tmp = SeqListSearch(Seq,pos);  //�ҵ�Ҫ�޸ĵ�λ��
    if (tmp != -1)
        Seq->data[tmp]=x;
    else
        printf("�޸��������ڣ�");
}

void SeqListBubbleSort(SeqList *Seq)  //ð������
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
        if (flag==0)  //�Ż�ð�ݴ���
        {
            break;
        }
    }
}

void SeqListSelectSort(SeqList *Seq)  //ѡ������
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

