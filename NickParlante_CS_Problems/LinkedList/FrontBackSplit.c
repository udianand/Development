/* Given a list, split it into two sublists — one for the front half, and one for the back half. If
the number of elements is odd, the extra element should go in the front list. So
FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7,
11}. Getting this right for all the cases is harder than it looks. You should check your
solution against a few cases (length = 2, length = 3, length=4) to make sure that the list
gets split correctly near the short-list boundary conditions. If it works right for length=4,
it probably works right for length=1000. You will probably need special case code to deal
with the (length <2) cases. Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.

void FrontBackSplit(struct node* source,
struct node** frontRef, struct node** backRef) { // Your code...
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
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

int LengthList(struct node* head){
	
	int length = 0;
	struct node * current = head;
	
	while(current!=NULL){
		length+=1;
		current = current->next;
	}
	
	return length;
}

struct node * BuildList(){
	
	struct node * head = NULL;
	struct node * second = NULL;
	struct node * third = NULL;
	struct node * fourth = NULL;
	struct node * fifth = NULL;

	
	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));
	fourth = malloc(sizeof(struct node));
	fifth = malloc(sizeof(struct node));
	
	head -> data = 1;
	head -> next = second;
	second -> data = 2;
	second -> next = third;
	third -> data = 3;
	third -> next = fourth;
	fourth -> data = 4;
	fourth -> next = fifth;
	fifth -> data = 5;
	fifth -> next = NULL;
	
	return head;
}

void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef)	
{
	int listLength = LengthList(source);
	printf("List length is: %d\n",listLength);
	
	if (listLength < 2)
	{
		*frontRef = source;
		}
		
	else 
	{
		
		int midPoint,count=1;
		struct node* currentNode = source;
		
		if ((listLength % 2) == 0)
		midPoint = (listLength)/2;
		
		else
		midPoint = (listLength+1)/2;
		
		printf("The midPoint is: %d\n",midPoint);
		
		while(currentNode!=NULL)
		{
			if(count == midPoint)
			{
				*frontRef = source;
				*backRef = currentNode->next;
				currentNode->next = NULL;
				break;
				}
			count+=1;
			currentNode = currentNode->next;
		}		
	}
}

	
int main()
{	
	struct node* head = BuildList();
	struct node* frontRef = NULL;
	struct node* backRef = NULL;
	
	FrontBackSplit(head,(&frontRef),(&backRef));
	
	printf("The first list is:\n");
	PrintList(frontRef);
	printf("The second list is:\n");
	PrintList(backRef);
	
	return 1;
} 

