//creating named pipes
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
	int res;
	res=mkfifo("fifo",0777);
	if(res==0)
		printf("named pipe created successfully\n");
}
