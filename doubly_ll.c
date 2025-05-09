#include <stdio.h>
#include <stdlib.h>

// write your code here 
struct node{
int data;
struct node* prev;
struct node* next;
};
typedef struct node *NODE;
NODE createNodeInCLL(){
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	return temp;
}
NODE first=NULL;
void insert(int x){
	NODE temp,lastNode=first;
	temp=createNodeInCLL();
	temp->data=x;
	if(first==NULL)
		first=temp;
	else{
		while(lastNode->next!=NULL)
			lastNode=lastNode->next;
		lastNode->next=temp;
		temp->prev=lastNode;
	}
}

void remov(int x){
	NODE temp=first;
	if(first==NULL){
		printf("List is empty\n");
		return;
	}
	while(temp!=NULL && temp->data!=x)
		temp=temp->next;
	if(temp==NULL){
		printf("%d not found\n",x);
		return;
	}
	if(first==temp)
		first=temp->next;
	if(temp->next!=NULL)
		temp->next->prev=temp->prev;
	if(temp->prev!=NULL)
		temp->prev->next=temp->next;
	free(temp);
}
void display(){
	if(first==NULL)
		printf("Double linked list is empty.\n");
	else{
		NODE lastNode = first;
		while(lastNode!=NULL){
			printf("%d\t",lastNode->data);
			lastNode=lastNode->next;
		}
		printf("\n");
	}
}
void reverse(){
	NODE temp=NULL, current = first;
	while(current !=NULL){
		temp=current->prev;
		current->prev=current->next;
		current->next=temp;
		current=current->prev;
	}
	if(temp!=NULL)
		first=temp->prev;
}

int main() {
    int n, ch;
    do {
        printf("Operations on doubly linked list\n");
        printf("1.Insert\n2.Remove\n3.Display\n4.Reverse\n0.Exit\n");
        printf("Enter Choice 0-4: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &n);
                insert(n);
                break;
            case 2:
                printf("Enter number to delete: ");
                scanf("%d", &n);
                remov(n);
                break;
            case 3:
                display();
                break;
            case 4:
                reverse();
                printf("List reversed\n");
                break;
        }
    } while (ch != 0);
    return 0;
}



