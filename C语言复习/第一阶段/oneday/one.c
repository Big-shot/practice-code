#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>
#include <string.h>
#include<stdarg.h>

// void primer()
// {
//     int i,j ,flag = 0,count=0;
//     for (i=1; i<=100; i++)
//     {
//         flag = 0;
//         for (j=2; j<i; j++)
//         {
//             if (i%j == 0)
//             {
//                 flag = 1;
//                 break;
//             }
//         }
//         if (flag==0)
//         {
//             count++;
//             printf("%d ",i);
//         }
//     }
//     printf("\n%d \n",count);
// }
// 
// void copy_n(char dst[],char src[],int n)
// {
//     int dst_i = 0,src_i = 0;
//     for (dst_i=0; dst_i<n; dst_i++)
//     {
//         dst[dst_i]=src[src_i];
// 
//         if (src[src_i] != '\0')
//         {
//             printf("%c ",dst[dst_i]);
//             src++;
//         }
//     }
// }
// 
// void prictice()
// {
//     int a = 20;
//     if (1<=a<=10)
//     {
//         printf("in \n");
//     }
//     else
//     {
//         printf("out \n");
//     }
// }
// 
// void GetPrint()
// {
//     char ch = 0;
//     while (ch != EOF)
//     {
//         ch = getchar();
//         if (ch>='A' && ch <='Z') //chΪ��д��ĸʱת��ΪСд
//             putchar(ch+('a'-'A'));
//         else
//            putchar(ch);
// 
//     }
// }
// 
// unsigned int reverse_bits(unsigned int value)
// {
//     int i = 1;
//     unsigned int answer = 0;
//     do 
//     {
//        answer<<=1;
//        if (value&1)
//            answer|=1;
//        value>>=1;
//     } while(i<<=1);
//     return answer;
// }

//ԭ�ַ����г��ֿ����ַ�������ͬ���ַ����򷵻ظ��ַ���ԭ���еĵ�ַ
// char *find_char(char const *source,char const *chars)  
// {
//     char const *tmp = chars;
//     char const *src = source;
//     while (*src)
//     {
//         tmp = chars;
//         while (*tmp)
//         {
//             if ((*src) == *tmp)
//             {
//                 return src;
//             }
//             tmp++;
//         }
//         src++;
//     }
//     return NULL;
// }

// int del_substr(char *str,char const*substr)
// {
//     char *string = str;
//     char const *substrs = substr;
//     while (*string)
//     {
//         int flag = 0;
//         substrs = substr;
//         while (*substrs)
//         {
//             if (*substrs == *string)
//             {
//                 while (*string)
//                 {
//                     if (*substrs == *string)
//                     {
//                         char *tmp = string;
//                         substrs++,string++;
//                         tmp = NULL;
//                         return 1;
//                     }
//                 }
//             }
//             substrs++;
//         }
//         string++;
//     }
//     while (*str)
//     {
//         printf("%c ",*str);
//         str++;
//     }
//     return 0;
// }
// 
void reverse_str(char *str)  //�ַ�������
{
    char *tail = str;
    while (*tail) 
    {
        tail++;
    }
    --tail;//ָ��ָ�����һ��Ԫ��
    while (str<tail)
    {
        char cur = *str;  //ͷβ����
        *str = *tail;
        *tail = cur;
        tail--,str++; //ͷָ����ƣ�βָ��ǰ��
    }
}
// 
// int Hermite(int n,int x)  //���ܶ���ʽ
// {
//     if (n<=0)
//     {
//         return 1;
//     }
//     if (n==1)
//     {
//        return  2*x;
//     }
//     return 2*x*Hermite(n-1,x)-2*(n-1)*Hermite(n-2,x);
// }
// 
// int Gcd(int m,int n) //�������������Լ��
// {
//     if (m%n==0)
//     {
//         return n;
//     }
//     return Gcd(n,m%n);
// }
// 
// int ascii_to_integer(char *str)
// {
//    int sum = 0;
//    while (*str)
//    {
//        if (*str>'9' || *str<'0')
//        {
//            return 0;
//        }
//        sum +=((*str)*10);
//        str++;
//    }
//    return sum;
// }
// 
// void matrix_multiply(int *m1,int *m2,int *r,int x,int y,int z) //�����������
// {
//     int i = 0;
//     int j = 0,k;
//     int *tmp1,*tmp2;
//     for (i=0; i<x; i++)
//     {
//         for (j=0; j<z; j++)
//         {
//             tmp1 = m1 +i*y;
//             tmp2 = m2 +j;
//             *r=0;
// 
//             for (k=0; k<y; k++)
//             {
//                 *r+= *tmp1 * *tmp2;
//                 tmp1++;
//                 tmp2+=z;
//             }
//             r++;
//         }
//     }
// }

//��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������
//ÿһ�ж����մ��ϵ��µ�����˳�����������һ��������
//����������һ����ά�����һ���������ж��������Ƿ��и�������
int FindNum(int arr[][4],int n)
{
   int i = 0;
   int j = 3;
   while (i<3 && j>=0)
   {
       if (n==arr[i][j])
       {
           return 1;
       }
       else if (n<arr[i][j])
       {
           j--;
       }
       else
           i++;
   }
   return 0;
}

////һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������
//int jumpFloor(int number)
//{
//    int f=1,g=2;
//    number--;
//    while(number--)
//    {
//        g+=f;
//        f=g-f;
//    }
//    return f;
//}
//
//int Fibonacci(int n)
//{
//    int i,sum;
//    int a = 0;
//    int b = 1;
//    if(n<2)
//        return n;
//    for(i=1; i<n; i++)
//    {
//        sum = a + b;
//        a = b;
//        b = sum;
//    }
//    return sum;
//}

//��дһ��my_strlen��������������strlen�������������ܹ���������ʹ��strn--������������δ����null�ֽڽ�β���ַ�����
int my_strlen(char *str,int n)  //���ַ�������
{
    int lenth = 0;
    while (lenth<n)
    {
        if (*(str++) == '\0')
            break;
        ++lenth;
    }
    return lenth;
}

//��дһ��my_strcpy��������������strcpy�����������������Ŀ�����顣���ƵĽ��������һ���������ַ���
void my_strcpy(char *dst,char const *src,int n) //�ַ�������������n��ԭ�ַ����ĳ��ȣ�
{
    while (--n) //n�������
    {
        if (*src == '\0')
            break;
        *(dst++) = *(src++);
    }
    *dst='\0';
}

//��дһ��my_strcat��������������strcat�����������������Ŀ�����顣���ƵĽ��������һ���������ַ���
void my_strcat(char *dst,char const *src,int n)//�ַ������ӣ�nΪԭ�ַ����ĳ��ȣ�����ԭ�ַ�����
{
    while (n--) //�ҵ�ԭ�ַ����Ľ���
    {
        if (*dst == '\0')
            break;
        dst++;
    }
    do 
    {
        *dst++ = *src++; //����
        if ((--n)==0)
            break;
    } while (*src);
    *dst = '\0'; //�����ַ���������־
}

//��дһ��my_strcpy_end��������������strcpy��������������ָ��Ŀ���ַ�����β�ĵ�ָ�벻�����Ŀ�����顣
//���ƵĽ��������һ���������ַ���
char* my_strcpy_end(char *dst,char const *src,int n)
{
    while (--n) //n�������
    {
        if (*src == '\0')
            break;
        *(dst++) = *(src++);
    }
    *dst='\0';
    return dst;
}

//��дһ��my_strchr��������������strchr������ֻ�����������һ�γ���ch����ַ��ĵ�ַ��
char *my_strchr(char  *str,int ch)
{
    char *result = NULL;
    while (*str)
    {
        if (ch == (int)*str)
            result = str;
        str++;
    }
    return result;
}

//��дһ��my_strchr��������������strchr������ֻ�������ص�n�γ���ch����ַ��ĵ�ַ��
char *my_strnchr(char  *str,int ch,int n)
{
    char *result = NULL;
    while (*str)
    {
        if ((int)*str == ch)
        {
            result = str;
            if (0 == --n)
               break;
        }
        str++;
    }
    return result;
}

//��дһ��count_chars�������ú����ڵ�һ�������н��в��ң�������chars�б�ƥ���ַ��ĸ�����
int count_chars(char const*str,char const *chars)
{
    char const *tmp = str;
    int count = 0;
    while (*chars)
    {
        tmp = str;
        while (*tmp)
        {
            if (*tmp == *chars)
            {
                count++;
                break;
            }
            tmp++;
        }
        chars++;
    }
    return count;
}

