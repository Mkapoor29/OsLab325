#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pid1, pid2;
	//create process 1
	pid1=fork();
	if(pid1==0)
	{
	//this is process2
	printf("child process1 id is %d and parent id is %d\n",getpid(),getppid());
	//create process 3
	pid2=fork();
	if(pid2==0)
	{printf("Child process2 id is %d and parent id is %d\n",getpid(),getppid());
	}
	}
	else
	{
	//this is process1
	printf("parent process: %d\n",getpid());
	}
}
