/*This is a variant on Push(). Instead of creating a new node and pushing it onto the given
list, MoveNode() takes two lists, removes the front node from the second list and pushes
it onto the front of the first. This turns out to be a handy utility function to have for
several later problems. Both Push() and MoveNode() are designed around the feature that
list operations work most naturally at the head of the list. Here's a simple example of
what MoveNode() should do...
void MoveNodeTest() {
struct node* a = BuildOneTwoThree();
struct node* b = BuildOneTwoThree();
// the list {1, 2, 3}
MoveNode(&a, &b); // a == {1, 1, 2, 3} // b == {2, 3}
}

Take the node from the front of the source, and move it to
the front of the dest.
It is an error to call this with the source list empty.

void MoveNode(struct node** destRef, struct node** sourceRef) { // Your code
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
	};

void PrintList(struct node* head)
{
	struct node* current = head;
  
     
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
	
struct node * BuildOneTwoThree(){
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;
	
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

void MoveNode(struct node** destRef, struct node** sourceRef) 
{
	if ((*destRef!=NULL) && (*sourceRef!=NULL))
	{
		struct node*  tempNode1 = *sourceRef;
		//struct node* tempNode2 = *destRef;
		
		*sourceRef = (*sourceRef)->next;
		tempNode1->next = *destRef;
		*destRef = tempNode1;
	}
}
		
int main()
{
	struct node* firstList = BuildOneTwoThree();
	struct node* secondList = BuildOneTwoThree();
	
	MoveNode((&firstList),(&secondList));
	
	PrintList(firstList);
	PrintList(secondList);
	
	return 1;
}

