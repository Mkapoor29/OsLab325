 #include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int pid;
	pid = getpid();
	printf("current process pid is %d\n",pid);
	printf("forking child process: \n");
	pid = fork();
	if(pid==0)
	{
		printf("Child process id: %d and its parent's process's id: %d \n ",getpid(),getppid());
	}
	else
	{
		printf("parent process id is: %d\n",getpid());
	}
	return 0;
}
