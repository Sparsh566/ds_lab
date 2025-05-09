#include<stdio.h>
#include<stdlib.h>

// write your code here 
struct node{
	int data;
	struct node* next;
};

typedef struct node* NODE;
NODE insertAtPositionInCLL(NODE first,int pos,int ele){
	NODE temp = (NODE)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=NULL;
	if(pos<1){
		printf("Invalid position\n");
		free(temp);
		return first;
	}
	if(first==NULL && pos!=1){
		printf("Position not found\n");
		free(temp);
		return first;
	}
	if(pos==1){
		if(first==NULL){
			temp->next=temp;
			return temp;
		}else{
			NODE last=first;
			while(last->next!=first)
				last=last->next;
			temp->next=first;
			last->next=temp;
			return temp;
		}
	}
	NODE curr=first;
	int count=1;
	while(count<pos-1 && curr->next!=first){
		curr=curr->next;
		count++;
	}
	if(count<pos-1){
		printf("Position not found\n");
		free(temp);
	}else{
		temp->next=curr->next;
		curr->next=temp;
	}
	return first;
}
NODE deleteAtPositionInCLL(NODE first,int pos){
	if(first==NULL){
		printf("CLL is empty\n");
		return NULL;
	}
	if(pos<1){
		printf("Invalid position\n");
		return first;
	}
	if(pos==1){
		NODE last = first;
		while(last->next!=first)
			last=last->next;

		NODE temp=first;
		if(first==last){
			printf("Deleted element: %d\n",temp->data);
			free(temp);
			return NULL;
		}
		first=first->next;
		last->next=first;
		printf("Deleted element: %d\n",temp->data);
		free(temp);
		return first;
	}
	NODE curr=first;
	int count = 1;
	while(count<pos-1&&curr->next!=first){
		curr=curr->next;
		count++;
	}
		printf("Position not found\n");
	}else{
		NODE temp=curr->next;
		curr->next=temp->next;
		printf("Deleted element: %d\n",temp->data);
		free(temp);
	}
	return first;
}
void traverseListInCLL(NODE first){
	if(first==NULL){
		printf("CLL is empty\n");
		return;
	}
	NODE curr=first;

	do{
		printf("%d --> ",curr->data);
		curr=curr->next;
	}while(curr!=first);
	printf("\n");
}
NODE reverseCLL(NODE first){
	if(first==NULL){
		printf("CLL is empty\n");
		return NULL;
	}
	NODE prev=NULL,curr=first,next=NULL;
	NODE last=first;
	while(last->next!=first)
		last=last->next;
	do{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}while(curr!=first);
	first->next=prev;
	first=prev;

	return first;
}
void main() {
    NODE first = NULL;
    int x, pos, op;
    while (1) {
        printf("1.Insert 2.Delete 3.Display 4.Reverse 5.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 2:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                }
                break;
            case 5:
                exit(0);
        }
    }
}
