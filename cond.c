/*************************************************************************
	> File Name: cond.c
	> Author: zhonglongbo
	> Mail: zhonglbo@163.com 
	> Created Time: Tue 22 May 2018 08:59:42 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

void *r1(void* arg)
{
	while(1){
	pthread_cond_wait(&cond,&mutex);
	printf("返回\n");
	}
}

void *r2(void* arg)
{
	while(1){

	pthread_cond_signal(&cond);
	sleep(1);
	}
}

int main()
{
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);

	pthread_t t1,t2;
	pthread_create(&t2,NULL,r2,NULL);
	pthread_create(&t1,NULL,r1,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&mutex);
}
