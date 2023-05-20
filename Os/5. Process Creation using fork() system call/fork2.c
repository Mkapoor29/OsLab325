#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	fork();
	fork();
	fork();
	printf("process completed\n");
	return 0;
}
