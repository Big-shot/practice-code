
/***************************************************************************************************
 *牛客网第一次
 ****************************************************************************************************/

//#include<windows.h>
//#include<stdio.h>
//#define _CRT_SECURE_NO_WARNINGS 1
//void InsertSort(int *a, size_t n)
//{
//	size_t i = 0;
//	for(i = 0; i<n - 1; ++i)
//	{
//		int end = i;
//		int tmp = a[end + 1];
//		while(end >= 0 && a[end] > tmp)
//		{
//			a[end + 1] = a[end];
//			end--;
//		}
//
//		a[end + 1] = tmp;
//	}
//}
//
//int GetSum(int *p,int left,int right,int s)
//{
//	int sum = 0;
//	for(int i = left; i < right; i++)
//	{
//		sum += p[i];
//		if(sum >= s)
//		{
//			return sum;
//		}
//	}
//	return -1;
//}
//
//int main( )
//{
//	int n = 0;
//	int s = 0;
//	int  i = 0;
//	int p[10] = {0};
//	scanf("%d%d", &n, &s);
//	for(i = 0; i < n; i++)
//	{
//		scanf("%d", p[i]);
//		if(p[i]<1 || p[i]>100)
//		{
//			printf("enter error !\n");
//			break;
//		}
//	}
//	InsertSort(p, n);
//	int count = 0;
//	int sum = 0;
//	sum = GetSum(p, 0, n,s);
//	if(sum > 0)
//	{
//		for(i = 0; i < n; i++)
//		{
//			if((sum - p[i])>s)
//			{
//				sum = 0;
//				i = 0;
//				while(sum < s)
//				{
//					sum += p[i];
//					i++;
//					count++;
//				}
//				printf("%d \n", count);
//				break;
//			}
//			else
//			{
//				sum = GetSum(p, i, n, s);
//			}
//		}
//	}
//
//	return 0;
//}

//#include<stdio.h>
//
//int main( )
//{
//	int m = 13;
//	int n = 9;
//	int b = (m | n);
//	int a = (m&n);
//	int count = 0;
//	while(b &= (b - 1))
//		count++;
//	while(a &= (a - 1))
//		count--;
//	
//	printf("%d \n", count);
//	printf("%d\n", m&n);
//	getchar( );
//	return 0;
//}


/***************************************************************************************************
*        深信服      2018.03.15
****************************************************************************************************/
//#define _CRT_SECURE_NO_DEPRECATE
//
//#include<stdio.h>
//#include<windows.h>
////二进制表示为1011000011111111，反序后val的二进制表示为1111111100001101。
//
//
//unsigned int reverse(unsigned int num)
//{
//	int i = 0;
//	int t = 0;
//	unsigned int sum = 0;
//	for(i = 31; i > 0; i--)
//	{
//		t =(((num<<(31-i))>>i)&1);
//		num <<= 1;
//		sum = (sum | (t<<(31-i)));
//	}
//	return sum;
//}
//
//int main( )
//{
//	unsigned int num = 0;
//	scanf("%d", &num);
//	printf("%u \n", reverse(num)); 
//	system("pause");
//	return 0;
//}

//int main(int argc, char *argv[])
//{
//	unsigned int num = 0;
//	unsigned int ret = 0;
//
//	if(1 != fscanf(stdin, "0x%x", &num))
//	{
//		fprintf(stderr, "input error\n");
//		return 0;
//	}
//	ret = reverse(num);
//	printf("%08x\n", ret);
//	return 0;
//}

//unsigned int total(int arr[], unsigned int size)
//{
//	int flag = 0;
//	int count = 0;
//	int i = 0, j = 0;
//	for(i = 0; i < size; i++)
//	{
//		flag = 0;
//		for(j = 0; j < size; j++)
//		{
//			if((arr[i] ^ arr[j]) == 0)
//				flag = 1;
//		}
//		if(flag)
//			count++;
//	}
//	return count;
//}

//static void heap_arrange(int arr[], int cur, int cnt)  //调整为小顶堆
//{
//	int heaptop_val = arr[cur]; //堆顶的值
//	while(cur < cnt)
//	{
//		int left = 2 * cur + 1;
//		int right = 2 * cur + 2;
//		int min = -1;
//		int min_val = arr[right];
//		if(left < cnt && arr[left] < heaptop_val)
//		{ //检查是否比左节点大
//			min = left;
//			min_val = arr[left];
//		}
//		if(right < cnt && arr[right] < min_val)
//		{//检查是否比右节点大
//			min = right;
//		}
//		if(min == 0)
//			break;
//		arr[cur] = min_val;
//		cur = min;
//	}
//	arr[cur] = arr[0];
//}

