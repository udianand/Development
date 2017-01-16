/* Write a function DeleteList() that takes a list, deallocates all of its memory and sets its
   head pointer to NULL (the empty list).

   void DeleteListTest() {
   struct node* myList = BuildOneTwoThree(); // build {1, 2, 3}
   DeleteList(&myList); // deletes the three nodes and sets myList to NULL
}*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};

struct node * BuildOneTwoThree(){
	struct node * head = NULL;
	struct node * second = NULL;
	struct node * third = NULL;
	
	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));
	
	head -> data = 1;
	head -> next = second;
	second -> data = 2;
	second -> next = third;
	third -> data = 3;
	third -> next = NULL;
	
	return head;
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
		 printf("%2d",current->data);
		 current=current->next;
		 }
		printf("\n");
	 }	
}
	
int main ()
{
struct node* head;

head = BuildOneTwoThree();
PrintList(head);
DeleteList(&head);
PrintList(head);

return 1;
}