//��дһ��������ԭ�ͣ�palindrome(char *str)����������ַ����ǻ��ľͷ���1�����ǻ��ķ���
//(����:Madam ,I'm Adam.�������з���ĸ�ַ�)
int palindrome(char *str)
{
    char *tmp = str;
    while (*str)
        str++;
    str-=1;
    while (tmp<str)
    {
        if (*tmp>='a' && *tmp<='z' || *tmp>='A' && *tmp<='Z')
        {
            if (*str>='a' && *str<='z' || *str>='A' && *str<='Z')
            {
                *tmp = tolower(*tmp);
                *str = tolower(*str);
                if (*tmp != *str)
                    return 0;
                tmp++,str--;
            }
            else
                str--;
        }
        else
            tmp++;
    }
    return 1;
}

//дһ���������ҳ�����2���ַ����ٲ���1�ַ�����ƥ��Ĵ�����
int count_target(char const* str,char *target)
{
    int count = 0;
    while (*str)
    {
        char *tmp = target;
        if (*tmp == *str)
        {
            while (*tmp)
            {
                if (*tmp == *str)
                {
                    tmp++,str++;
                }
                else
                    break;
            }
            if ('\0'==*tmp)
            {
                count++;
            }
        }
        else
           str++;
    }
    return count;
}

//��һ�������ַ���ת��Ϊ��׼��Ԫ��ʾ��ʽ��
void dollars(char *dst,char const*src)
{
    int lenth = 0;
    int flag = 0,i = 0;
    while (*src)
    {
        lenth++;
        src++;
    }
    src-=1;
    while (lenth)
    {
        *dst++ = *src--;
        lenth--;
        i++;
        if (2==i && 0==flag)
        {
            *dst++ = '.';
            i = 0;
            flag = 1;
        }
        if (3 == i && 1 == flag)
        {
            *dst++ = ',';
            i = 0;
        }
    }
    *dst = '$';
}

//////////////////////////////////////////////////////////////////////////

//�����������

typedef int DataType;
typedef struct LinkNode  //������ṹ
{
    struct LinkNode* next;
    DataType data;
}LinkNode;

LinkNode *CreateNode(DataType x) //����������ڵ�
{
    LinkNode *tmp = (LinkNode *)malloc(sizeof(LinkNode));
    if (NULL == tmp)
    {
        printf("�����ڴ�ʧ�ܣ�\n");
        return NULL;
    }
    tmp->next=NULL;
    tmp->data=x;
    return tmp;
}

void PrintLinkList(LinkNode *phead)  //�������ӡ
{
    while (phead)
    {
        printf("%d ",phead->data);
        phead = phead->next;
    }
    printf("\n");
}

void InsertLinkList(LinkNode **phead,LinkNode *pos,DataType x)  //���������
{
    LinkNode *newNode,*tmp = *phead;
    assert(phead);
    if (NULL==*phead)
    {
        *phead = CreateNode(x);
        return;
    }
    while(*phead != pos)
    {
        tmp = *phead;
        *phead = (*phead)->next;
    }
    newNode = CreateNode(x);
    newNode->next = tmp->next;
    tmp->next = newNode;
}

size_t ListNodeCount(LinkNode* phead) //���㵥����Ľڵ���
{
    size_t count = 0;
    while (phead)
    {
        count++;
        phead = phead->next;
    }
    return count;
}

LinkNode *LinkListSearch(LinkNode *phead,DataType x)  //�ڵ������в���һ����
{
    while(phead)
    {
        if (phead->data == x)
            return phead;
        phead = phead->next;
    }
    return NULL;
}

LinkNode *ReverseLinkList(LinkNode *phead)  //�����������
{
    LinkNode *first = phead;
    LinkNode *cur = first->next;
    first->next=NULL;

    while (cur)
    {
        LinkNode *tmp = cur->next;
        cur->next = first;
        first = cur;
        cur = tmp;
    }
    return first;
}

size_t RemoveLinkList(LinkNode **phead,LinkNode *pos)  //����������ڵ�ɾ��
{
    LinkNode *first = *phead;
    while (first)
    {
        if (*phead == pos) //ɾͷ�ڵ�
        {
            *phead = first->next;
            free(pos);
            pos = NULL;
            return 1;
        }
        else if (first->next == pos) //��ͷ�ڵ����
        {
            first->next = pos->next;
            free(pos);
            pos = NULL;
            return 1;
        }
        first = first->next;
    }
    return 0;
}

