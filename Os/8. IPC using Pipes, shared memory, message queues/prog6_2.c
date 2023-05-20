#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main()
{
	int res,n;
	res=open("fifo",O_WRONLY);
	write(res,"hello\n",6);
	printf("Sender process id %d send the data\n",getpid());
	
}
