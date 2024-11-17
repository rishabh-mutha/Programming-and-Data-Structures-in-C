#include<stdio.h>
#include<stdlib.h>

struct node {
   int value;
   struct node *left, *right;
}node;

int search(int arr[],int start,int end,int value) {
    int i;
    for(i=start;i<=end;i++)
    {
        if(arr[i]==value)
            return i;
    }
}

struct node *getNewNode(int value) {
   struct node *new_node =malloc(sizeof(struct node));
   new_node->value = value;
   new_node->left = NULL;
   new_node->right = NULL;
   return new_node;
}

void postorder(struct node *ptr) 
{
    if(ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ",ptr->value);
    }
}

struct node* constructTree(int inorder[],int preorder[],int inorder_start,int inorder_end)
{
    static int preorder_idx = 0;
    if(inorder_start > inorder_end)
        return NULL;

    struct node *tree_node = getNewNode(preorder[preorder_idx++]);
    if(inorder_start == inorder_end)
        return tree_node;
    int inorder_idx = search(inorder,inorder_start,inorder_end,tree_node->value);
    
    tree_node->left = constructTree(inorder,preorder,inorder_start,inorder_idx-1);
    tree_node->right = constructTree(inorder,preorder,inorder_idx+1,inorder_end);
    return tree_node;
}

int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int inorder[n];
    int preorder[n];
    printf("Enter the inorder sequence : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&inorder[i]);
    }
    printf("Enter the preorder sequence : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&preorder[i]);
    }
    struct node *root = constructTree(inorder, preorder, 0,n-1);
    printf("The postorder traversal of the tree is : \n");
    postorder(root);
    printf("\n");
}