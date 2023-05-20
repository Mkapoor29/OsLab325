
// wap to concatentae two strings
#include<stdio.h>
#include<pthread.h>
#include<string.h>

//max_strings, max length of strings
char strings[10][100];
char result[1000]; 

void *myCon()
{
    
    int i,j,k = 0;
    for(i = 0; i<10;i++)
    {
        for(j=0;strings[i][j]!='\0';j++)
        {
            result[k++] = strings[i][j];
        }
    }
    result[k] ='\0';
    pthread_exit(NULL);
}
int main()
{
    printf("Enter number of strings you wish to enter: ");
    int num; scanf("%d",&num);

    for(int i = 0;i<num;i++)
    {
        scanf("%s",strings[i]);
    }

    void *ret;
    pthread_t t1;
    pthread_create(&t1,NULL,myCon,NULL);
    pthread_join(t1,&ret);
    printf("Concatenated string is: %s\n",result);
    return 0;
}
