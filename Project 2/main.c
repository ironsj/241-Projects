#include"product.h"
void menu(){
	printf("1: Create an empty list      2: Insert a product\n3: Delete a product          4: Delete the entire list\n5: Search a product          6: Display products in the list\n7: Purchase a product        8: Sell a product\n9: Save to a file            0: Exit\n");
}

int main()
{
	menu();
	struct node *head = NULL;
	while(1){
		int input;
		scanf("%d", &input);
		if(input == 0){
			break; 
		}
		else if(input == 1){
			head = init();
			printf("An empty list was created!\n");
			menu(); 
		}
		else if(input != 1 && head != NULL){
			if(input == 2){
			insert(head);
			menu();
			}
			else if(input == 3){
				delete(head);
				menu(); 
			}
			else if(input == 4){
				deleteAll(head);
				head = NULL;
				menu();
			}
			else if(input == 5){
				char newName[50];
				printf("Please enter product name to search\n");
				scanf("%s", newName);
				search(head, newName);
				menu(); 
			}
			else if(input == 6){
				display(head);
				menu(); 
			}
			else if(input == 7){
				purchase(head);
				menu(); 
			}
			else if(input == 8){
				sell(head);
				menu(); 
			}
			else if(input == 9){
				save(head);
				menu(); 
			}
			
		}
		else if(input != 1 && head == NULL){
			printf("An empty list must be created first!\n");
			menu(); 
		}
	}
	return 0;
}
