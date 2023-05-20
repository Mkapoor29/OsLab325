//program to return a value from thread function
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
struct sum 
{
	int num1;
	int num2;
	int *add;
};
void *sumFunc(void *a)
{
	struct sum *s = (struct sum*)a;
	scanf("%d",&s->num1);scanf("%d",&s->num2);
	*(s->add) =  (s->num1+s->num2);
	pthread_exit(s->add);
}

int main()
{
	pthread_t t1;
	struct sum args;
	void *a;
	args.num1 = 5;
	args.num2 = 5;
	pthread_create(&t1,NULL,&sumFunc,&args);
	pthread_join(t1,a);
	return 0;
}
