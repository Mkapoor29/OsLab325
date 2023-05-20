#include<stdio.h>
#include<pthread.h>
void *fact(void *temp1)
{
    int *i = (int *)temp1;
    int fact=1;
    for(int a = 1;a<=*i;a++)
    {
        fact = fact * a;
    }
    printf("fact is %d: \n",fact);
}
void *even_odd(void *temp2)
{
    int *i = (int *)temp2;
    if((*i)%2==0)
    {
        printf("even\n");
    }
    else printf("odd\n");
}
int main()
{
    pthread_t t1,t2;
    int num ; scanf("%d",&num);
    pthread_create(&t1,NULL,fact,(void *)&num);
    pthread_create(&t2,NULL,even_odd,(void *)&num);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;

}
