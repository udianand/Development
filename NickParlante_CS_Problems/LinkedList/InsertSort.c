/* Write an InsertSort() function which given a list, rearranges its nodes so they are sorted in
increasing order. It should use SortedInsert().
// Given a list, change it to be in sorted order (using SortedInsert()).
void InsertSort(struct node** headRef) { // Your code
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};



void PrintList(struct node *head)
{
	struct node * current = head;
  
     
     if (current == NULL)
     printf ("The List is empty");
     
     else
     {
		 printf("The list is:\n");
		 while(current!=NULL)
		 {
		 printf("%d\t",current->data);
		 current=current->next;
		 }
		printf("\n");
	 }	
}


void SortedInsert(struct node** headRef, struct node* newNode)
{
		
	if ((*headRef)==NULL || (*headRef)->data >= newNode->data )
	{
		newNode->next=*headRef;
		*headRef=newNode;
	}
	
	else {
		struct node* current = *headRef;
		struct node*tempNode;
		
		while(current!=NULL)
		{ 
				if (current->next!=NULL && current->next->data > newNode->data && current->data < newNode->data)
				{
					tempNode = current->next;
					current->next = newNode;
					newNode->next = tempNode;
					
					break;
					}				
					
				if (current->next==NULL &&  current->data < newNode->data)
				{
					current->next= newNode;
					newNode->next = NULL;
					
					break;
					}
					
			
		current = current->next;				
			}
	}
}

void InsertSort(struct node ** headRef)
{
	struct node * currentNode = *headRef;
	struct node * result = NULL;
	struct node* nextNode;
		
	while (currentNode!=NULL)
	{ 

	nextNode = currentNode->next;
	SortedInsert(&result,currentNode);
	currentNode = nextNode;
	}
	
	*headRef = result;
}

int main ()
{
	struct node* headRef = malloc(sizeof(struct node));
	struct node* newNode2 = malloc(sizeof(struct node));
	struct node* newNode3 = malloc(sizeof(struct node));
	struct node* newNode4 = malloc(sizeof(struct node));
	
	headRef->data = 5;
	headRef->next = newNode2;
	newNode2->data = 10;
	newNode2->next = newNode3;
    newNode3->data = 7;
	newNode3->next = newNode4;
	newNode4->data = 5;
	newNode4->next = NULL;
	
	InsertSort(&headRef);
	
	PrintList(headRef);
	
	return 1;
	
}
