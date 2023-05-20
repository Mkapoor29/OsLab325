#include <stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int a,b,c,d;
    char buff[10];
    a = open("append.txt",O_WRONLY|O_APPEND,777);
    printf("%d\n",a);
    b = read(0,buff,5);
    c = write(a,buff,b);
    return 0;
}