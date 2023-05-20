//synchronizarion using mutex
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
int shared=5;
pthread_mutex_t h;
void *func1()
{
	int local=shared;
	pthread_mutex_lock(&h);
	local=local+1;
	sleep(5);
	shared=local;
	pthread_mutex_unlock(&h);
	printf("shared in func1 is %d\n",shared);
	pthread_exit(NULL);
}

void *func2()
{
        int local=shared;
        pthread_mutex_lock(&h);
        local=local-1;
        shared=local; 
        pthread_mutex_unlock(&h);
        printf("shared in func2 is %d\n",shared);
        pthread_exit(NULL);
}
int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,func1,NULL);
	pthread_create(&t2,NULL,func2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}
