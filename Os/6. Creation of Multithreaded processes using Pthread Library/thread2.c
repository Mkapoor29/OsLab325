// program to pass argument in thread func
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *func(void *i)
{
    int *p=(int *)i;
    printf("In thread func\n");
    printf("%d\n",*p);
    return NULL;
}
int main()
{
    pthread_t t1;
    int i = 10;
    pthread_create(&t1,NULL,func,(void *)&i);
    pthread_join(t1,NULL);
    exit(0);
}
