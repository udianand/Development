// Write a Count() function that counts the number of times a given int occurs in a list. The
// code for this has the classic list traversal structure as demonstrated in Length()

/*void CountTest() {
List myList = BuildOneTwoThree();
// build {1, 2, 3}
int count = Count(myList, 2);
// returns 1 since there's 1 '2' in the list
}

Given a list and an int, return the number of times that int occurs
in the list.
*/

// Your code Below 

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

int Count (struct node *head, int searchFor){
	struct node * current = head;
	int repeat = 0;
	
	while (current!=NULL){
		
		if (current->data == searchFor){
			repeat +=1 ;
			}
			
		current = current->next;
		}
		
		if (repeat!=0)
			return repeat;
		else 
			return 0;
		
}

int main ()
{
	int searchFor,repeat;
	struct node * head;
	
	printf("Enter the number to search for: ");
	scanf("%d",&searchFor);
	
	head = BuildOneTwoThree();
	repeat = Count(head,searchFor);
	
	if (repeat!=0)
	printf("The number %d occurs %d times.",searchFor,repeat);
	else
	printf("The number is not present in the list.");
	
	return 1;
}
	
	
	
	
