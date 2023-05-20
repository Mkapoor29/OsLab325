// pass array in a thread
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *arrFunc(void *arr)
{
    int *p = (int *)arr;
    for(int i = 0; i<10;i++)
    {
        printf("%d ",p[i]);
    }
    return NULL;
}
int main()
{
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    pthread_t t1;
    pthread_create(&t1,NULL,arrFunc,(void *)arr);
    pthread_join(t1,NULL);
    return 0;
}
/*
// pass structure to array
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

struct thread_args
{
    int arg1;
    int arg2;
    char *arg3;
};
void *myFunc(void *temp)
{
    struct thread_args *myargs = (struct thread_args *)temp;
    printf("arg1= %d\n",myargs->arg1);
    printf("arg2= %d\n",myargs->arg2);
    printf("arg3= %s\n",myargs->arg3);

    return NULL;
}

int main()
{
    
    pthread_t t1;
    struct myargs args;
    args.arg1 = 10; args.arg2 = 11; args->arg3 = "10+11";
    pthread_create(&t1,NULL,myFunc,void,args);
    pthread_join(t1,NULL);
    return 0;
}*/
