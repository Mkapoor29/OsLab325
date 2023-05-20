#include <stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int rd,wr;
    char buff[10];
    buff[10]='\0';
    rd = read(0,buff,6);
    printf("number of bytes reas are: %d\n",rd);
    write(1,buff,6);
    printf("\nnumber of bytes written are: %d\n",wr);
    return 0;
}