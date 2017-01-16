/*(This problem requires recursion) Given FrontBackSplit() and SortedMerge(), it's pretty
easy to write a classic recursive MergeSort(): split the list into two smaller lists,
recursively sort those lists, and finally merge the two sorted lists together into a single
sorted list. Ironically, this problem is easier than either FrontBackSplit() or
SortedMerge().
void MergeSort(struct node* headRef) { // Your code...
*/

#include <stdio.h>
#include <stdlib.h>

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
	
	head -> data = 5;
	head -> next = second;
	second -> data = 4;
	second -> next = third;
	third -> data = 3;
	third -> next = fourth;
	fourth -> data = 2;
	fourth -> next = fifth;
	fifth -> data = 1;
	fifth -> next = NULL;
	
	return head;
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


void MergeSort(struct node** headRef)
{
	struct  node* source = *headRef;
	struct node* list1;
	struct node*list2;
    
    if ((*headRef)->next == NULL)
    return;
    
    FrontBackSplit(source,&list1,&list2);
    
    PrintList(list1);
    PrintList(list2);

    MergeSort(&list1);
    MergeSort(&list2);
   
    *headRef = SortedMerge(list1,list2);
    
   
	}
	

int main()
{
	struct node* headRef = BuildList();
	
	MergeSort(&headRef);
	
	printf("The Sorted List is: \n");
	PrintList(headRef);
	
	return 1;
}
