#include<stdio.h>
#include<unistd.h>
int main()
{
int a,b;
a=access("1.c",X_OK); //to check real users permission
printf("File handling in linux\n"); //X_OK for executable
if(a==0)
 perror("access"); //explains error code
else
 perror("access:");
return 0;
}
