#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int res, n;
	char buff[100];
	res=open("fifo",O_RDONLY);
	n = read(res,buff,100);
	printf("Reader process %d started\n",getpid());
	printf("Data recieved by procesd %d  is %s\n",getpid(),buff);
}