typedef struct DoubleLinkList  //˫����ṹ
{
    DataType data;
    struct DoubleLinkList *prev;
    struct DoubleLinkList *next;
}DoubleList;

DoubleList *CreateDoubleList(DataType x) //����˫����ڵ�
{
    DoubleList *newNode = (DoubleList *)malloc(sizeof(DoubleList));
    assert(newNode);
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = x;
    return newNode;
}

void PrintDoubleList(DoubleList *phead)  //��ӡ˫����
{
    DoubleList *tmp = phead;
    while (tmp)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
        if (tmp == phead)
            break;
    }
    printf("\n");
}

DoubleList *DoubleListSearch(DoubleList *phead,DataType x)  //˫�������
{
    DoubleList *tmp = phead;
    while (phead)
    {
        if (phead->data == x)
            return phead;
        if (tmp == phead->next)
            break;
        phead = phead->next;
    }
    return NULL;
}

void DoubleListInsert(DoubleList **phead, DataType x) //˫�����ͷ��
{
    DoubleList *tmp = (*phead);
    DoubleList *newNode = CreateDoubleList(x);

    if (NULL == *phead)
    {
        *phead = newNode;
        (*phead)->next = *phead;
        (*phead)->prev = *phead;
    }
    else 
    {
        newNode->next = (*phead)->next;
        (*phead)->next = newNode;
        newNode->prev = *phead;
        newNode->next->prev = newNode;
    }
}


size_t RemoveDoubleListNode(DoubleList **phead,DataType x)  //ɾ��˫����ڵ�
{
    DoubleList *tmp = *phead;
    while (*phead)
    {
        if (tmp->data == x)
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            if (tmp->data == (*phead)->data)
               *phead = tmp->next;
            if ((*phead)->next == *phead)
            {
                free(*phead);
                *phead = NULL;
            }
            free(tmp);
            tmp = NULL;
            return 1;
        }
        if (*phead == tmp->next)
            break;
        tmp = tmp->next;
    }
    return 0;
}

void mystery(int n)
{
    n += 5;
    n /= 10;
    printf("%s \n","**********"+10-n);
}

// void Test1()
// {
//     LinkNode *list = NULL;
//     InsertLinkList(&list,list,1);
//     InsertLinkList(&list,list,2);
//     InsertLinkList(&list,list,3);
//     InsertLinkList(&list,list,4);
//     InsertLinkList(&list,list,5);
//     PrintLinkList(list);
// 
//     LinkListSearch(list,1);
//     printf("%p \n",LinkListSearch(list,1));
//     list = ReverseLinkList(list);
//     RemoveLinkList(&list,LinkListSearch(list,1));
//     RemoveLinkList(&list,LinkListSearch(list,5));
//     RemoveLinkList(&list,LinkListSearch(list,4));
//     RemoveLinkList(&list,LinkListSearch(list,3));
//     RemoveLinkList(&list,LinkListSearch(list,2));
// 
//     PrintLinkList(list);
// 
//     DoubleList *DList = NULL;
//     DoubleListInsert(&DList,5);
//     DoubleListInsert(&DList,6);
//     DoubleListInsert(&DList,7);
//     DoubleListInsert(&DList,8);
//     PrintDoubleList(DList);
// 
//     RemoveDoubleListNode(&DList,8);
//     RemoveDoubleListNode(&DList,7);
//     RemoveDoubleListNode(&DList,5);
//     RemoveDoubleListNode(&DList,6);
// 
//     PrintDoubleList(DList);
//     mystery(88);  
//}

//////////////////////////////////////////////////////////////////////////


int  NumberOf1(int n)  //��һ�������Ķ���������1�ĸ���
{
    int count = 0;
    while (n)
    {
        count++;
        n=n&(n-1);
    }
    return count;
}


double Power(double base, int exponent)  //��һ������������������
{
    long long p = abs( (long long) exponent);
    double r = 1.0;

      while (p) 
      {
        if (p & 1)
            r *= base;
        base *= base;
        p >>= 1;
    }
     
    return ( exponent > 0 ) ? r : 1/r;
}

