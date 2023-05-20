// wap using pthread to find length of string, where string is passed to thread function
#include<stdio.h>
#include<pthread.h>
#include<string.h>
 
void *myFun(void *i)
{
    char *str = (void *)i;
    int strLen = strlen(str);
    printf("The length of string is: %d",strLen);
    return NULL;
}

int main()
{
    char *str = "hello world";//11
    pthread_t t1;
    pthread_create(&t1,NULL,myFun,(void *)str);
    pthread_join(t1,NULL);
    return 0;
}

