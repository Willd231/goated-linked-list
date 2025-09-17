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
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }

    node * temp = head;
    while(temp != NULL){
        if(temp->prev == NULL) { // head
            printf("%s(head)->", temp->data);
        }
        else if(temp->next == NULL) { // tail
            printf("%s->NULL", temp->data);
        }
        else { // middle
            printf("%s->", temp->data);
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    char data[] = "hello";
    head = insertNode(head, data); // <- update head
   	insertNode(head, "yo"); 
	
    int count = getNum(head);
    
    PrintList(head);

    // Free the list
    node *temp;
    while(head) {
        temp = head;
        head = head->next;
        free(temp->data); // only if malloc'd
        free(temp);
    }

    return 0;
}





