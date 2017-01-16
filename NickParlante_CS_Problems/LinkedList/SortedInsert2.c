/*Given two lists sorted in increasing order, create and return a new list representing the
intersection of the two lists. The new list should be made with its own memory — the
original lists should not be changed. In other words, this should be Push() list building,
not MoveNode(). Ideally, each list should only be traversed once. This problem along
with Union() and Difference() form a family of clever algorithms that exploit the
constraint that the lists are sorted to find common nodes efficiently.

Compute a new sorted list that represents the intersection
of the two given sorted lists.

struct node* SortedIntersect(struct node* a, struct node* b) { // Your code
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
	};
	
struct node * BuildList1(){
	struct node * head = NULL;
	struct node * second = NULL;
	struct node * third = NULL;
	
	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));
	
	head -> data = 1;
	head -> next = second;
	second -> data = 10;
	second -> next = third;
	third -> data = 11;
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
	
	four -> data = 1;
	four -> next = five;
	five -> data = 2;
	five -> next = six;
	six -> data = 10;
	six -> next = NULL;
	
	return four;
}


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
		 printf("%p\t",current);
		 printf("\n");
		 current=current->next;
		 }
		printf("\n");
	 }	
}

void Push(struct node** headRef, int newData) {
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = newData;
	newNode->next = (*headRef);
	(*headRef) = newNode;
}

struct node* SortedIntersect(struct node* a, struct node* b)
{
	struct node* intersectList = NULL;
	struct node** lastPtrRef = &intersectList;
	
	printf("intersect List %p",intersectList);
	printf("&intersect List %p\n",&intersectList);
    printf("*LastPtrRef %p\n",*lastPtrRef);
	printf("Before Loop Lastptrref: %p\n",lastPtrRef);
	
	while(a!=NULL && b!=NULL)
	{
		if (a->data == b->data)
		{
			Push(lastPtrRef,a->data);
			printf("In loop Lastptrref: %p\n",lastPtrRef);
			lastPtrRef = &((*lastPtrRef)->next);
			a=a->next;
			b=b->next;
			}
			
		
		else if (a->data > b->data)
		{
			b=b->next;
			}
		
		else 
		a=a->next;
	}
	
	printf("intersect List %p\n",intersectList);
	printf("&intersect List %p\n",&intersectList);
	printf("*LastPtrRef %p\n",*lastPtrRef);
	printf("After Loop Lastptrref: %p\n",lastPtrRef);
	return intersectList;
	}
	
int main()
{
	struct node* head1 = BuildList1();
	struct node* head2 = BuildList2();
	PrintList(head1);
	PrintList(head2);
	
	struct node* sortedIntersectList;
    
   sortedIntersectList = SortedIntersect(head1,head2);
    PrintList(sortedIntersectList);
	return 1;
}
