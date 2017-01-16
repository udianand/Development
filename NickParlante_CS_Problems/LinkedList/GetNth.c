/* Write a GetNth() function that takes a linked list and an integer index and returns the data
value stored in the node at that index position. GetNth() uses the C numbering convention
that the first node is index 0, the second is index 1, ... and so on. So for the list {42, 13,
666} GetNth() with index 1 should return 13. The index should be in the range [0..length-
1]. If it is not, GetNth() should assert() fail (or you could implement some other error
case strategy).
void GetNthTest() {
struct node* myList = BuildOneTwoThree(); // build {1, 2, 3}
int lastNode = GetNth(myList, 2); // returns the value 3
}*/

#include <stdio.h>
#include <stdlib.h>

struct node {
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

int ListLength(struct node* head){
	int length = -1;
	struct node * current = head;
	
	while(current!=NULL){
		length+=1;
		current = current->next;
	}
	
	return length;
}

int GetNth(struct node *head, int index){
    
	struct node * current;
	int currentIndex = 0;
	current = head;
	 
	while (current!=NULL)
	{
		if (currentIndex == index)
			return current->data;
		else
		currentIndex+=1;
		
		current = current->next;
	}
}
	
	

int main()
{
	int listLength,index,data;
	struct node * head;

	head = BuildOneTwoThree();
	listLength = ListLength(head);
	
	do{	
		printf("\nEnter the Linked List index:\n ");
		scanf("%d",&index);
			
		if (listLength == -1)
		printf("List could not be initialized");
		else if(listLength >= 0 && index <= listLength)
		{ 
			data = GetNth(head,index);
			printf("\nThe value at the given index %d is: %d.\n",index,data);
			}	
		else
		printf("\nPlease enter number within range 0 to %d\n",listLength);
		}
					
	while (1);
	return 1;
}
