#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MALLOC(p,n,type) (p=(type *) malloc(n*(sizeof(type))))
typedef struct polynode
{
 int cx,cy,cz;
 int px,py,pz;
 int info;
 struct polynode *link;
}NODE;

NODE *header;

void create_header()
{
 MALLOC(header,1,NODE);
 header->link=NULL;
 header->info=0;
}

void insert_poly()
{
 NODE *cur, *pnew;
 int i;
 MALLOC(pnew,1,NODE);
 printf("\nEnter the Co-efficient and Power of X,Y,Z ");
 scanf("%d %d %d %d %d %d",&pnew->cx,&pnew->px,&pnew->cy,&pnew->py,&pnew->cz,&pnew->pz);
 cur=header;
 for(i=0;i<header->info;i++)
 {
  cur=cur->link;
 }
 cur->link=pnew;
 header->info=header->info+1;
}


void display()
{
 int i;
 NODE *cur;

 cur=header->link;
 for(i=0;i<header->info;i++)
 {
  printf(" %dX^%d + %dY^%d + %dZ^%d ",cur->cx,cur->px,cur->cy,cur->py,cur->cz,cur->pz);
  cur=cur->link;
  printf("+");

 }
}
 void eval()
 {
  int x,y,z,res=0,res1=0,res2=0;
  NODE *p1,*p2;
  printf("\nEnter the values for X,Y,Z ");
  scanf("%d %d %d",&x,&y,&z);
  p1=header->link;
   printf(" \np1=%dX^%d + %dY^%d + %dZ^%d ",p1->cx,p1->px,p1->cy,p1->py,p1->cz,p1->pz);

  p2=header->link->link;
   printf(" \np2=%dX^%d + %dY^%d + %dZ^%d ",p2->cx,p2->px,p2->cy,p2->py,p2->cz,p2->pz);

  res1=p1->cx*pow(x,p1->px)+p1->cy*pow(y,p1->py)+p1->cz*pow(z,p1->pz);
  res2=p2->cx*pow(x,p2->px)+p2->cy*pow(y,p2->py)+p2->cz*pow(z,p2->pz);
  res=res1+res2;
  printf("\nResult = %d\n ",res);
 }

void addpoly()
{
  NODE *p1,*p2;
  int i;
  p1=header->link;
  p2=header->link->link;
  if(p1->px < p2->px)
  {
     printf("%d X^%d",p1->cx,p1->px);
     printf("+ %d X^%d",p2->cx,p2->px);

  }
  else if(p1->px > p2->px)
  {
     printf("%d X^%d",p2->cx,p2->px);
     printf("+ %d X^%d",p1->cx,p1->px);

  }
  else
  {
     printf("%d X^%d+ ",p1->cx+p2->cx,p1->px);
  }



  if(p1->py < p2->py)
  {
     printf("%d Y^%d",p1->cy,p1->py);
     printf("+ %d Y^%d",p2->cy,p2->py);

  }
  else if(p1->py > p2->py)
  {
     printf("%d Y^%d",p2->cy,p2->py);
     printf("+ %d Y^%d",p1->cy,p1->py);

  }
  else
  {
     printf("%d Y^%d+ ",p1->cy+p2->cy,p1->py);
  }


   if(p1->pz < p2->pz)
  {
     printf("%d Z^%d",p1->cz,p1->pz);
     printf("+ %d Z^%d",p2->cz,p2->pz);

  }
  else if(p1->pz > p2->pz)
  {
     printf("%d Z^%d",p2->cz,p2->pz);
     printf("+ %d Z^%d",p1->cz,p1->pz);

  }
  else
  {
     printf("%d Z^%d+ ",p1->cz+p2->cz,p1->pz);
  }



}

 void main()
 {
  clrscr();
  create_header();
   printf("\nThe Accepted Polynomials are: ");
  insert_poly();
//  display();
  insert_poly();
  display();
  eval();
  addpoly();
  getch();
 }