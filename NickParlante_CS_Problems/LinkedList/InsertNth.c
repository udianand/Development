
/* A more difficult problem is to write a function InsertNth() which can insert a new node at
any index within a list. Push() is similar, but can only insert a node at the head end of the
list (index 0). The caller may specify any index in the range [0..length], and the new node
should be inserted so as to be at that index.
void InsertNthTest() {
struct node* head = NULL; // start with the empty list
InsertNth(&head, 0, 13); // build {13)
InsertNth(&head, 1, 42); // build {13, 42}
InsertNth(&head, 1, 5); // build {13, 5, 42}
DeleteList(&head); // clean up after ourselves
} */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node * next;
	};


int ListLength(struct node* head){
	int length = 0;
	struct node * current = head;
	
	while(current!=NULL){
		length+=1;
		current = current->next;
	}
	
	return length;
}

void PrintList(struct node *head)
{
	struct node * current = head;
  
     
     if (current == NULL)
     printf ("The List is empty\n");
     
     else
     {
		 printf("The list is:\n");
		 while(current!=NULL)
		 {
		 printf("%d\n",current->data);
		 current=current->next;
		 }		
	 }	
}


void Push(struct node** headRef, int nodeValue)
{
	struct node* newNode = malloc(sizeof(struct node));
	newNode -> data = nodeValue;
	newNode->next = *headRef;
	*headRef = newNode;
}


void DeleteList(struct node **head)
{
	struct node * current = *head;
	struct node * next;
	
	while(current!=NULL){
		next = current->next;
		free(current);
		current = next;
	}
	
	*head = NULL;
}

void InsertNth(struct node **head,int nodeIndex, int nodeValue)
{
	struct node * current = *head;
	int currentIndex = 0;
    int listLength = ListLength(current);	
   
	if (current == NULL || nodeIndex == 0)
	{ 
		current = malloc(sizeof(struct node));
		current->data = nodeValue;
		current->next = *head;
		*head = current;
	}	
	
	else if (current != NULL && nodeIndex <= (listLength))
	{
		while (current!=NULL)
		{
			if ((currentIndex+1) == nodeIndex)
			{  
				Push(&(current->next),nodeValue);
				break;
			}
			
	     	currentIndex+=1;
			current = current->next;
		}		
	}
		
	else
	printf("Invalid Index !!!. Enter number at index %d.\n",listLength);
		
}

void InsertNthTest()
{
struct node* head = NULL;

InsertNth(&head,0,13);
InsertNth(&head,1,42);
InsertNth(&head,2,5);
InsertNth(&head,1,51);
InsertNth(&head,8,31);

printf("Length of List is: %d\n",ListLength(head));
PrintList(head);
DeleteList(&head);
PrintList(head);
}

int main()
{
	InsertNthTest();
	return 1;
	}
	
