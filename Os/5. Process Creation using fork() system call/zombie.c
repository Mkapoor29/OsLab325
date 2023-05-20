#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int main()
{
	pid_t a;
	a = fork();
	if(a>0)
	{
		sleep(20);
		printf("pid of parent  is: %d\n", getpid());
	}
	else
	{
		printf("pid of child is: %d\n",getpid());
	}
}