//一个正整数可以表示为多个正整数相加的表达式，表达式中的各个正整数要求都是2的幂。例如给定正整数7，
//它有下列六个符合要求的表达式：
//1)1 + 1 + 1 + 1 + 1 + 1 + 1
//2)1 + 1 + 1 + 1 + 1 + 2
//3)1 + 1 + 1 + 2 + 2
//4)1 + 1 + 1 + 4
//5)1 + 2 + 2 + 2
//6)1 + 2 + 4
//因此，正整数7符合条件的表达式个数是6.编写一个程序，对于给定的正整数N(1 <= N <= 1, 000)，
//输出符合条件的表达式个数。要求：时间复杂度不高于O(N)。
//unsigned int GetNum(unsigned int num)
//{
//	if(num == 0)
//		return 0;
//	else
//		return GetNum(num - 1)+1;
//}
//
//int main( )
//{
//	int num = 0;
//	scanf_s("%d", &num);
//	printf("%d \n", GetNum(num)-1);
//	getchar( );
//	return 0;
//}

//int main( )
//{
//	/*char i = 0;
//	i = 255;
//	printf("%d\n", i);*/
//	printf("%d\n", 7 ^ 7);
//	printf("%d\n", 5 ^ 7);
//
//
//	getchar( );
//	return 0;
//}


  /********************************************************************
  *                              网易游戏
  *********************************************************************/


//#include<stdio.h>
//#include<Windows.h>
//#include<stdlib.h>
//#include<iostream>
/*第二题*/

//int main( )
//{
//	int a[4] = {0};
//	int b[4] = {0};
//	int i = 0;
//	for(i = 0; i < 8; i++)
//	{
//		if(i < 4)
//			scanf("%d",&a[i]);
//		/*if(a[i]<0 || a[i]>30)
//			exit(1);*/
//		else
//			scanf("%d",&b[i-4]);
//		/*if(b[i]<1 || b[i]>100)
//			exit(1);*/
//	}
//	int max = 0;
//	int sum = 0;
//	for(i = 0; i < 4; i++)
//	{
//		sum = b[i];
//		int cur1 = sum;
//		int j = 0, k = 0, l = 0;
//		for(j = 0; j < 4; j++)
//		{
//			if(j != i)
//			{
//				sum = (sum % 10) * b[j];
//				int cur2 = sum;
//				for(k = 0; k < 4; k++)
//				{
//					if(k != i && k != j)
//					{
//						sum = (sum % 10) * b[k];
//						int cur3 = sum;
//						for(l = 0; l < 4; l++)
//						{
//							if(l != i&&l != j&&l != k)
//								sum = (sum % 10) * b[l];
//							if(max <= sum)
//								max = sum;
//							sum = cur3;
//						}
//					}
//					sum = cur2;
//				}
//			}
//			sum = cur1;
//		}
//	}
//	std::cout << max<<std::endl;
//	system("pause");
//	return 0;
//}


/*第一题*/
//int main( )
//{
//	int num = 0;
//	std::cin>>num;
//	if(num <= 100 && num >= 1)
//	{
//		int i = 0;
//		for(i = 0; i < num-1; i++)
//		{
//			int j = 0;
//			for(j = 0; j < num+i; j++)
//			{
//				if(j == num - i - 1 && j < num + i)
//					std::cout << "*";
//				
//				else if(j < num - i - 1)
//					std::cout << ".";
//			}
//			for(j = num-i-1; j < num + i; j++)
//			{
//				if(j < num + i-1 && j>num - 1 - i)
//					std::cout << ".";
//			}
//			if(i)
//				std::cout << "*";
//			std::cout << "\n";
//		}
//		for(i = 0; i < 2 * num - 1; i++)
//			std::cout << "*";
//		
//	}
//	system("pause");
//	return 0;
//}



		/********************************************************************
		 *                              携程旅游
		 *********************************************************************/

//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//#pragma warning(disable:4996)
//
//#include<iostream>
//#include<stdio.h>
//
//#define N 3
//
//int main()
//{
//	int i = 0, j = 0;
//	int arr[N][N] = {0};
//	for(i = 0; i<N; i++)
//	{
//		for(j = 0; j<N; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	for(i = 0; i<N; i++)
//	{
//		for(j = N - 1; j >= 0; j--)
//		{
//			printf("%d", arr[j][i]);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int *p = NULL;
//	int len = 0;
//	scanf("%d", &len);
//	p = (int *)malloc(sizeof(int)*len);
//	memset(p, 0, sizeof(int)*len);
//	int *a = p;
//	int *b = p;
//	int *str = p;
//	for(int i = 0; i<len; i++)
//	{
//		int num = 0;
//		scanf("%d", &num);
//		*p = num;
//		p++;
//	}
//	for(int i = 0; i<len; i++)
//	{
//		if(*a != 0 && i!=0)
//		{
//			while(*str != 0)
//			{
//				str++;
//			}
//			*str = *a;
//			*a = 0;
//
//		}
//		a++;
//	}
//	for(int i = 0; i<len; i++)
//	{
//		printf("%d\n", *b);
//		b++;
//	}
//	system("pause");
//	return 0;
//}
//#include<iostream>
//#include<stdio.h>
//
//#define N 3
//
//int main()
//{
//	int i = 0, j = 0;
//	int arr[N][N] = {0};
//	for(i = 0; i<N; i++)
//	{
//		for(j = 0; j<N; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	for(i = 0; i<N; i++)
//	{
//		for(j = N - 1; j >= 0; j--)
//		{
//			printf("%d", arr[j][i]);
//		}
//	}
//
//	return 0;
//
//}
