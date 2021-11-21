#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"product.h"

struct node *init()
{
	struct node* head = (struct node*)malloc(sizeof(struct node));
	head -> next = NULL;
}

int search(struct node *head, char *name){
	while(head != NULL)
	{
		if(strcmp(head->name, name) == 0)
		{
			printf("'%s' is in the list.\n", name);
			printf("%s %s %d %d\n", head -> name, head->unit, head->price, head->quantity);
			return 1;
		}
		else if(head->next == NULL)
		{
			printf("'%s' is not in the list.\n", name);
			return -1;
		}
		head = head->next;
	}
}

void insert (struct node *head)
{
	char newName[50];
	char newUnit[50];
	int newPrice;
	int newQuantity;
	printf("Please enter product name, unit, price and quantity (using blank space as delimeter\n");
	scanf("%s %s %d %d", newName, newUnit, &newPrice, &newQuantity);
	if(newPrice <= 0)
	{
		printf("The price of a product should be greater than 0!\n");
	}
	else if(newQuantity <= 0)
	{
		printf("The quantity of a product should be greater than 0!\n");
	}
	else{
		if(search(head, newName) == -1)
		{
			while(head != NULL){
				if(head->next == NULL)
				{
					struct node* new = (struct node*)malloc(sizeof(struct node));
					strcpy(new->name, newName);
					strcpy(new->unit, newUnit);
					new -> price = newPrice;
					new -> quantity = newQuantity;
					new -> next = NULL; 
					head -> next = new;
					printf("Product %s has been inserted!\n", newName);
					break;
				}
				head = head->next;
			}
		}
		else
		{
			printf("This item is already in the list!\n");
		}
	}
}

void display (struct node *head)
{
	printf("The list is:\n");
	head = head->next;
	while(head != NULL)
	{
		if(head->next == NULL)
		{
			printf("%s %s %d %d\n", head -> name, head->unit, head->price, head->quantity);
		}
		else if(head != NULL)
		{
			printf("%s %s %d %d\n", head -> name, head->unit, head->price, head->quantity);
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
	else{
		printf("The entire list has been deleted!\n");
	}
}

void purchase(struct node *head)
{
	char newName[50];
	printf("Please enter product name\n");
	scanf("%s", newName);
	if(search(head, newName) == 1)
	{
		while(head != NULL){
			if(strcmp(head->name, newName) == 0)
			{
				head->quantity += 1;
				printf("%s %s %d %d\n", head -> name, head->unit, head->price, head->quantity);
				break;
			}
			head = head->next;
		}
	}
}

void sell(struct node *head)
{
	char newName[50];
	printf("Please enter product name\n");
	scanf("%s", newName);
	if(search(head, newName) == 1)
	{
		while(head->next != NULL){
			if(strcmp(head->next->name, newName) == 0)
			{
				if(head->next->quantity >= 2){
					head->next->quantity -= 1;
					printf("%s %s %d %d\n", head->next->name, head->next->unit, head->next->price, head->next->quantity);
				}
				else if(head->next->quantity == 1){
					head->next->quantity -= 1;
					printf("%s %s %d %d\n", head->next->name, head->next->unit, head->next->price, head->next->quantity);
					printf("Product %s has been deleted\n", newName);
					struct node *q = head->next;
					strcpy(q->name, head->next->name);
					strcpy(q->unit, head->next->unit);
					q->price = head->next->price;
					q->quantity = head->next->quantity;
					head->next = head->next->next;
					free(q);     
				}
				break;
			}
			head = head->next;
		}
	}
}

void delete(struct node *head)
{
	char newName[50];
	printf("Please enter product name\n");
	scanf("%s", newName);
	if(search(head, newName) == 1)
	{
		while(head->next != NULL){
			if(strcmp(head->next->name, newName) == 0)
			{
				
				printf("Product %s has been deleted\n", newName);
				struct node *q = head->next;
				strcpy(q->name, head->next->name);
				strcpy(q->unit, head->next->unit);
				q->price = head->next->price;
				q->quantity = head->next->quantity;
				head->next = head->next->next;
				free(q);
				break;     
			}
			head = head->next;
		}
	}
}

void save(struct node *head)
{
	FILE * fptr;
    	fptr = fopen("list.txt", "w");
    	head = head->next;
    	while(head != NULL)
	{
		fprintf(fptr, "%s %s %d %d\n", head->name, head->unit, head->price, head->quantity);
		head = head->next;
	}
	fclose(fptr);
	printf("The list has been saved to a file!\n");
}


/*int main()
{
	struct node *head;
	head = init();
	insert(head);
	insert(head);
	save(head);
	return 0;
}*/
