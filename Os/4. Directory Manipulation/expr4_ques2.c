// wap to copy contents of one directory in a newly created directory.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
// int main()
// {
//     // create new dir;
//     char *d = "C:\\Users\\kapoo\\OneDrive\\Desktop\\bye";
//     int check;
//     check = mkdir(d);
//     if(!check)
//     {
//         printf("error in creating dir");
//         return 1;
//     }
//     // open source dir
//     DIR *dr = opendir("C:\\Users\\kapoo\\OneDrive\\Desktop\\hello");
//     if(dr==NULL)
//     {
//         printf("error in opening source dir");
//         return 1;
//     }

//     int fd; char buff[100];
//     struct dirent *dptr;
//     while((dptr = readdir(dr))!=NULL)
//     {
//         char s_path[100] = "C:\\Users\\kapoo\\OneDrive\\Desktop\\hello\\";
//         char d_path[100] = "C:\\Users\\kapoo\\OneDrive\\Desktop\\bye\\";

//         char file[100] = "";

//         strcat(file,dptr->d_name);

//         strcat(s_path,file);
//         strcat(d_path,file);

//         fd = open(s_path,O_RDONLY,777);
//         int fileLen = lseek(fd,0,SEEK_END);
//         lseek(fd,0,0);
//         read(fd,buff,fileLen);
//         close(fd);

//         fd = open(d_path,O_CREAT|O_WRONLY);
//         write(fd,buff,fileLen);
//         close(fd);

//         printf("%s\n",dptr->d_name);

//     }
//     // close(dr);
//     dr = opendir("C:\\Users\\kapoo\\OneDrive\\Desktop\\bye");
//     while((dptr=readdir(dr))!=NULL)
//     {
//         printf("%s\n",dptr->d_name);
//     }

// }
int main()
{
    int check;
    char *s_path = "C:\\Users\\kapoo\\OneDrive\\Desktop\\hello";
    check = mkdir(s_path);
    if (check)
    {
        printf("error in creating dir");
        return 1;
    }
    FILE *fptr;
    fptr = fopen("C:\\Users\\kapoo\\OneDrive\\Desktop\\hello\\newFile.txt", "w");
    if (fptr == NULL)
    {
        printf("error creating file");
        return 1;
    }
    fprintf(fptr, "heelo world");
    fclose(fptr);

    int check1;
    char *d_path = "C:\\Users\\kapoo\\OneDrive\\Desktop\\bye";
    check1 = mkdir(d_path);
    if (check1)
    {
        printf("error in creating des dir");
     
    }

    DIR *dp = opendir(s_path);
    
    int fd;
    char buff[100];
    struct dirent *dptr;
    while ((dptr = readdir(dp)) != NULL)
    {

        char spath[100] = "C:\\Users\\kapoo\\OneDrive\\Desktop\\hello\\";
        char dpath[100] = "C:\\Users\\kapoo\\OneDrive\\Desktop\\bye\\";

        char file[100] = "";

        strcat(file, dptr->d_name);
        strcat(spath, file);
        strcat(dpath, file);

        int fd = open(spath, O_RDONLY);
        int flen = lseek(fd, 0, SEEK_END);
        lseek(fd, 0, 0);
        read(fd,buff,flen);

        close(fd);

        fd = open(dpath,O_CREAT|O_WRONLY);
        write(fd,buff,flen);

        close(fd);
        // printf("content in source file: \n");
        printf("%s  %s\n",dptr->d_name,dptr->d_type);

        
    }
    
    dp = opendir(d_path);
    while((dptr= readdir(dp))!=NULL)
    {
        printf("%s\n",dptr->d_name);
    }
    
}