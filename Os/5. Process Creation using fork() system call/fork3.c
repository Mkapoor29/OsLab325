#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1,pid2,pid3,pid4,pid5,pid6,pid7;

    pid2=fork();
    if(pid2==0)
    {
        printf("P2 %d parent %d\n",getpid(),getppid());
        pid3=fork();
        if(pid3==0)
        {
            printf("P3 %d parent %d\n",getpid(),getppid());
            pid4=fork();
            if(pid4==0)
            {
                printf("P4 %d parent %d\n",getpid(),getppid());
                exit(0);
            }
            else
            {
                wait(NULL);
                exit(0);
            }
        }
        else
        {
            wait(NULL);
            exit(0);
        }
    }
    pid1=getpid();
    printf("P1 %d\n",pid1);
    pid5=fork();
    if(pid5==0)
    {
        printf("P5 %d parent %d\n",getpid(),getppid());
        pid6=fork();
        if(pid6==0)
        {
            printf("P6 %d parent %d\n",getpid(),getppid());
            pid7=fork();
            if(pid7==0)
            {
                printf("P7 %d parent %d\n",getpid(),getppid());
                exit(0);
            }
            else
            {
                wait(NULL);
                exit(0);
            }
        }
        else
        {
            wait(NULL);
            exit(0);
        }
    }
    wait(NULL);
    wait(NULL);
    exit(0);

}



