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
//         if (ch>='A' && ch <='Z') //ch为大写字母时转换为小写
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

//原字符串中出现控制字符串中相同的字符，则返回该字符在原串中的地址
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
void reverse_str(char *str)  //字符串逆置
{
    char *tail = str;
    while (*tail) 
    {
        tail++;
    }
    --tail;//指针指向最后一个元素
    while (str<tail)
    {
        char cur = *str;  //头尾交换
        *str = *tail;
        *tail = cur;
        tail--,str++; //头指针后移，尾指针前移
    }
}
// 
// int Hermite(int n,int x)  //厄密多项式
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
// int Gcd(int m,int n) //求两个数的最大公约数
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
// void matrix_multiply(int *m1,int *m2,int *r,int x,int y,int z) //两个矩阵相乘
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

//在一个二维数组中，每一行都按照从左到右递增的顺序排序，
//每一列都按照从上到下递增的顺序排序。请完成一个函数，
//输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
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

////一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
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

//编写一个my_strlen函数，他类似于strlen函数，但是他能够处理由于使用strn--函数而创建的未能以null字节结尾的字符串。
int my_strlen(char *str,int n)  //求字符串长度
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

//编写一个my_strcpy函数，它类似于strcpy函数，但他不会溢出目标数组。复制的结果必须是一个真正的字符串
void my_strcpy(char *dst,char const *src,int n) //字符串拷贝函数（n是原字符串的长度）
{
    while (--n) //n控制溢出
    {
        if (*src == '\0')
            break;
        *(dst++) = *(src++);
    }
    *dst='\0';
}

//编写一个my_strcat函数，它类似于strcat函数，但他不会溢出目标数组。复制的结果必须是一个真正的字符串
void my_strcat(char *dst,char const *src,int n)//字符串连接（n为原字符串的长度，控制原字符串）
{
    while (n--) //找到原字符串的结束
    {
        if (*dst == '\0')
            break;
        dst++;
    }
    do 
    {
        *dst++ = *src++; //连接
        if ((--n)==0)
            break;
    } while (*src);
    *dst = '\0'; //加上字符串结束标志
}

//编写一个my_strcpy_end函数，它类似于strcpy函数，但他返回指向目标字符串结尾的得指针不会溢出目标数组。
//复制的结果必须是一个真正的字符串
char* my_strcpy_end(char *dst,char const *src,int n)
{
    while (--n) //n控制溢出
    {
        if (*src == '\0')
            break;
        *(dst++) = *(src++);
    }
    *dst='\0';
    return dst;
}

//编写一个my_strchr函数，他类似于strchr函数，只是他返回最后一次出现ch这个字符的地址。
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

//编写一个my_strchr函数，他类似于strchr函数，只是他返回第n次出现ch这个字符的地址。
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

//编写一个count_chars函数，该函数在第一个参数中进行查找，并返回chars中被匹配字符的个数。
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

//编写一个函数，原型：palindrome(char *str)，如果参数字符串是回文就返回1，不是回文返回
//(回文:Madam ,I'm Adam.忽略所有非字母字符)
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

//写一个函数，找出参数2的字符串再参数1字符串中匹配的次数。
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

//把一个数字字符串转换为标准美元表示格式。
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

//链表相关问题

typedef int DataType;
typedef struct LinkNode  //单链表结构
{
    struct LinkNode* next;
    DataType data;
}LinkNode;

LinkNode *CreateNode(DataType x) //创建单链表节点
{
    LinkNode *tmp = (LinkNode *)malloc(sizeof(LinkNode));
    if (NULL == tmp)
    {
        printf("分配内存失败！\n");
        return NULL;
    }
    tmp->next=NULL;
    tmp->data=x;
    return tmp;
}

void PrintLinkList(LinkNode *phead)  //单链表打印
{
    while (phead)
    {
        printf("%d ",phead->data);
        phead = phead->next;
    }
    printf("\n");
}

void InsertLinkList(LinkNode **phead,LinkNode *pos,DataType x)  //单链表插入
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

