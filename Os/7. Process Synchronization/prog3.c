//synchronozation using semapjores
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
int shared=5;
sem_t s;
void *func1()
{
	int local = shared;
	sem_wait(&s);
	local=local+1;
	sleep(3);
	shared=local;
	sem_post(&s);
	printf("shared in func1 is %d\n",shared);
}
void *func2()
{
        int local = shared;
        sem_wait(&s);
        local=local-1;
        shared=local;
        sem_post(&s);
        printf("shared in func2 is %d\n",shared);
}

int main()
{
	pthread_t t1,t2;
	sem_init(&s,0,1);
	pthread_create(&t1,NULL,func1,NULL);
	pthread_create(&t2,NULL,func2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}
