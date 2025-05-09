#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list
struct Node* createList() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int data;
    
    printf("Enter elements (-1 to end): ");
    
    while (1) {
        scanf("%d", &data);
        
        if (data == -1)
            break;
            
        newNode = createNode(data);
        
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    
    return head;
}

// Function to display a linked list
void displayList(struct Node* head, char* listName) {
    printf("%s: ", listName);
    
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to concatenate two linked lists
struct Node* concatenate(struct Node* list1, struct Node* list2) {
    // If first list is empty, return second list
    if (list1 == NULL)
        return list2;
    
    // If second list is empty, return first list
    if (list2 == NULL)
        return list1;
    
    // Create a new list to store the concatenated result
    struct Node *result = NULL, *temp = NULL;
    struct Node *current1 = list1;
    
    // Copy the first list
    while (current1 != NULL) {
        struct Node* newNode = createNode(current1->data);
        
        if (result == NULL) {
            result = newNode;
            temp = result;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
        
        current1 = current1->next;
    }
    
    // Append the second list
    struct Node* current2 = list2;
    while (current2 != NULL) {
        struct Node* newNode = createNode(current2->data);
        temp->next = newNode;
        temp = newNode;
        current2 = current2->next;
    }
    
    return result;
}

// Function to free memory allocated for a linked list
void freeList(struct Node* head) {
    struct Node* temp;
    
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL, *concatenatedList = NULL;
    int choice;
    
    do {
        printf("1. Create SLL1\n");
        printf("2. Create SLL2\n");
        printf("3. Display SLL1\n");
        printf("4. Display SLL2\n");
        printf("5. Concatenation\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Free existing list if any
                if (list1 != NULL) {
                    freeList(list1);
                }
                printf("Enter elements for SLL1 ");
                list1 = createList();
                break;
                
            case 2:
                // Free existing list if any
                if (list2 != NULL) {
                    freeList(list2);
                }
                printf("Enter elements for SLL2 ");
                list2 = createList();
                break;
                
            case 3:
                displayList(list1, "SLL1");
                break;
                
            case 4:
                displayList(list2, "SLL2");
                break;
                
            case 5:
                // Free existing concatenated list if any
                if (concatenatedList != NULL) {
                    freeList(concatenatedList);
                }
                concatenatedList = concatenate(list1, list2);
                printf("Concatenated List: ");
                displayList(concatenatedList, "Concatenated List");
                break;
                
            case 6:
                // Free all allocated memory before exiting
                if (list1 != NULL) freeList(list1);
                if (list2 != NULL) freeList(list2);
                if (concatenatedList != NULL) freeList(concatenatedList);
                printf("Exiting program\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}
