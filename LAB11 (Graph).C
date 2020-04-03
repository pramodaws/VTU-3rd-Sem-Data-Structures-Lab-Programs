#include<stdio.h>
#include<conio.h>

int a[10][10],n,m,i,j,source,s[10],b[10];
int visited[10]={0};

void create()
{
 printf("\nEnter the no. of vertices of the digraph : ");
 scanf("%d",&n);
 printf("\nEnter the adjacency matrix of the graph: ");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   scanf("%d",&a[i][j]);
}

void bfs()
{
 int q[10],u,front=0,rear=-1;
 printf("\nEnter the source vertex to find other nodes reachable or not: ");
 scanf("%d",&source);
 q[++rear]=source;
 visited[source]=1;
 printf("\nThe reachable Vertices are: ");
 while(front<=rear)
 {
  u=q[front++];
  for(i=1;i<=n;i++)
  {
   if(a[u][i]==1&&visited[i]==0)
   {
     q[++rear]=i;
     visited[i]=1;
     printf("\n%d",i);
   }
  }
 }
}

void dfs(int source)
{
 int v,top=-1;
 s[++top]=1;
 b[source]=1;
 for(v=1;v<=n;v++)
 {
  if(a[source][v]==1&&b[v]==0)
  {
   printf("\n%d->%d",source,v);
   dfs(v);
  }
 }
}

void main()
{
 int ch;
 clrscr();
 while(1)
 {
  printf("\n1.Create  2.BFS  3.Check Graph Connected or Not  4.EXIT ");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:create(); break;
   case 2:{
	bfs();
	for(i=1;i<=n;i++)
	if(visited[i]==0)
	printf("\nThe vertex that is not reachable %d",i);
          }break;
   case 3:{
	printf("\nEnter the Source vertex to find the connectivity: ");
	scanf("%d",&source);
	m=1;
	dfs(source);
	for(i=1;i<=n;i++)
	{
	 if(b[i]==0)
	 m=0;
	}
	if(m==1)
	printf("\nGraph is Connected");
	else
	 printf("\nGraph is not connected");
           }break;
   case 4:exit();
   }
  }
 }