
//#include"practice.h"

//int Add1(int a, int b)
//{
//	return a + b;
//}
//
//int Add2(int a, int b = 1)
//{
//	return a + b;
//}
//
//namespace myname1
//{
//	int a = 1;
//}

//namespace myname2
//{
//	int a = 5;
//	namespace myname3
//	{
//		int a = 10;
//	}
//}
//int ret = 0;
//int Add1(int a, int b)
//{
//	ret = a + b;
//	return ret;
//}
//
//int& Add2(int a, int b)
//{
//	ret = a + b;
//	return ret;
//}
//
//int main( )
//{
//	printf("%d\n",Add1(1, 2));
//	printf("%d\n", Add2(1));
//	printf("%d\n", Add2(1,2));
//	printf("%d\n", Add1(5,6));
//	printf("%d\n", Add2(4,5));
//
//
//	system("pause");
//	return 0;
//}

//#include"practice.h"
//int main(void)
//{
//	Date d(2018, 5, 12);
//	d.Show();
//	Date d1(2018, 3, 27);
//	Date d2(2019, 12, 12);
//	//(d1+1000).Show();
//	//d1.Show( );
//	//(++d).Show();
//	//d.Show();
//	printf("%d\n", (d2 - d1));
//	/*d1=d+(-150);
//	d1.Show( );
//	(d + 150).Show();
//	(d - 150).Show();
//	d1+=156;
//	d1++;
//	d1.Show( );
//	Date d3(d1);
//	d3.Show();*/
//	system("pause");
//	return 0;
//}

#include<malloc.h>
#include<stdio.h>
#include<string.h>

void replaceSpace(char *str, int length)
{
	int count = 0;
	for(int i = 0; i<length; i++)
	{
		if(str[i] == ' ')
			count++;
	}
	char *cur = (char*)realloc(str, length + count * 2 + 1);
	if(!cur)
		return;
	str = cur;
	int len = length + count * 2;
	for(int i = length; i>0; i--)
	{
		if(str[i] == ' ')
		{
			char *tmp = "02%";
			while(*tmp)
			{
				str[len] = *tmp;
				tmp++;
				len--;
			}
		}
		str[len] = str[i];
		len--;
	}
}

int main( )
{
	replaceSpace("hello world",11);

	return 0;
}
