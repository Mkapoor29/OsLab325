//program to create file with null attributes
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *func()
{
    printf("In thread func\n");
    pthread_exit("Exit thread func\n");
}
int main()
{
    pthread_t t;
    printf("in main thread");
    pthread_create(&t,NULL,func,NULL);
    pthread_join(t,NULL);
    printf("thread completed\n");
}
