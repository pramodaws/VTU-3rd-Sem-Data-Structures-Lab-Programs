#include<stdio.h>
#include<conio.h>
#define MALLOC(p,n,type) (p=(type*)malloc(n*sizeof(type)))

typedef struct BST
{
 int info;
 struct BST *Llink;
 struct BST *Rlink;
}NODE;

NODE* create_tree(NODE *root,int data)
{
 if(root==NULL)
 {
  NODE *pnew;
  MALLOC(pnew,1,NODE);
  pnew->info=data;
  pnew->Llink=NULL;
  pnew->Rlink=NULL;
  return pnew;
 }
 else
  {
   if(data<root->info)
    root->Llink=create_tree(root->Llink,data);

  else if(data>root->info)
   root->Rlink=create_tree(root->Rlink,data);
  }
  return root;
 }

void inorder(NODE *root)
{
 if(root==NULL) return;
 inorder(root->Llink);
 printf("%d-",root->info);
 inorder(root->Rlink);
}

void preorder(NODE *root)
{
 if(root==NULL) return;
 printf("%d-",root->info);
 preorder(root->Llink);
 preorder(root->Rlink);
}

void postorder(NODE *root)
{
 if(root==NULL) return;
 postorder(root->Llink);
 postorder(root->Rlink);
 printf("%d-",root->info);
}

NODE* search(NODE *root,int data)

{
 if(root==NULL)
 printf("\nElement not found");

 else if(data<root->info)
    root->Llink=search(root->Llink,data);

  else if(data>root->info)
   root->Rlink=search(root->Rlink,data);
   else
   printf("\nElement found");
  return root;
 }

NODE* FindMin(NODE *node)
{
 if(node==NULL)
  return NULL;
 if(node->Llink)
  return FindMin(node->Llink);
  else
   return node;
 }

NODE* del(NODE *node,int data)
{
 NODE *temp;
 if(node==NULL)
  printf("\nElement not found");
 else if(data<node->info)
  node->Llink=del(node->Llink,data);
 else if(data>node->info)
  node->Rlink=del(node->Rlink,data);

 else
  {
   if(node->Rlink&&node->Llink)
   {
    temp=FindMin(node->Rlink);
    node->info=temp->info;
    node->Rlink=del(node->Rlink,temp->info);
   }
   else
    {
     temp=node;
     if(node->Llink==NULL)
      node=node->Rlink;
     else if(node->Rlink==NULL)
      node=node->Llink;
     free(temp);
    }
   }
    return node;

}
void main()
{
 NODE *root=NULL;
 int i,data,n,ch=0;
 clrscr();
 do
{
 printf("\n1.Create BST  2.Traverse  3.Search  4.Delete  5.EXIT ");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:{
	 printf("\nEnter the no. of nodes in tree ");
	 scanf("%d",&n);
	 printf("\nEnter the Data ");
	 for(i=0;i<n;i++)
	 {
	  scanf("%d",&data);
	  root=create_tree(root,data);
	 }
         }break;
 case 2:{

	 printf("\nPreorder :");
	 preorder(root);
	 printf("\nPostorder :");
	 postorder(root);
	 printf("\nInorder :");
	 inorder(root);
         }break;
  case 3:{

	 printf("\nEnter the element to searched ");
	 scanf("%d",&data);
	root=search(root,data);
	} break;
 case 4:{
	 printf("\nEnter the element to Deleted ");
	 scanf("%d",&data);
	root=del(root,data);
         }break;
  case 5: exit();
 }

 getch();
 }while(ch!=5);
 }

