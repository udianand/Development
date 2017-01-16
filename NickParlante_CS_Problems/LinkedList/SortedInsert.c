/* Write a SortedInsert() function which given a list that is sorted in increasing order, and a
single node, inserts the node into the correct sorted position in the list. While Push()
allocates a new node to add to the list, SortedInsert() takes an existing node, and just
rearranges pointers to insert it into the list. There are many possible solutions to this
problem.
void SortedInsert(struct node** headRef, struct node* newNode) { // Your code...
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node * next;
};

/* Function to print linked list */
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
		 printf("%4d",current->data);
		 current=current->next;
		 }
		printf("\n");
	 }	
}

/* function to insert a new_node in a list. Note that this
  function expects a pointer to head_ref as this can modify the
  head of the input linked list (similar to push())*/
  
void SortedInsert(struct node** headRef, struct node* newNode)
{
	/* Special case for the head end */	
	if ((*headRef)==NULL || (*headRef)->data >= newNode->data )
	{
		newNode->next=*headRef;
		*headRef=newNode;
	}
	
	else {
		/* Locate the node before the point of insertion */
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

int main()
{
	struct node* headRef = NULL;
	
	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = 15;
	newNode->next = NULL;
	SortedInsert(&headRef,newNode);
	
	struct node* newNode2 = malloc(sizeof(struct node));
	newNode2->data = 10;
	newNode2->next = NULL;
	SortedInsert(&headRef,newNode2);
	
    struct node* newNode3 = malloc(sizeof(struct node));
	newNode3->data = 7;
	newNode3->next = NULL;
	SortedInsert(&headRef,newNode3);
	
	struct node* newNode4 = malloc(sizeof(struct node));
	newNode4->data = 5;
	newNode4->next = NULL;
	SortedInsert(&headRef,newNode4);
	
	struct node* newNode5 = malloc(sizeof(struct node));
	newNode5->data = 2;
	newNode5->next = NULL;
	SortedInsert(&headRef,newNode5);
	
	printf("Before inserting 9. ");
	PrintList(headRef);

	
	struct node* newNode6 = malloc(sizeof(struct node));
	newNode6->data = 9;
	newNode6->next = NULL;
	SortedInsert(&headRef,newNode6);
	
	printf("After inserting 9. ");
	PrintList(headRef);
	
	return 1;
}
