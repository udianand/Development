/* Write an Append() function that takes two lists, 'a' and 'b', appends 'b' onto the end of 'a',
and then sets 'b' to NULL (since it is now trailing off the end of 'a'). Here is a drawing of
a sample call to Append(a, b) with the start state in gray and the end state in black. At the
end of the call, the 'a' list is {1, 2, 3, 4}, and 'b' list is empty.

// Append 'b' onto the end of 'a', and then set 'b' to NULL.
void Append(struct node** aRef, struct node** bRef) {
// Your code... */

#include<stdio.h>
#include<stdlib.h>

struct node
{
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

struct node * BuildFourFiveSix(){
	struct node * four = NULL;
	struct node * five = NULL;
	struct node * six = NULL;
	
	four = malloc(sizeof(struct node));
	five = malloc(sizeof(struct node));
	six = malloc(sizeof(struct node));
	
	four -> data = 4;
	four -> next = five;
	five -> data = 5;
	five -> next = six;
	six -> data = 6;
	six -> next = NULL;
	
	return four;
}

void PrintList(struct node * head)
{
	struct node* currentNode = head;
	
	if (currentNode == NULL)
	printf("The list is empty.");
	
	else 
	{ 
		printf("The List is: \n");
		while(currentNode!=NULL)
		  {
			printf("%d\t",currentNode->data);
			currentNode = currentNode->next;
		  }
	}
}
	
void Append(struct node** aRef , struct node** bRef)
{
	if ((*aRef!=NULL) && (*bRef!=NULL))
	{
		struct node * currentNode = *aRef;
		
		while (currentNode!=NULL)
		{
			if (currentNode->next == NULL)
			{
				currentNode->next = *bRef;
				*bRef = NULL;
				break;
			}
			currentNode = currentNode->next;
		}
				
	}
	
	else if ((*aRef == NULL) && (*bRef!=NULL))
	{		
		*aRef = *bRef;
		*bRef = NULL;
		} 
	
	else 
	printf("Second List is set to NULL. \n");
}

int main()
{
	// struct node *head1 = NULL; 
	struct node *head1 = BuildOneTwoThree();
	// struct node *head2 = NULL;
	struct node *head2 = BuildFourFiveSix();
	
    Append(&head1,&head2);
    
    PrintList(head1);
    printf("\n"); 	
	PrintList(head2);
	
	return 1;
	
}
