/*
 Write a Pop() function that is the inverse of Push(). Pop() takes a non-empty list, deletes
the head node, and returns the head node's data. If all you ever used were Push() and
Pop(), then our linked list would really look like a stack. However, we provide more
general functions like GetNth() which what make our linked list more than just a stack.
Pop() should assert() fail if there is not a node to pop. Here's some sample code which
calls Pop()....
void PopTest() {
struct node* head = BuildOneTwoThree(); // build {1, 2, 3}
int a = Pop(&head); // deletes "1" node and returns 1
int b = Pop(&head); // deletes "2" node and returns 2
int c = Pop(&head); // deletes "3" node and returns 3
int len = Length(head); // the list is now empty, so len == 0
}
*/

#include<stdlib.h>
#include<stdio.h>

struct node{
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
	int length = 0;
	struct node * current = head;
	
	while(current!=NULL){
		length+=1;
		current = current->next;
	}
	
	return length;
}

int Pop(struct node **head)
{
	struct node * current;
	struct node * next;
	int currentData;
	
	current = *head;
	currentData = current->data;
	next = current->next;
	*head = next;
	free(current);
	
	return currentData;
	}

void PopTest()
{
	struct node * head = BuildOneTwoThree();
	int a,b,c,listLength;
	
	a = Pop(&head);
	printf("Value at head node %d.\n",a);
	
	b = Pop(&head);
	printf("Value at head node %d.\n",b);
	
	c = Pop(&head);
	printf("Value at head node %d.\n",c);
	
	listLength = ListLength(head);
	printf("Length of List is %d.",listLength);
}

int main()
{
	PopTest();
	return 1;
}
