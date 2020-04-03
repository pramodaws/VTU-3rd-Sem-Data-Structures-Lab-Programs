#include<stdio.h>
#include<conio.h>

#define MALLOC(p,n,type)(p=(type *)malloc(n*sizeof(type)))

typedef struct node
{
 int ssn;
 char name[20];
 char dept[20];
 char desg[20];
 int sal;
 int phno;
 int info;
 struct node *llink;
 struct node *rlink;
}NODE;

NODE *header,*cur,*fcur,*bcur,*prev,*pnew,*dcur;
int ch=0,n,i,j;
void create_header()
{
 MALLOC(header,1,NODE);
 header->info=0;
 header->llink=NULL;
 header->rlink=NULL;
}
void display_front()
{
 printf("\nFoward Display\n");
 for(i=1;i<=header->info;i++)
 {
 printf("[%d %s %s %s %d %d]->",fcur->ssn,fcur->name,fcur->dept,fcur->desg,fcur->sal,fcur->phno);
 fcur=fcur->rlink;
 }
}

void display_rear()
{
 printf("\nBackward Display\n");
 for(i=1;i<=header->info;i++)
 {
   printf("[%d %s %s %s %d %d]->",bcur->ssn,bcur->name,bcur->dept,bcur->desg,bcur->sal,bcur->phno);

  bcur=bcur->llink;
 }

}


void insert_front()
{
 MALLOC(pnew,1,NODE);
 printf("\nEnter ssn,Name,dept,desg,salary,phno info");
 scanf("%d %s %s %s %d %d",&pnew->ssn,pnew->name,pnew->dept,pnew->desg,&pnew->sal,&pnew->phno);

 prev=header;
 cur=prev->rlink;

 pnew->rlink=prev->rlink;
 pnew->llink=cur->llink;
 prev->rlink=pnew;
 cur->llink=pnew;

 header->info=header->info+1;
 fcur=header->rlink;

 bcur=header;
for(i=1;i<=header->info;i++)
 bcur=bcur->rlink;
}

void insert_rear()
{
   MALLOC(pnew,1,NODE);
   printf("\nEnter ssn,Name,dept,desg,salary,phno info");
   scanf("%d %s %s %s %d %d",&pnew->ssn,pnew->name,pnew->dept,pnew->desg,&pnew->sal,&pnew->phno);


   cur=header;
   n=header->info;

    for(i=1;i<=n;i++)
    {
      cur=cur->rlink;
    }
    pnew->llink=cur;
    cur->rlink=pnew;
    pnew->rlink=NULL;
    header->info=header->info+1;

    fcur=header->rlink;
    bcur=cur->rlink;
}

void del_front()
{

  dcur=header->rlink;
  header->rlink=dcur->rlink;
  dcur->rlink->llink=header;
  free(dcur);
  header->info=header->info-1;
   fcur=header->rlink;
   bcur=header;
   for(i=1;i<=header->info;i++)
   bcur=bcur->rlink;

}

void del_rear()
{
 prev=header;
 dcur=header->rlink;
 for(i=1;i<=header->info;i++)
 {
  prev=prev->rlink;
  dcur=dcur->rlink;
 }

 free(dcur);
 prev->rlink=NULL;
 header->info=header->info-1;
 fcur=header->rlink;
 bcur=prev->llink;
}



void main()
{
clrscr();
do
{
 printf("\n1.Create_header\t2.Insert_front\t3.Insert_rear\t4.Delete_front\t5.Delete_rear\t6.D_Q\t7.Display\t8.Exit");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:create_header();break;
  case 2:insert_front();break;
  case 3:insert_rear(); break;
  case 4:del_front();break;
  case 5:del_rear();break;
  case 6:{
          printf("\nInserting 3 nodes in front");
          insert_front();
          insert_front();
          insert_front();
          display_front();

         printf("\nDeleting 2 nodes from rear");


           del_rear();
           del_rear();
           display_rear();

         }break;
  case 7:{ display_front(); display_rear();} break;
  case 8:exit();
 }
}while(ch!=8);
 getch();
}