void replaceSpace(char *str,int length)
{
    char *cur = str;
    int len = 0;

    while (*cur) //����ո�����ת����Ҫ���г���
    {
        if (' ' == *cur)
            len+=(strlen("%20")-1);
        len+=1;cur+=1;
    }
    if (len>length)  //���賤��len����length�����ʻ�Խ��
        exit(1);
    while (len>0)
    {
        if (*cur==' ')
        {
            char *target = "02%";
            while (*target) //ѭ���滻
                str[len--] = *target++;
            cur--; //�滻���cur���ƣ��Ա��´��ж�
        }
        else
            str[len--] = *cur--; //��Ϊ�ո�͸���
    }

}

// void replaceSpace(char *str,int length)
// {
//     int i = 0;
//     for (i=0; i<length; i++)
//     {
//         if (str[i] == ' ')
//         {
//             char *tmp = "%20";
//             int j = length-1;
//             int k = 0;
//             for (k=0; k<2; k++)//�ƶ��ո������ַ���
//             {
//                 for (j= length-1; j>=i; j--)
//                     str[j] = str[j-1];
//             }
//             while (*tmp) //�滻Ŀ�괮
//                 str[i++] = *tmp++;
//             i-=1; //iѭ����������Լӣ���������һ��
//         }
//     }
// }
void reverse(char*str,int len)
{
    int i = 0;
    while (i<len)
    {
        char tmp = str[i];
        str[i] = str[len-1];
        str[len-1] = tmp;
        i++;len--;
    }
}

char* LeftRotateString(char* str, int n) 
{
    int lenstr = 0;
    int len = 0;
    char *tmp = str;
    while (*tmp)
    {
        tmp++;
        lenstr++;
    }
    len =  lenstr - n;
    reverse(str,n);
    reverse(str+n,len);
    reverse(str,lenstr);
    return str;
}

//  int main()
//  {
//      //printf("%d \n",NumberOf1(1));
//      char str[]= "abcdef";
//      printf("%s \n",str);
//      LeftRotateString(str,3);
//      printf("%s \n",str);
// 
// //      int begintime,endtime;
// //      begintime=clock();	//��ʱ��ʼ
// //      double b = sin(30.0);
// //      endtime = clock();	//��ʱ����
// //      printf("\n\nRunning Time��%dms\n", endtime-begintime);
// //      Test1();
// //       char str[20] = " helloworld";
// //       replaceSpace(str,20);
// //      printf("%lf \n",b);
//      return 0;
//  }

void Swap(int *a, int *b)
{
    *a^= *b;
    *b^= *a;
    *a^= *b;
}

void FindData(int *p,int len)
{
    int i = 0;
    int value = p[0];
    int flag = 1;
    int data1 = 0;
    int data2 = 0;
    int  bit = 8*sizeof(int);
    for (i=1; i<len; i++)
        value ^= p[i];
    for (i=0; i<bit; i++)
    {
        if (value & (flag<<=i))
            break;
    }
    for (i=0; i<len; i++)
    {
        if (p[i] & flag)
        {
            data1 ^= p[i];
        }
        else
            data2 ^= p[i];
    }
    printf("%d\n %d\n",data1,data2);
}

//int main()
//{
//
//     union ip_adder
//     {
//         unsigned long addr ;
//         struct
//         {
//             unsigned char c1;
//             unsigned char c2;
//             unsigned char c3;
//             unsigned char c4;
//         }ip;
//     }my_ip;
//     my_ip.addr = 2433525958;
//     printf("%u.%u.%u.%u \n",my_ip.ip.c1,my_ip.ip.c2,my_ip.ip.c3,my_ip.ip.c4);
//     my_ip.ip.c1 = 198;
//     my_ip.ip.c2 = 168;
//     my_ip.ip.c3 = 12;
//     my_ip.ip.c4 = 145;
//     printf("%u \n",my_ip.addr);
//
//
//     int a = 0;
//     int b = 0;
//     scanf("%d%d",&a,&b);
//     Swap(&a,&b);
//     printf("%d %d \n",a,b);
//     int arr[] = {1,2,3,4,5,3,2,8,4,5};
//     int len = sizeof(arr) / sizeof(arr[0]);
//     FindData(arr,len);
//    printf("%d \n",f);
//     return 0;
// }
//abcd abdc acbd acdb 


