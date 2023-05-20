#include <stdio.h>
#include<direct.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
    int check;
    char *dir = "OsDir";
    check = mkdir(dir);
    if(!check)
    {
        printf("directory created");
    }
    else
    {
        printf("directory exists");
    }
    system("dir");     // this lists the content where the program is stored.
    return 0;
}