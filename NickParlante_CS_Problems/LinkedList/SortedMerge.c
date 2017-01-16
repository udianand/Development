/*Write a SortedMerge() function that takes two lists, each of which is sorted in increasing
order, and merges the two together into one list which is in increasing order.
SortedMerge() should return the new list. The new list should be made by splicing
together the nodes of the first two lists (use MoveNode()). Ideally, Merge() should only
make one pass through each list. Merge() is tricky to get right — it may be solved
iteratively or recursively. There are many cases to deal with: either 'a' or 'b' may be
empty, during processing either 'a' or 'b' may run out first, and finally there's the problem
of starting the result list empty, and building it up while going through 'a' and 'b'.

Takes two lists sorted in increasing order, and
splices their nodes together to make one big
sorted list which is returned.

struct node* SortedMerge(struct node* a, struct node* b) { // your code...
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

struct node * BuildList1(){
	struct node * head = NULL;
	struct node * second = NULL;
	struct node * third = NULL;
	
	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));
	
	head -> data = 1;
	head -> next = second;
	second -> data = 9;
	second -> next = third;
	third -> data = 8;
	third -> next = NULL;
	
	return head;
}

struct node * BuildList2(){
	struct node * four = NULL;
	struct node * five = NULL;
	struct node * six = NULL;
	
	four = malloc(sizeof(struct node));
	five = malloc(sizeof(struct node));
	six = malloc(sizeof(struct node));
	
	four -> data = 0;
	four -> next = five;
	five -> data = 2;
	five -> next = six;
	six -> data = 10;
	six -> next = NULL;
	
	return four;
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

struct node* SortedMerge(struct node* a, struct node* b) 
{
	struct node* result = NULL;
	struct node** lastPtrRef = &result; // point to the last result pointer
	
	while (1) 
	{
	
		if (a==NULL) {
			*lastPtrRef = b;
			break;
			}
			
	else if (b==NULL) {
		*lastPtrRef = a;
		break;
		}

	if (a->data <= b->data) 
	{
	 MoveNode(lastPtrRef, &a);
		}
		
	else {
		MoveNode(lastPtrRef, &b);
		}
	
	lastPtrRef = &((*lastPtrRef)->next);
	}
	
	return(result);
}


int main()
{
	struct node* head1 = BuildList1();
	struct node* head2 = BuildList2();
	struct node* sortedMergeList;
	
	sortedMergeList = SortedMerge(head1,head2);
	
	PrintList(sortedMergeList);
	
	return 1;
	}
