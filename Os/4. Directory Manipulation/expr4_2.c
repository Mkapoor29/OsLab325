#include<stdio.h>
#include<dirent.h>

// int main()
// {
//     DIR *d;

//     struct dirent *dir;
//     d = opendir(".");
//     // d = opendir("Os File");
//     if(d)
//     {
//         while((dir=readdir((d))) != NULL)
//         {
//             printf("%s\n", dir->d_name);
//         }
//         closedir(d);
//     }
//     return 0;
// 
int main()
{
    DIR *dp;
    struct dirent *dptr;
    dp = opendir(".");
    while((dptr=readdir(dp))!=NULL)
    {
        printf("%s\n",dptr->d_name);
        printf("%d\n",dptr->d_type);
        printf("%d\n",dptr->d_ino);
    }
    closedir(dp);
}