#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

struct node *init (); //initialize: create an empty head node (whose "data" is intentionally missing); This head node will not be used to store any data;

void insert(struct node *head, int data); //Create a new node to store data and insert it to the end of current linked list; the head node will still be empty and data in the array in the main() function are not stored in head node

void display (struct node *head); //print data for all nodes in the linked list except the head node (which is empty)

void deleteAll (struct node *head); //delete the entire linked list including the head node

struct node *init()
{
	struct node* head = (struct node*)malloc(sizeof(struct node));
	head -> next = NULL;
}

void insert (struct node *head, int data)
{
	if (head->next == NULL)
	{
		struct node* new = (struct node*)malloc(sizeof(struct node)); 
		new -> data = data;
		new -> next = NULL; 
		head -> next = new;
	}
	else
	{
		insert(head->next, data);
	}
}

void display (struct node *head)
{
	head = head->next;
	while(head != NULL)
	{
		if(head->next == NULL)
		{
			printf("%d\n", head -> data);
		}
		else if(head != NULL)
		{
			printf("%d ", head -> data);
		}
		head = head->next;
	}
}

void deleteAll (struct node *head)
{
	if (head!=NULL)
	{
		deleteAll(head->next);
		free(head);
	}
}


int main()
{
	int array[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	struct node *head;
	head = init();   //after this statement, a linked list has been created with only a head node
	
	int i;
	for (i=0;i<10;i++) 
	{
		insert(head, array[i]);   //create a new node to store an array element for each iteration. This new node is inserted to the end of current linked list
	}
	
	display(head);  //print data for all nodes in the linked list except the head node (which is empty)

	deleteAll(head);  //delete the entire linked list including the head node

	return 1;
}
