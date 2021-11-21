#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef PRODUCT_H
#define PRODUCT_H
struct node 
{
	char name[100];
	char unit[100];
	int price;
	int quantity;
	struct node *next;
};

struct node *init ();

void insert(struct node *head);

void delete(struct node *head);

void deleteAll(struct node *head);

int search(struct node *head, char *name);

void display(struct node *head);

void purchase(struct node *head);

void sell(struct node *head);

void save(struct node *head);

#endif
