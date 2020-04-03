#include<stdio.h>
#include<conio.h>

char str[100],res[100],pat[50],rep[50];
int ls=0,lp=0,lr=0;
int i=0,j=0,k=0;
void create()
{
 printf("\nEnter the string ");
 scanf("%s",str);
 for(i=0;str[i]!='\0';i++) ls++;

 printf("\nEnter pattern ");
 scanf("%s",pat);
 for(j=0;pat[j]!='\0';j++) lp++;

 printf("\nEnter string to replace ");
 scanf("%s",rep);
 for(k=0;rep[k]!='\0';k++) lr++;

}


void replace()
{
 int I=0,count=0,r=0;
 for(i=0;str[i]!='\0';)
  {
       I=i;
       count=0;
       for(j=0;pat[j]!='\0';j++,I++)
       {
        if(str[I]==pat[j])
        count++;
       }
       if(count==lp)
       {
        for(k=0;rep[k]!='\0';k++,r++)
        res[r]=rep[k];
        i=i+lp;
       }
       else
        {
         res[r++]=str[i];
         i++;
        }
   }

   res[r]='\0';
   printf("\nReplaced String %s",res);
   getch();
 }



void main()
{
 clrscr();

  create();
  replace();

}
