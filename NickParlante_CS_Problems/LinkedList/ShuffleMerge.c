/*Given two lists, merge their nodes together to make one list, taking nodes alternately
between the two lists. So ShuffleMerge() with {1, 2, 3} and {7, 13, 1} should yield {1, 7,
2, 13, 3, 1}. If either list runs out, all the nodes should be taken from the other list. The
solution depends on being able to move nodes to the end of a list as discussed in the
Section 1 review. You may want to use MoveNode() as a helper. Overall, many
techniques are possible: dummy node, local reference, or recursion. Using this function
and FrontBackSplit(), you could simulate the shuffling of cards.

Merge the nodes of the two lists into a single list taking a node
alternately from each list, and return the new list.

struct node* ShuffleMerge(struct node* a, struct node* b) { // Your code */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next; 
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

void MoveNode(struct node** destRef, struct node** sourceRef) 
{
	if ((*sourceRef)!=NULL)
	{
		struct node*  tempNode1 = *sourceRef;
		
		*sourceRef = (*sourceRef)->next;
		tempNode1->next = *destRef;
		*destRef = tempNode1;
	}
}

struct node* ShuffleMerge(struct node* head1, struct node* head2)
{
	struct node* shuffleMerge=NULL;

while(1)
{
 
	if (head1==NULL && head2!=NULL)
	{
		while(head2!=NULL)
		MoveNode(&shuffleMerge,&head2);
	}
	
	else if (head2==NULL && head1!=NULL)
	{
		while(head1!=NULL)
		MoveNode(&shuffleMerge,&head1);	
	}
		
	else if (head1!=NULL && head2!=NULL)
	{
		MoveNode(&shuffleMerge,&head1);
		MoveNode(&shuffleMerge,&head2);	
		}
		
	else if (head1==NULL && head2==NULL)
	break;
 }
	
	return shuffleMerge;	
}

int main()
{
	struct node* head1 = BuildOneTwoThree();
	struct node* head2 = BuildFourFiveSix();
	struct node* shuffleMergeList;
	
	shuffleMergeList = ShuffleMerge(head1,head2);
	PrintList(shuffleMergeList);
	return 1;
	}
