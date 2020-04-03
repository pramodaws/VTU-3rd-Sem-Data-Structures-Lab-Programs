#include<stdio.h>
#include<conio.h>
#include<math.h>

double postfix_eval(double op1, double op2,char op)
{
 switch(op)
 {
  case '+': return(op1+op2);
  case '-': return(op1-op2);
  case '*': return(op1*op2);
  case '/': return(op1/op2);
  case '^': return(pow(op1,op2));
  default: return 0;
 }
}
void main()
{
 double op1,op2,res;
 char op;
 char postfix[30];
 char symbol;
 char stack[30];
 int top=-1;
 int i;
  clrscr();
  printf("\nEnter the Postfix ");
  scanf("%s",postfix);
  for(i=0;postfix[i]!='\0';i++)
  {
   symbol=postfix[i];
   if(isdigit(symbol))
    stack[++top]=symbol-'0';  //if symbol is a digit push to stack
   else
    {
     op=symbol;
     op2=stack[top--];
     op1=stack[top--];
     res=postfix_eval(op1,op2,op);
     stack[++top]=res;
    }
   }


    res=stack[top--];
    printf("\nThe final Result is %f",res);
    getch();
  }