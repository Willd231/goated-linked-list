#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//node model
typedef struct node {
	struct node * next; 
	struct node * prev; 
	char * data; 
	int id; 
	
}   node;



//head of the linked list 
node * head = NULL; 


//function prototypes
node * createNode(char * data);
node * insertNode(node * head, char * data);
node * deleteNode(node * head, char * data);
int isIN(node * head, char * data);
int getNum(node * head);
char ** getVals(node * head);
void PrintList(node * head); 




//utility function to just generate a new node based on given input data
node * createNode(char * data){
	node * newnode = malloc(sizeof(node));
	newnode -> next = NULL;
	newnode -> prev = NULL; 
	newnode -> data = data;
	return newnode; 
}



//function to insert a node, if left blank adds to the back but if specified indexing can occur -- i will work on this later

node * insertNode(node * head, char * data){

	if (head == NULL){
		head = createNode(data); 
		
		return head; 
	}
	
		node * newnode = createNode(data); 
			node * temp = head; 
		while(temp -> next != NULL){
			temp = temp-> next;  
		}
		temp ->next = newnode; 
	
	return head; 	
}


//function to delete a node, takes in the head and the node to delete and returns the altered list 
node * deleteNode(node * head, char * data){
	if(head == NULL){
		return head;
	}

	if(strcmp(head->data, data) == 0){
		//head swap 
	 head -> next = head; 
		
		return head;
	}

	else{
		node * temp = head; 

		while(temp != NULL && strcmp(data, temp->data) != 0){
			temp = temp -> next; 
		}

			temp->prev->next = temp-> next; 
			free(temp);

			return head;
	}
}




//returns 0 if the value is included in the list and 1 if not 
int isIN(node * head, char * data){
	if(head == NULL){
		return 2;
	}
	node * temp = head; 
	while(temp != NULL){
		if(strcmp(temp-> data, data) == 0){
			return 0;
		}
		temp = temp -> next; 
	}
	return 1;
}



int getNum(node * head){
	
	node * temp = head; 
	int count = 0; 
	
	while(temp!= NULL){
		count +=1; 
		temp = temp -> next; 
	}
	return count; 
}



char ** getVals(node * head){
	int num = getNum(head);
	int i = 0;
	char ** vals = malloc(sizeof(char) * num );

	node * temp = head; 

	while(temp != NULL){
		vals[i] = malloc(sizeof(char*) * strlen(temp->data) + 1);
		strcpy(temp->data, vals[i]);
		i++; 
	}
	return vals;
}

void PrintList(node * head){
	//remember that when you concat that it breaks the length of the stack allocated strings	
	char arrow[] = "->"; 
	char  marker1[] = "(head)";
	char  marker2[] = "NULL";
	char ** vals = getVals(head);
	int num = getNum(head); 
	size_t len1 = strlen(arrow) + strlen(marker1);
	size_t len2 = strlen(arrow) + strlen(marker2);   
	char ** printable = malloc (sizeof(char*) * num); 

	for(int i = 0; i < num; i ++){
	
		if(i == 0){ 
		printable[i] = malloc(sizeof(char) * strlen(vals[i]) + 1 + len1 + 1); 
		strcpy(printable[i], vals[i]);
		strcat(printable[i], marker1);
		strcat(printable[i], arrow);
		printf("%s", printable[i]);
		   }
		
		
	 	else if(i == num - 1){
	 		printable[i] = malloc(sizeof(char) * strlen(vals[i]) + 1 + len2 + 1);
			strcpy(printable[i],vals[i]);
			strcat(printable[i], arrow);
			strcat(printable[i], marker2);
			printf("%s", printable[i]);

	 					
	 		}
	 		
	 	else{
	 
			printable[i] = malloc(sizeof(char) * strlen(vals[i]) + 1 + strlen(arrow) + 1);
			strcpy(printable[i], vals[i]);
			strcat(printable[i], arrow);
			printf("%s", printable[i]);
	 			 		}
	 			 		}
		
	for(int i = 0; i < num; i ++){
		printf("%s", printable[i]);
		free(printable[i]);
	}

	free(printable);
		

	


}

int main (){

/*
bool status = true; 
printf("Options:\n 1 - print current list\n2 - Add to nodes to the list\n 3 - delete nodes from the list\n4 - Check if a value is in the list without printing\n");

	int option; 
	
	while(status == true){
		
	scanf("%d", &option);

	switch(option){
		case 1:
			PrintList(head);
			break;
		
		case 2:
			printf("Enter the value you wish to enter: \n");
			char *  data = malloc(sizeof(char) * 20); 
			scanf("%s", data);
			insertNode(head, data);
			printf("Alright! \n");
			int count = getNum(head);
			printf("%d", count);
			break;

		case 3:
			printf("Enter the value you want to delete:\n");
			char * value = malloc(sizeof(char) * 20);
			scanf("%c", value);
			if ((isIN(head, value) == 2)){
			printf("The list is empty dawg...\n");
			break;	
			}
			else if(isIN(head, value) == 1){
				printf("ts is not in the list gang");
			break;
			}
			else if(isIN(head, value) == 0){
				deleteNode(head, value);
				printf("it is done...");
			break;
			}
			break;
		case 4:
			printf("You could have just printed gang; Enter the value:");
			char * check = malloc(sizeof(char) * 20);
			scanf("%s", check);
			if(isIN(head, check) == 2){
				printf("Yeah it is not here, the list is empty");
							}
							else if(isIN(head,check) == 1){ printf("Not in the list"); }
							else if(isIN(head, check) == 0){
								printf("Yeah its here");
							}
			break;
	}
}

*/



char data[] = "hello";

insertNode(head, data); 
int count = getNum(head);
			printf("%d", count);

PrintList(head);
	return 0;

}




