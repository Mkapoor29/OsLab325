#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<fcntl.h>

// read from console and print on console
/*
int main()
{
    int nread;
    char buff[100];
    nread = read(0,buff,100);
    printf("\n%d",nread);
    if(nread== -1)
    {
        write(2,"read error occurs",16);
    }
    if(nread!=(write(1,buff,100)))
    {
        write(2,"succesfull read write",20);
    }
    return 0;
// }
*/


/*
int main()
{
    char buffer[6];
    int nread;
    nread = read(0, buffer, 6);
    if (nread == -1)
        write(2, "A read error has occurred\n", 26);
    if ((write(1, buffer, nread)) != nread)
        write(2, "A write error has occurred\n", 27);    // prints when data is not completly read.

    exit(0);
}

*/


// read from file
int main()
{
    int fd;
    char buff[22];
    fd = open("newfile",O_RDONLY);
    if(fd<0)
    {
        perror("open"); return 1;
    }
    if(read(fd,buff,22)!=22)
    {
        perror("read"); return 1;
    }
    buff[22] = '\0';
    printf("read: %s\n",buff);
    close(fd);
    return 0;
}