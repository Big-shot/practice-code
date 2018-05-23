/*************************************************************************
	> File Name: rwlock.c
	> Author: zhonglongbo
	> Mail: zhonglbo@163.com 
	> Created Time: Tue 22 May 2018 08:28:14 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<malloc.h>

int g_num = 0;
pthread_rwlock_t rw;

void *route_read(void* arg)
{
	int id = *((int*)arg);
	free(arg);
	while(1)
	{
		pthread_rwlock_rdlock(&rw);
		printf("%d read thread %d\n",g_num,id);
		sleep(1);
		pthread_rwlock_unlock(&rw);
	}
}


void *route_write(void* arg)
{
	int id = *((int*)arg);
	free(arg);
	while(1)
	{
		pthread_rwlock_rdlock(&rw);
		printf("%d write thread %d\n",++g_num,id);
		sleep(1);
		pthread_rwlock_unlock(&rw);
	}
}

int main()
{
	pthread_t w1,r1,r2,r3;
	pthread_rwlock_init(&rw,NULL);
	int *p = malloc(sizeof(int));
	*p = 1;
	pthread_create(&w1,NULL,route_write,p);
	p = (int*)malloc(sizeof(int));
	*p = 1;
	pthread_create(&r1,NULL,route_read,p);
	p = (int*)malloc(sizeof(int));
	*p = 1;
	pthread_create(&r2,NULL,route_read,p);
	p = (int*)malloc(sizeof(int));
	*p = 1;
	pthread_create(&r3,NULL,route_read,p);
	pthread_join(w1,NULL);
	pthread_join(r1,NULL);
	pthread_join(r2,NULL);
	pthread_join(r3,NULL);
	return 0;
}
