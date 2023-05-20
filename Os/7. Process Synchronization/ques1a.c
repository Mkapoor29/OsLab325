#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int buffer=0;
pthread_mutex_t l;
void *prod()
{
	while(1)
	{
		pthread_mutex_lock(&l);
		if(buffer==0)
		{
		buffer=1;
		printf("producer consumed 1 item\n");
		}
		pthread_mutex_unlock(&l);
	}
}

void *cons()
{
	while(1)
	{
		pthread_mutex+lock(&l);
		if(buffer==1)
		{
		buffer=0;printf("Consumer consumed 1 item\n");
		}
		pthread_mutex_unlock(&l);
	}
}
int main()
{

}

}