size_t ListNodeCount(LinkNode* phead) //计算单链表的节点数
{
    size_t count = 0;
    while (phead)
    {
        count++;
        phead = phead->next;
    }
    return count;
}

LinkNode *LinkListSearch(LinkNode *phead,DataType x)  //在单链表中查找一个数
{
    while(phead)
    {
        if (phead->data == x)
            return phead;
        phead = phead->next;
    }
    return NULL;
}

LinkNode *ReverseLinkList(LinkNode *phead)  //单链表的逆置
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

size_t RemoveLinkList(LinkNode **phead,LinkNode *pos)  //单链表任意节点删除
{
    LinkNode *first = *phead;
    while (first)
    {
        if (*phead == pos) //删头节点
        {
            *phead = first->next;
            free(pos);
            pos = NULL;
            return 1;
        }
        else if (first->next == pos) //非头节点情况
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

typedef struct DoubleLinkList  //双链表结构
{
    DataType data;
    struct DoubleLinkList *prev;
    struct DoubleLinkList *next;
}DoubleList;

DoubleList *CreateDoubleList(DataType x) //创建双链表节点
{
    DoubleList *newNode = (DoubleList *)malloc(sizeof(DoubleList));
    assert(newNode);
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = x;
    return newNode;
}

void PrintDoubleList(DoubleList *phead)  //打印双链表
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

DoubleList *DoubleListSearch(DoubleList *phead,DataType x)  //双链表查找
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

void DoubleListInsert(DoubleList **phead, DataType x) //双链表的头插
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


size_t RemoveDoubleListNode(DoubleList **phead,DataType x)  //删除双链表节点
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


int  NumberOf1(int n)  //求一个整数的二进制码中1的个数
{
    int count = 0;
    while (n)
    {
        count++;
        n=n&(n-1);
    }
    return count;
}


double Power(double base, int exponent)  //求一个浮点数的整数次幂
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

    while (*cur) //求出空格数和转换需要的中长度
    {
        if (' ' == *cur)
            len+=(strlen("%20")-1);
        len+=1;cur+=1;
    }
    if (len>length)  //所需长度len大于length，访问会越界
        exit(1);
    while (len>0)
    {
        if (*cur==' ')
        {
            char *target = "02%";
            while (*target) //循环替换
                str[len--] = *target++;
            cur--; //替换完毕cur后移，以便下次判断
        }
        else
            str[len--] = *cur--; //不为空格就复制
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
//             for (k=0; k<2; k++)//移动空格后面的字符串
//             {
//                 for (j= length-1; j>=i; j--)
//                     str[j] = str[j-1];
//             }
//             while (*tmp) //替换目标串
//                 str[i++] = *tmp++;
//             i-=1; //i循环在上面会自加，这里多加了一次
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
// //      begintime=clock();	//计时开始
// //      double b = sin(30.0);
// //      endtime = clock();	//计时结束
// //      printf("\n\nRunning Time：%dms\n", endtime-begintime);
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
    for (i=0; i<len-1; i++)  //给数组排序
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
    for (i = 0; i<len; i++) //遍历一遍查找是否有符合题意的数字
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
 //             k = i; //记录当前位置
 //             count++;
 //         }
 //         else
 //         {
 //             count--;//不同则计数器减1
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


void reOrderArray(int *arr,int len)  //把一个数组的所有奇数放在偶数的前面
{
    int *head = &arr[0];
    int *tail = &arr[len-1];
    while (head<tail)
    {
        if (!(*head&1) && (*tail&1)) //前面是偶数后面是偶数就交换
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
    va_start(vp,format); //vp指向第一个可选参数
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
                        int  n = va_arg(vp,int); //va—arg返回参数列表中的当前参数并使vp指向参数列表中的下一个参数。
                        char *string = _itoa(n,str,10); //把整数转为字符串
                        print_str(string);
                    }
                    break;
                case 'f':
                    {
                        char str[50];
                        double f = va_arg(vp,double);//va—arg返回参数列表中的当前参数并使vp指向参数列表中的下一个参数
                        char *string = _gcvt(f,10,str);//将浮点型数转换为字符串，取四舍五入
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
