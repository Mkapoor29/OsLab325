#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *mythread(void *vargs)
{
	printf("Created Successfully\n");
	return NULL;
}
int main()
{
	pthread_t t;
	printf("Before\n");
	pthread_create(&t,NULL,mythread,NULL);
	pthread_join(t,NULL);
	printf("After\n");
	exit(0);
}
