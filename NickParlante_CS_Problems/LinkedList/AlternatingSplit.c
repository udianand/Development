/*Write a function AlternatingSplit() that takes one list and divides up its nodes to make
two smaller lists. The sublists should be made from alternating elements in the original
list. So if the original list is {a, b, a, b, a}, then one sublist should be {a, a, a} and the
other should be {b, b}. You may want to use MoveNode() as a helper. The elements in
the new lists may be in any order (for some implementations, it turns out to be convenient
if they are in the reverse order from the original list.)

Given the source list, split its nodes into two shorter lists.
If we number the elements 0, 1, 2, ... then all the even elements
should go in the first list, and all the odd elements in the second.
The elements in the new lists may be in any order.

void AlternatingSplit(struct node* source,
struct node** aRef, struct node** bRef) { // Your code
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
	struct node * four = NULL;
	struct node * five = NULL;
	struct node * six = NULL;
	
	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));
	four = malloc(sizeof(struct node));
	five = malloc(sizeof(struct node));
	six = malloc(sizeof(struct node));
	
	head -> data = 1;
	head -> next = second;
	second -> data = 2;
	second -> next = third;
	third -> data = 3;
	third -> next = four;
	four -> data = 4;
	four -> next = five;
	five -> data = 5;
	five -> next = six;
	six -> data = 6;
	six -> next = NULL;
	
	
	return head;
}

void MoveNode(struct node** destRef, struct node** sourceRef) 
{
	if (*sourceRef!=NULL)
	{
		struct node*  tempNode1 = *sourceRef;
		
		*sourceRef = (*sourceRef)->next;
		tempNode1->next = *destRef;
		*destRef = tempNode1;				
	}
}

void AlternatingSplit(struct node* source,struct node** aRef, struct node** bRef)
{
	struct node* firstList = *aRef;
	struct node* secondList = *bRef;
	
	while (source!=NULL)
	{
		MoveNode(&firstList,&source);
		if(source!=NULL)
		MoveNode(&secondList,&source);
	}
		
	*aRef = firstList;
	*bRef = secondList;
}

int main()
{
	struct node* source = BuildOneTwoThree();
	struct node* aRef = NULL;
	struct node* bRef = NULL;
	
	AlternatingSplit(source,(&aRef),(&bRef));
	
	PrintList(aRef);
	PrintList(bRef);
		
	return 1;
}		
