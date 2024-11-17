#include <stdio.h> 
#include <stdlib.h> 
  
struct node { 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  
int search(int arr[], int strt, int end, int value); 
struct node* newNode(int data); 
  

struct node* buildTree(int in[], int pre[], int inStrt, int inEnd) 
{ 
    static int preIndex = 0; 
  
    if (inStrt > inEnd) 
        return NULL; 
  
    /* Pick current node from Preorder traversal using preIndex 
    and increment preIndex */
    struct node* tNode = newNode(pre[preIndex++]); 
  
    /* If this node has no children then return */
    if (inStrt == inEnd) 
        return tNode; 
  
    /* Else find the index of this node in Inorder traversal */
    int inIndex = search(in, inStrt, inEnd, tNode->data); 
  
    /* Using index in Inorder traversal, construct left and 
     right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1); 
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd); 
  
    return tNode; 
} 
  
/* UTILITY FUNCTIONS */

int search(int arr[], int strt, int end, int value) 
{ 
    int i; 
    for (i = strt; i <= end; i++) { 
        if (arr[i] == value) 
            return i; 
    } 
} 
  

struct node* newNode(int data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 
  
void printPostorder(struct node* node) 
{ 
    if (node == NULL) 
        return; 
  
    printPostorder(node->left); 
    printPostorder(node->right); 
    printf("%d ", node->data);
} 
  
void main() 
{   
    int len;
    printf("enter no of elements in tree\n");
    scanf("%d",&len);
    int in[len],pre[len];
    printf("enter inorder traversal\n");
for(int i=0; i<len ; i++)    
scanf("%d",&in[i]);
    
    printf("enter preorder traversal\n");
for(int i=0; i<len ; i++)    
scanf("%d",&pre[i]);
    
    struct node* root = buildTree(in, pre, 0, len - 1); 
  

    printf("Postorder traversal of the constructed tree is \n"); 
    printPostorder(root); 
    
} 
