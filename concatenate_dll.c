#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
	struct DoublyLinkedList{
	int data;
	struct DoublyLinkedList *head;
	struct DoublyLinkedList *tail;
};
struct DoublyLinkedList *createNode()
{
	struct DoublyLinkedList *temp=(struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
	temp->head=NULL;
	temp->tail=NULL;
	return temp;
}

void append(struct DoublyLinkedList *first,int x){
	struct DoublyLinkedList *temp,*lastNode=first;
	temp=createNode();
	temp->data=x;
	if(first==NULL)
		first=temp;
	else{
		while(lastNode->head!=NULL)
			lastNode=lastNode->head;
		lastNode->head=temp;
		temp->tail=lastNode;
	}
}
void displayList(struct DoublyLinkedList *first){
	if(first==NULL){
		printf("List is empty\n");
		return;
	}while(first!=NULL){
		if(first->data==0)
			first=first->head;
		printf("%d <-> ",first->data);
		first=first->head;
	}
	printf("NULL\n");
}

void concatenate(struct DoublyLinkedList *list1,struct DoublyLinkedList *list2){
	if(list1==NULL){
		list1=list2;
		return;
	}if(list1==NULL)
		return;
	struct DoublyLinkedList *temp=list1;
	while(temp->head!=NULL)
		temp=temp->head;
	temp->head=list2;
	list2->tail=temp;
}
int main() {
    struct DoublyLinkedList* list1 = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
    list1->head = NULL;
    list1->tail = NULL;

    struct DoublyLinkedList* list2 = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
    list2->head = NULL;
    list2->tail = NULL;

    int choice, data;

    printf("Elements for List 1 (separated by spaces): ");
    while (1) {
        scanf("%d", &data);
        append(list1, data);
        char c = getchar();
        if (c == '\n') break;
    }

    printf("Elements for List 2 (separated by spaces): ");
    while (1) {
        scanf("%d", &data);
        append(list2, data);
        char c = getchar();
        if (c == '\n') break;
    }

    while (1) {
        printf("1. Display List 1\n");
        printf("2. Display List 2\n");
        printf("3. Concatenate\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("List 1: ");
                displayList(list1);
                break;
            case 2:
                printf("List 2: ");
                displayList(list2);
                break;
            case 3:
                concatenate(list1, list2);
                printf("Lists Concatenated\n");
                break;
            case 4:
                free(list1);
                free(list2);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

