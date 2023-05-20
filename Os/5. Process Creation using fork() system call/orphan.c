#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
int pid;
pid = getpid();
printf("Current process id is %d\n",getpid());
printf("forking a child process\n");
pid = fork();
if(pid==0)
{
printf("Child is sleeping\n");
sleep(5);
}
else
{
printf("parent process completed\n");
}
}
