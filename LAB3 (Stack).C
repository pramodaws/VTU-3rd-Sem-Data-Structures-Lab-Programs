#include<stdio.h>
#include<conio.h>
#define MAX 4

int stack[MAX];
int top=-1,ele,i,status=0;

void push()
{
 printf("\nEnter the value to be pushed ");
 scanf("%d",&ele);

 if(top==MAX-1)
  printf("\nStack overflow");

 else
  {
   ++top;
   stack[top]=ele;
   status=status+1;
  }
}

int pop()
{
 if(top==-1)
  printf("\nStack underflow");

  else
   {
    ele=stack[top];
    top=top-1;

    status=status-1;
    return ele;
   }
}

void display()
{
 printf("\nElements in Stack ");
 for(i=top;i>=0;i--)
 printf("\nstack[%d]=%d\n",i,stack[i]);
}

void palindrome()
{
int count=0;
 for(i=0;i<top;i++)
 {
  if(stack[i]==pop())
  count++;
 }
  if(count==top)
   printf("Stack is a Palindrome");
  else
   printf("Stack is not a Palindrome");
}



void main()
{
 int ch=0;
 clrscr();
 do
 {
  printf("\n1.push\t2.pop\t3.display\t4.Pailndrome\t5.Exit ");
  scanf("%d",&ch);

  switch(ch)
   {
       case 1:push();break;
       case 2:ele=pop(); printf("Element poped=%d",ele);break;
       case 3:display();break;
       case 4:palindrome();
       case 5:exit();
   }
  }
 while(ch!=5);
 getch();
}

