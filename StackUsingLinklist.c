#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}soham;

soham *head,*temp;
int top=0;

void push(){
    if(top==5){
        printf("\nOverflow");
    }
    else{
    struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data \n");
	scanf("%d",&newnode->data);
	newnode->link=NULL;
        if(top==0){
            head=newnode;
            top=1;
        }
        else{
            temp=head;
            newnode->link=temp;
            head=newnode;
            top++;
        }
    }
}

void pop(){
    if(top==0)
        printf("\nUnderflow");
    else{
    soham *temp1;
    int num;
     if(top==1){
     		printf("Item deleted is %d",head->data);
         free(head);
         top=0;
     }
     else{
            temp=head;
            temp1=temp->link;
            int num=head->data;
            head=temp1;
            temp=NULL;
            free(temp);
            printf("Number deleted is %d",num);
            top--;
        }
    }
}

void peek(){
	printf("Topmost data is %d",head->data);
}

void display()
{	
	if(top==0){
		printf("No stack to display\n");

	}
	else{
	printf("There are %d nodes\n",top);
	printf("There are %d nodes left to be inserted\n",5-top);
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	}
}

void main(){
    int n;
    while(1){
        printf("\n1.Push 2.Pop 3.Peek 4.Display other to exit\n");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            push();
            break;
        
        case 2:
            pop();
            break;
        
        case 3:
            peek();
            break;
            
        case 4:
            display();
            break;
        
        default:
            exit(0);
            break;
        }
    }
}
