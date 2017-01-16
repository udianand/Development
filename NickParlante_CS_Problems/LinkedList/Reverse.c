/* Write an iterative Reverse() function that reverses a list by rearranging all the
.next pointers and the head pointer. Ideally, Reverse() should only need to make one pass of the
list. The iterative solution is moderately complex. It's not so difficult that it needs to be
this late in the document, but it goes here so it can be next to #18 Recursive Reverse
which is quite tricky. The efficient recursive solution is quite complex (see next
problem). (A memory drawing and some hints for Reverse() are below.)
void ReverseTest() {
struct node* head;
head = BuildOneTwoThree();
Reverse(&head); // head now points to the list {3, 2, 1}
DeleteList(&head); // clean up after ourselves
}*/



#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
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

void Push(struct node**head,int data)
{
	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = (*head);
	*head = newNode;
	}
	
void Reverse(struct node** head)
{
	struct node* current = *head;
	struct node* result = NULL;
	
	while(current!=NULL)
	{
	   Push(&result,current->data);
	   current= current->next;
		}
	
	*head=result;
}

int main()
{
	struct node* head;
	
	head = BuildList();
	
	printf("Before Reversing");
	PrintList(head);
    
    Reverse(&head);	
    
    printf("After Reversing");
    PrintList(head);
	
	return 1;
}
