#include <stdio.h> 
int f(int x, int *py, int **ppz)
{ 
int y,z;
**ppz += 1; z = **ppz;
*py+=2; y=*py; x+=3;
return x+y+z;

}



void main()

{ 
int c, *b, **a, result;
c=4; b=&c;
a=&b;
result = f(c,b,a); 
printf("%d \n ",result);

}
