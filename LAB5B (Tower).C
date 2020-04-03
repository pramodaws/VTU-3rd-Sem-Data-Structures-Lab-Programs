#include<stdio.h>
#include<conio.h>
#include<math.h>

void tower(int n,int source,int temp,int dest)
{
 if(n==0)
  return;
 tower(n-1,source,dest,temp);
 printf("\nMove disk%d from %c to %c",n,source,dest);
 tower(n-1,temp,source,dest);
}
void main()
{
 int n;
 clrscr();
 printf("\nEnter no. of disk ");
 scanf("%d",&n);
 tower(n,'A','B','C');
 printf("\nTotal no. of Moves=%d",(int)pow(2,n)-1);
 getch();
}