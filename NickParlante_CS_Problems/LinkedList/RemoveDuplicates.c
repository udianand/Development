/*Write a RemoveDuplicates() function which takes a list sorted in increasing order and
deletes any duplicate nodes from the list. Ideally, the list should only be traversed once.

Remove duplicates from a sorted list.

void RemoveDuplicates(struct node* head) {
// Your code...*/

# include <stdio.h>
# include <stdlib.h>

struct node{
	int data;
	struct node* next;
	};



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
	third -> data = 5;
	third -> next = fourth;
	fourth -> data = 5;
	fourth -> next = fifth;
	fifth -> data = 5;
	fifth -> next = NULL;
	
	return head;
}

void RemoveDuplicates(struct node* head)
{
	if (head == NULL)
	printf("List is Empty.\n");
	
	else
	{
		struct node* currentNode = head;
		while(currentNode->next!=NULL)
		{
			if (currentNode->data == currentNode->next->data)
			{
				struct node* nextNextNode = currentNode->next->next;
				free(currentNode->next);
				currentNode->next=nextNextNode;
				}
			else // Increment only if there is no deletion.
			currentNode=currentNode->next;
		}
	}
}
	
	
int main()
{
	 
    struct node *head = BuildList();
	
    RemoveDuplicates(head);
    PrintList(head);
	
	return 1;
	
}
