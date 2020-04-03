#include<stdio.h>
#include<conio.h>
#define MAX 3

int rear=-1,front=0,count=0,i;
int CQ[MAX],item;

void cir_Q_insert()
{
 if(count==MAX)
  printf("\nCircular Queue Overflow");
 else
 {
  printf("\nEnter the item ");
  scanf("%d",&item);
  rear=(rear+1)%MAX;
  CQ[rear]=item;
  count++;
 }
}

void cir_Q_del()
{
 if(count==0)
  printf("\nCircular Queue Underflow");
 else
 {
   if(front>rear&&rear==MAX-1)
   { front=0; rear=-1; count=0; }
  else
  {
   item=CQ[front];
   printf("\nItem Deleted is %d", item);
   front=(front+1)%MAX;
   count--;
  }
 }
}
void display()
{
 int f=front, r=rear;
 printf("\nStatus =%d",count);
 for(i=1;i<=count;i++)
 {
  printf("\nCQ=%d ",CQ[f]);
  f=(f+1)%MAX;

 }
}

void main()
{
 int ch;
 clrscr();
 do
 {
  printf("\n1.insert\t2.delete\t3.display\t4.Exit ");
  scanf("%d",&ch);
  switch(ch)
     {
      case 1:  cir_Q_insert();
	  break;
      case 2:  cir_Q_del();
	  break;
      case 3: display();
	break;
      case 4: exit();
     }
 }  while(ch!=4);
 getch();
}