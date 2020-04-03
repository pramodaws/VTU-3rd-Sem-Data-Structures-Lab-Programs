#include<stdio.h>
#include<alloc.h>
#include<conio.h>

#define MALLOC(p,n,type)(p=(type*)malloc(n*sizeof(type)))

typedef struct node
{
 char usn[10];
 char name[30];
 char branch[5];
 int sem;
 char phno[10];
 int info;
 struct node *link;
}NODE;

NODE *header;
void create_header()
{
 MALLOC(header,1,NODE);
 header->info=0;
}

void insert_front()
{
 NODE *pnew;
 MALLOC(pnew,1,NODE);
 printf("\nEnter the usn,name,branch,sem,phone no.");
 scanf("%s %s %s %d %s",&pnew->usn,&pnew->name,&pnew->branch,&pnew->sem,&pnew->phno);
 pnew->link=header->link;
 header->link=pnew;
 header->info=header->info+1;
}

void insert_rear()
{
 int i,n;
 NODE *pnew,*dcur;
 dcur=header;
 n=header->info;
 MALLOC(pnew,1,NODE);
 pnew->link=NULL;
 printf("\nEnter the usn,name,branch,sem,phone no.");
 scanf("%s %s %s %d %s",&pnew->usn,&pnew->name,&pnew->branch,&pnew->sem,&pnew->phno);

 for(i=1;i<=n;i++)
 dcur=dcur->link;

 dcur->link=pnew;
 header->info=header->info+1;
}

void display()
{
 NODE *dcur;

 int n,i;
 n=header->info;
 dcur=header->link;
 printf("\n Records are : \n");
 for(i=1;i<=n;i++)
 {
 printf("[%s %s %s %d %s]->",dcur->usn,dcur->name,dcur->branch,dcur->sem,dcur->phno);

 dcur=dcur->link;
}
}


void delete_front()
{
 NODE *dcur;
 int n,i;
 n=header->info;
 if(n==0)
 printf("Can't be Deleted");
 else if(n==1)
{
 dcur=header->link;
 printf("\Record deleted is [%s %s %s %d %s]",dcur->usn,dcur->name,dcur->branch,dcur->sem,dcur->phno);
 header->link=NULL;
 header->info=0;
 free(dcur);
}
 else
 {
 NODE *dcur;
 dcur=header->link;
  printf("\Record deleted is [%s %s %s %d %s]",dcur->usn,dcur->name,dcur->branch,dcur->sem,dcur->phno);

 header->link=dcur->link;
 header->info=header->info-1;
 free(dcur);
 }
}
void delete_rear()
{
NODE *dcur,*pcur;
int i,n;
n=header->info;
dcur=header->link;
pcur=header;
for(i=1;i<n;i++)
{
 pcur=dcur;
 dcur=dcur->link;
}
  printf("\Record deleted is [%s %s %s %d %s]",dcur->usn,dcur->name,dcur->branch,dcur->sem,dcur->phno);

header->info=header->info-1;
free(dcur);
}

void length_list()
{
int count=0;
NODE *cur;
cur=header->link;
while(cur!=NULL)
{
 count++;
 cur=cur->link;
}
printf("\nNo. of nodes in the list =%d",count);
}


void main()
{
 int option;
 int ch=1,n,i;
 clrscr();
do
{
printf("\nPress 1. Create 2.Count 3.insert_rear  4.Delete_rear 5.insert_front \n 6.Delete_front 7.Stack 8. Queue 9.Display 10. Exit");

scanf("%d",&option);
switch(option)
{
case 1:create_header();break;
case 2: length_list();break;
case 3: insert_rear();  break;
case 4: delete_rear();   break;
case 5: insert_front();  break;
case 6: delete_front();  break;
case 7: {
             printf("Stack push & pop ");
             insert_front();
             display();
             delete_front();
             display();
          } break;
  case 8 :{
           printf("Queue insert and Delete");
             insert_rear();
             display();
             delete_front();
             display();
          } break;

case 9:display();break;
case 10:exit();
}
}while(option!=10);
 getch();

}