int MoreThanHalfNum_Solution(int *arr,int len) 
{
    int i,j,flag = 1,count = 1;
    for (i=0; i<len-1; i++)  //����������
    {
        for (j=0; j<len-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                flag = 0;
            }
        }
        if (flag)
            break;
    }
    for (i = 0; i<len; i++) //����һ������Ƿ��з������������
    {
        if (arr[i] == arr[i+1])
        {
            j = i;
            count++;
            if (count>(len>>1)) 
            {
                return arr[j];
            }
        }
        else
        {
            count = 1;
        }
    }
    return 0;
}

 //int MoreThanHalfNum_Solution(int *arr,int len) 
 // {
 //     int i = 1;
 //     int k = 0;
 //     int count = 1;
 //     while (i<len)
 //     {
 //         if (arr[i]==arr[k]) 
 //         {
 //             k = i; //��¼��ǰλ��
 //             count++;
 //         }
 //         else
 //         {
 //             count--;//��ͬ���������1
 //             if (count == 0)
 //             {
 //                 count = 1;
 //                 k = i;
 //             }
 //         }
 //         i++;
 //     }
 //     if (count)
 //     {
 //         count = 0;
 //         for (i=0; i<len; i++)
 //         {
 //             if(arr[k]==arr[i])
 //                 count++;
 //         }
 //         if (count>len/2)
 //             return arr[k];
 //         else
 //             return 0;
 //     }
 //     else
 //         return 0;
 // }


void reOrderArray(int *arr,int len)  //��һ�������������������ż����ǰ��
{
    int *head = &arr[0];
    int *tail = &arr[len-1];
    while (head<tail)
    {
        if (!(*head&1) && (*tail&1)) //ǰ����ż��������ż���ͽ���
        {
            int tmp = *head;
            *head = *tail;
            *tail = tmp;
            head++;
            tail--;
            continue;
        }
        else if (*head&1)
            head++;
        else if (!(*tail&1))
            tail--;
    }
}



int Sum(int n,...)
{
    int i = 0,sum = 0;
    va_list vp;
    va_start(vp,n);
    for (i=0; i<n; i++)
    {
        sum +=va_arg(vp,int); 
    }
    va_end(vp);
    return sum;
}

void print_str(char *str)
{
    assert(str);
    while (*str)
    {
        putchar(*str);
        str++;
    }
}

void my_print(const char *format,...)
{
    char c = 0;
    va_list vp; 
    va_start(vp,format); //vpָ���һ����ѡ����
    while (*format)
    {
        c = *format;
        switch (c)
        {
        case '%':
            {
                char c = *(++format);
                switch (c)
                {
                case 'd':
                    {
                        char str[50];
                        int  n = va_arg(vp,int); //va��arg���ز����б��еĵ�ǰ������ʹvpָ������б��е���һ��������
                        char *string = _itoa(n,str,10); //������תΪ�ַ���
                        print_str(string);
                    }
                    break;
                case 'f':
                    {
                        char str[50];
                        double f = va_arg(vp,double);//va��arg���ز����б��еĵ�ǰ������ʹvpָ������б��е���һ������
                        char *string = _gcvt(f,10,str);//����������ת��Ϊ�ַ�����ȡ��������
                        print_str(string);
                    }
                	break;
                case 'c':
                    putchar(va_arg(vp,char));
                    break;
                case 's':
                    {
                        char *string = va_arg(vp,char*);
                        print_str(string);
                    }
                    break;
                default:
                    break;
                }
            }
        	break;
        default:
            putchar(c);
            break;
        }
        format++;
    }
    va_end(vp);
}


int main()
{
//     int arr[] = {1,2,3,4,5,6,7,8,9,1,0,1,3,5,7,9};
//     printf reOrderArray(arr,sizeof(arr)/sizeof(arr[0]));
    //printf("%d \n",MoreThanHalfNum_Solution(arr,sizeof(arr)/sizeof(arr[0])));
//     char *str = "nihao";    
//     fputc(str,stdout);
    my_print("world = %d hello %f hello :%s hello :%c\n",15,15.001,"abc",'c');
//     char str[]="2147483647";
//     printf("%d \n",StrToInt(str));
    return 0;
}
