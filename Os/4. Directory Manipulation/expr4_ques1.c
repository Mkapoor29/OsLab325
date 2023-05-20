// wap to create a directory in desktop and create a file inside directory and then list contents of dir.

#include <stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main()
{
    int check;
    check = mkdir("C:\\Users\\kapoo\\OneDrive\\Desktop\\hello");
    if(!check)
    {
        printf("directory created");
    }
    else
    {
        printf("error in creating dir");
        return 1;
    }
    FILE *fptr = fopen("C:\\Users\\kapoo\\OneDrive\\Desktop\\hello\\newfile.txt","w");
    if(fptr==NULL)
    {
        printf("error in creating file");
        return 1;
    }
    fprintf(fptr,"hello world/n how are you?");
    fclose(fptr);

    DIR *dir = opendir("C:\\Users\\kapoo\\OneDrive\\Desktop\\hello");

    mkdir("C:\\Users\\kapoo\\OneDrive\\Desktop\\hello\\hello1");

    struct dirent *dp;

    while((dp = readdir(dir))!= NULL)
    {
       if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){

        printf("%s          " ,dp->d_name);
        // printf("%s\n" ,dp->d_type);
        }
    }

    closedir(dir);

    return 0;
}
