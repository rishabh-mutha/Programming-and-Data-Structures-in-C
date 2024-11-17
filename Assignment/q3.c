#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *lcptr;
struct node *rcptr;
};
struct node *rptr=NULL;


void postorder(struct node *ptr)
{	 
	if(ptr!=NULL)
	{     
		postorder(ptr->lcptr);
		postorder(ptr->rcptr);	
		printf("%d ",ptr->data);
	}
}
struct node *newnode(int data) 
{
   struct node *new_node =malloc(sizeof(struct node));
   new_node->data = data;
   new_node->lcptr = NULL;
   new_node->rcptr = NULL;
   return new_node;
}
struct node *tree(int pre[],int *preIndex,int Rless,int Rmore,int size)
{
   if(*preIndex>=size|| Rless>Rmore)
     return NULL;
  
  struct node* rptr=newnode(pre[*preIndex]);//making 1st node node as root
  *preIndex=*preIndex+1;
  
  if(Rless==Rmore)
    return rptr;
  
  int i;
  for(i=Rless;i<=Rmore;i++)
    if(pre[i]>rptr->data)
      break;
      
 rptr->lcptr=tree(pre,preIndex,*preIndex,i-1,size);// with index divide into left and right sub trees
 rptr->rcptr=tree(pre,preIndex,i,Rmore,size);
 
 return rptr;
}
struct node *buildtree(int pre[],int size)
{
   int preIndex=0;
   return tree(pre,&preIndex,0,size-1,size);
}
int main()
{
   int size;
   printf("enter no. of elements\n");
   scanf("%d",&size);
int pre[size];
	printf("enter preorder sequence\n");
   for(int i=0;i<size;i++)
     scanf("%d",&pre[i]);
   
   struct node *rptr=buildtree(pre,size);
   printf("post order is\n");
   postorder(rptr);
   return 0;
}



