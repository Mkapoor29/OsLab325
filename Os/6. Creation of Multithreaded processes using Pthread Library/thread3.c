//program to pass message from main
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *func(void *i)
{
	char *msg=(char *)i;
	printf("thread func executing.....%s\n",msg);
	return NULL;
}
int main()
{
	pthread_t t1, t2;
	int r1, r2;
	char *msg1="first thread";
	char *msg2="second thread";
	r1=pthread_create(&t1,NULL,func,(void *)msg1);
	r2=pthread_create(&t2,NULL,func,(void *)msg2);
	pthread_join(t1,NULL);pthread_join(t2,NULL);
	exit(0);
}
