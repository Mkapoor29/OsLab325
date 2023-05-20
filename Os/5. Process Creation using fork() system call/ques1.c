#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
int main()
{
	int pid;
	pid = getpid();
	for(int i = 0;i<2;i++)
	{
		if(fork()==0)
		{
			printf("Child process id is: %d\n", getpid());
			printf("parent process id is: %d\n", getppid());
		}
	}
	return 0;
}
