/*There is a short and efficient recursive solution to this problem. As before, the code should only
make a single pass over the list. Doing it with multiple passes is easier but very slow, so
here we insist on doing it in one pass.. Solving this problem requires a real understanding
of pointer code and recursion.

Recursively reverses the given linked list by changing its .next
pointers and its head pointer in one pass of the list.

void RecursiveReverse(struct node** headRef) { // your code...
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
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
		 printf("The List is:\n");
		 while(current!=NULL)
		 {
		 printf("%d\t",current->data);
		 current=current->next;
		 }
		printf("\n");
	 }	
}
	
struct node * BuildList(){
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;
	struct node* four = NULL;
	
	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));
    	four = malloc(sizeof(struct node));
	
	head -> data = 1;
	head -> next = second;
	second -> data = 2;
	second -> next = third;
	third -> data = 3;
	third -> next = four;
    	four -> next = NULL;
    	four -> data = 4;
    	
	return head;
}

void Push(struct node**head,int data)
{
	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = (*head);
	*head = newNode;
	}
	

void RecursiveReverse(struct node** head)
{
	struct node* first;
	struct node* rest;
	
	if (*head == NULL)
	return;
	
	first = *head;
	rest = first->next;
	
	if (rest == NULL)
	return;
	
	RecursiveReverse(&rest);
	
	first->next->next = first;
	first->next = NULL;
	
	*head = rest;
	
}

int main()
{
	struct node* head;
	
	head = BuildList();
	
	printf("Before Reversing\n");
	PrintList(head);
    
    	RecursiveReverse(&head);	
    
    	printf("After Reversing\n");
    	PrintList(head);
	
	return 1;
}
