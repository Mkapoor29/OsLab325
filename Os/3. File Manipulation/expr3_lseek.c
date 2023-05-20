#include <stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int rd,wr;
    char buff[50];
    int f = open("seek.txt",O_CREAT|O_WRONLY,0777);
    wr = write(f,"hello,i am muskan",18);
    rd = read(f,buff,wr);
    printf("%d",rd);
    return 0;
}