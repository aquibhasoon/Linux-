#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main() 
{ 
int ans = access("ex1.txt",F_OK|R_OK|W_OK|X_OK);
if (ans==-1)
{
 perror("Response:");
}
else
 perror("Reason");

}
