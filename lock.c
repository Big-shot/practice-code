/*************************************************************************
	> File Name: lock.c
	> Author: zhonglongbo
	> Mail: zhonglbo@163.com 
	> Created Time: Tue 22 May 2018 07:47:14 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


pthread_mutex_t mutex;
int a = 0;
int b = 0;
void *r1(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		a++;
		b++;
		if(a != b)
		{
			printf("%d != %d\n",a,b);
		}
		pthread_mutex_unlock(&mutex);
	}
}

void *r2(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		a++;
		b++;
		if(a != b)
		{
			printf("%d != %d\n",a,b);
		}
		pthread_mutex_unlock(&mutex);
	}	
}
int main(void)
{
	pthread_t t1,t2;
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&t1,NULL,r1,NULL);
	pthread_create(&t2,NULL,r2,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}
