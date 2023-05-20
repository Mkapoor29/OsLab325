#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>

// to write to screen
/*
int main()
{
    int c = write(1,"hello",5);
    printf("\n%d",c);   
    return 0;
}
*/


// to write to file
int main()
{
    int fd;
    char buff[] ="writing into file\n";
    fd = open("newfile.txt",O_RDWR|O_CREAT,0666);
    if(fd<0)
    {
        perror("open"); return 1;
    }
    if(write(1,buff,17)!=17)
    {
        perror("write"); return 1;
    }
    close(fd);
    return 0;

}