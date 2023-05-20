#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
int main()
{
	int fd[2],n;
	char buffer[100];
	pipe(fd);
	pid_t  p=fork();
	if(p>0)
	{
		printf("parent passing to child\n");
		write(fd[1],"hello\n",6);
	}
	else
	{
		printf("child printing recieved value\n");
		n = read(fd[0],buffer,100);
		write(1,buffer,n);
	}
}
