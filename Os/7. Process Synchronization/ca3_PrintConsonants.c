#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>
#include<string.h>
void *cons(void *args)
{
	char *a = (char *)args;
	char *result = (char*)malloc(100 *sizeof(char));
	int i = 0;
	while(a[i]!='\0')
	{
		if(a[i]=='a' || a[i]=='e'|| a[i]=='i' ||a[i] =='o' || a[i]=='u')
			continue;
		else
		result[i] = a[i];
		i++;
	}
	result[i] = '\0';
	return result;
}

void *pal(void *str1)
{
	char *a = (char *)str1;	
	int i = 0; int check = 1;
	int length = strlen(a);
	while(a[i]!='\0')
	{
		if(a[i]!=a[length-i-1])
			{printf("Not True\n");check =0; break;}
	}
	if(!check){printf("true");}
	pthread_exit(NULL);
}
int main()
{
	
	pthread_t t1,t2;
	char *a = "abcba";
	 pthread_create(&t1,NULL,pal,(void*)a);
	pthread_join(t1,NULL);
	exit(0);
}
	
