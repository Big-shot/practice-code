#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include <string.h>
#include<assert.h>


//��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
int StrToInt(char* str) 
{
    int flag = 1;
    int sum = 0;
    while (*str)
    {
        if (*str>='a' && *str<='z'
            || *str>='A' && *str<='Z')
        {
            flag = 0;
            break;
        }
        else 
        {
            if (*str == '-')
            {
                flag = -1;
                str++;
            }
            *str = *str - '0';
            if ('\0' == *(str+1))
            {
                sum +=*str ;
                break;
            }
            sum = (sum+ *str) * 10;
           
        }
        str++;
    }
    if (flag)
    {
        if (flag<0)
            return sum*flag;
        return sum;
    }
    return 0;
}

//��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������\
//���磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ��\ 
//����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�
int isNumeric(char* string)
{
    int flag1 = 0,flag2 = 0;
    while (*string)
    {
        if (*string >= '0'&& *string <= '9' ||
            *string == 'e' || *string =='E' ||
            *string == '.' || *string == '+'||
            *string == '-')
        {
            if (*string == 'E' || *string == 'e')
            {
                if (*(string+1) >'9' && *(string+1)<'0' || *(string+1) == '\0')
                {
                    return 0;
                }
            }
            if (*string == '+' || *string == '-')
            {
                flag2++;
                if (flag2>1)
                {
                    return 0;
                }
                if (*(string-1) >='0' && *(string-1) <='9')
                    return 0;
            }
            if (*string == '.')
            {
                flag1 ++ ;
                if (flag1>1)
                    return 0;
            }
            string++;
        }
        else
            return 0;
    }
    return 1;
}

void ReversePrintStr(char *str) //�����ӡ��-1234 ��> -4321
{
    if (*str=='\0')
        return;
    if(*str =='-' || *str=='+')
    {
        putchar(*str);
        str++;
    }
    ReversePrintStr(str+1);
    putchar(*str);
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

void my_print(const char *format,...)  //��ӡ���������Σ��ַ��������������ַ���
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



// int compare(void const * c1,void const* c2)
// {
//     int a = *((int*)c1);
//     int b = *((int*)c2);
//     return a>b ? 1 : a<b ? -1 : 0;
// }
int char_compare(void const * c1,void const* c2)
{
    int a = *((char*)c1);
    int b = *((char*)c2);
    return a>b ? 1 : a<b ? -1 : 0;
}

void Swap(char *str1,char *str2,int size)
{
    while (size--)
    {
        char tmp = *str1;
        *str1 = *str2;
        *str2 = tmp;
        str1++;str2++;
    }
}
void MyQsort(void *str,int len,int elen,int(*compare)(void const*,void const*))  //���ڻص�����д�������㷨
{
    int i = 0;
    int j = 0;
    int flag = 1;
    for (i=0; i<len-1; i++)
    {
        for (j=0; j<len-1-i; j++)
        {
            if (compare((char*)str+j*elen,(char*)str+(j+1)*elen)>0)
            {
                flag = 0;
                Swap((char*)str+j*elen,(char*)str+(j+1)*elen,elen);
            }
        }
        if (flag)
            return;
    }
}
void MyPrint(void *arr, int size)
{
    char *str = (char*)arr;
    while(*str)
     {
         putchar(*str);
         size--;
         if(size==0)
             printf("\n");
         str++;
     }
}


// int main()
// {
//     int arr[] ={2147483647,22,11,0,23,98,21,54,86,71,3,2,1};
//     //char arr[] = {'q','w','f','g','x','a','s','l','c'};
//     int len = sizeof(arr) / sizeof(arr[0]);
//     MyQsort(arr,len,sizeof(char),char_compare);
//     MyPrint(arr,sizeof(int));
//     //ReversePrintStr("+1234");
//     return 0;
// }

int Add(int x,int y)
{
    return x + y;
}

int Sub(int x,int y)
{
    return x - y;
}

int Mul(int x,int y)
{
    return x * y;
}

int Div(int x,int y)
{
    return x / y;
}
void menu()
{
    printf("#########################\n");
    printf("#  1.add         2.sub  #\n");
    printf("#  3.sub         4.div  #\n");
    printf("#               0.quit  #\n");
    printf("#########################\n");
    printf("plase select :");
}

// int main ()
// {
//     int select = 1;
//     int ret = 0;
//     int x,y;
//     char *op = "+-*/";
//     int (*cal[5])(int ,int ) = {0,Add,Sub,Mul,Div};
//     while(select)
//     {
//         menu();
//         scanf("%d",&select);
//         if (select>0 && select <5)
//         {
//             printf("please enter(x y):");
//             scanf("%d %d",&x,&y);
//             ret = (*cal[select])(x,y);
//             printf("%d %c %d = %d\n\n",x,op[select-1],y,ret);
//         }
//         else if (select == 0)
//         {
//             printf("began quit !\n");
//             break;
//         }
//         else
//             printf("enter error! please try again\n\n");
//     }
//     printf("good bye!\n");
//     return 0;
// }






// void main()
// {
//     char buf[][10] = {
//         "1111",
//         "2222",
//         "3333",
//         "4444",
//         "0"
//     };
// 
//     printf("sizeof buf = %d\r\n", sizeof(buf));
// 
//     if (buf[4] != NULL){
//         printf("buf[4] != NULL\n");
//     }
//     printf("%p \n",buf[4]);
//     system("pause");
// }

