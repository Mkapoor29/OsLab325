#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *myFunc(void *myvar)
{
	char *msg;
	msg = (char*)myvar;
	for(int i =0;i<10;i++)
	{
		printf("%s %d\n",msg,i);
		sleep(1);
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t thread1, thread2;
	char *msg1 = "first thread";
	char *msg2 = "second thread";
	int ret1, ret2;
	ret1 = pthread_create(&thread1,NULL,myFunc,(void *)msg1);
	ret2 = pthread_create(&thread2,NULL,myFunc,(void *)msg2);
	printf("Main fun after thread creation\n");
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("first thread ret1= %d\n", ret1);
	printf("second thread ret2= %d\n", ret2);
	return 0;
}
