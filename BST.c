	#include<stdio.h>
	#include<stdlib.h>
	struct Tnode
	{
		int data;
		struct Tnode *lcptr;
		struct Tnode *rcptr;
	};
	struct Tnode *rptr=NULL;
	void insert(int x)
	{
	   struct Tnode *tmp=malloc(sizeof(struct Tnode));
		tmp->data=x;
		tmp->lcptr=NULL;
	   tmp->rcptr=NULL;
	   if(rptr==NULL)
		{	
			rptr=tmp;
		}
		else
		{
			struct Tnode *ptr=rptr;
			struct Tnode *pptr=NULL;
		  while(ptr!=NULL)
			{
				pptr=ptr;
		     if(x<ptr->data)
				{
					ptr=ptr->lcptr;	
				}
				else
				{
					ptr=ptr->rcptr;
				}
			}
			if(x<pptr->data)
				pptr->lcptr=tmp;
			else
				pptr->rcptr=tmp;	
		}	

	}
	void Inorder(struct Tnode *ptr)
	{
		
		if (rptr==NULL)
     { printf("BST is Empty\n");return; }

		if(ptr!=NULL)
		{
			Inorder(ptr->lcptr);
			printf("%d ",ptr->data);
			Inorder(ptr->rcptr);
		}
	}
	int delete(int x)
	{
		int b=-666;	
	   struct Tnode *ptmp=NULL;
		struct Tnode *ptr=rptr;
		struct Tnode *pptr=NULL;	
		while(ptr!=NULL && ptr->data!=x)
		{
			pptr=ptr;		
			if(x>=ptr->data)
				ptr=ptr->rcptr;	
			else 
				ptr=ptr->lcptr;
		}	
		if(ptr==NULL)
		{
			printf("\n Deletion Fails");
		}
		else if(rptr->lcptr==NULL && rptr->rcptr==NULL)
		{
			b=rptr->data;		
			rptr=NULL;	
		}
		else if(ptr->lcptr==NULL && ptr->rcptr==NULL) //Case 1:Delete Leaf Node
		{
			b=ptr->data;		
			if(x<pptr->data)
				pptr->lcptr=NULL;
			else
				pptr->rcptr=NULL;
		}
		else if(ptr->lcptr==NULL && ptr->rcptr!=NULL || ptr->lcptr!=NULL && ptr->rcptr==NULL)
		{
			b=ptr->data;		
			if(x<pptr->data && ptr->lcptr!=NULL)
				pptr->lcptr=ptr->lcptr;		
			else if(x<pptr->data && ptr->lcptr==NULL)
				pptr->lcptr=ptr->rcptr;
			else if(x>=pptr->data && ptr->lcptr!=NULL)
				pptr->rcptr=ptr->lcptr;
			else
				pptr->rcptr=ptr->rcptr;   
		}
		else
		{		
			struct Tnode *tmp=ptr;
		  ptmp=tmp;		
			tmp=tmp->rcptr;
		  
			while(tmp->lcptr!=NULL)
			{
		     ptmp=tmp;
				tmp=tmp->lcptr;
			}
			b=ptr->data;		
			ptr->data=tmp->data;	
			

			//To delete suc node pointed to by tmp, and its parent is ptmp
		  
		   if(tmp->data < ptmp->data)
		     ptmp->lcptr=tmp->rcptr;
		   else
		    ptmp->rcptr=tmp->rcptr;

		}
		return b;
	}

	int min()
	{
     if (rptr==NULL)
     { printf("BST is Empty\n");return -666; }
	struct Tnode *tmp=rptr;
	while(tmp->lcptr!=NULL)

	tmp=tmp->lcptr;
	return tmp->data;

	}


	int max()
	{
    if (rptr==NULL)
     { printf("BST is Empty\n");return -666; }
 
	struct Tnode *tmp=rptr;
	while(tmp->rcptr!=NULL)

	tmp=tmp->rcptr;
	return tmp->data;

	}

	void Preorder(struct Tnode *ptr)
	{
	if (rptr==NULL)
     { printf("BST is Empty\n");return; }

		if(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			Preorder(ptr->lcptr);
			Preorder(ptr->rcptr);
		}
	}


	void main()
	{
	printf("This is a BST\n\nTo insert, press 1\nTo delete, press 2\nTo print Inorder, press 3\nTo print Preorder, press 4\nTo print maximum element, press 5\nTo print minimum element, press 6\n\n");
	   int x,y;
	   label: printf("enter your choice\n");
	   scanf("%d",&x);
		 
		if (x==1) 
		{ printf("\n");
		  printf("enter the number to be inserted\n");
		  scanf("%d",&y);
		  insert(y);printf("\n");}
		else if (x==2)
		 {printf("\n");
		  printf("enter the number to be deleted\n");
		  scanf("%d",&y);
		  delete(y);printf("\n");}
		else if (x==3) 
		{printf("\ninorder traversal:"); Inorder(rptr);printf("\n");}
		else if(x==4)
		 {printf("\npreorder traversal:"); Preorder(rptr);printf("\n");}
		else if(x==5)
		 printf("the maximum element in the BST is %d\n",max());
		else if(x==6)
		 printf("the minimum element in the BST is %d\n",min());

	goto label;	
	}

	
