#include <stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int a,b,c;
    char buff[20];
    a = open("file.txt",O_WRONLY,0777);
    b = read(0,buff,20);
    c = write(a,buff,b);
    
    return 0;
}