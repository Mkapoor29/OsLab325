// program to create and open a file using open system call
#include <stdio.h>
#include<fcntl.h>
int main()
{
    int n,m;
    n = open("newfile",O_RDONLY);
    printf("\n%d\n",n);
    m = open("newfile",O_CREAT|O_WRONLY,666);
    printf("%d\n",m);

    return 0;
}