#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node NODE;
NODE *create()
{
	int x;
	NODE *newnode;
	newnode=(NODE *)malloc(sizeof(NODE));
	printf("Enter the data (or -1 to exit)");
	scanf("%d",&x);
	if(x==-1)
	{
		return 0;
	}
	newnode->data=x;
	printf("Enter the left child of %d",x);
	newnode->left=create();
	printf("Enter the right child of %d",x);
	newnode->right=create();
	return newnode;
}
void inorder(NODE *root)
{
	if(root==0)
	{
		return;
	}
	else
	{
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}
void preorder(NODE *root)
{
	if(root==0)
	{
		return;
	}
	else
	{
		printf("%d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(NODE *root)
{
	if(root==0)
	{
		return;
	}
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d",root->data);
	}
}

void main()
{
	NODE *root=0;
	root=create();
	printf("\nThe Inorder is:\n");
	inorder(root);
	printf("\nThe Preorder is:\n");
	preorder(root);
	printf("\nThe Postorder is:\n");
	postorder(root);
	
}
