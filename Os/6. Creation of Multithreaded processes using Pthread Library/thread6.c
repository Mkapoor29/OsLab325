
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
    struct thread_args args;
    args.arg1 = 10; args.arg2 = 11; args.arg3 = "10+11";
    pthread_create(&t1,NULL,myFunc,&args);
    pthread_join(t1,NULL);
    return 0;
}
