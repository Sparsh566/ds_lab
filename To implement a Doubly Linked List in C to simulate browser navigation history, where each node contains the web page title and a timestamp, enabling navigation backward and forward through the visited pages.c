#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node {
    char title[100];
    char timestamp[100];
    struct Node* prev;
    struct Node* next;
};

struct Node* current = NULL;

// Function to get current timestamp
void getTimestamp(char* buffer) {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    strftime(buffer, 100, "%Y-%m-%d %H:%M:%S", t);
}

// Function to create a new node
struct Node* createNode(char* title) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->title, title);
    getTimestamp(newNode->timestamp);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
// Visit a new page
void visitPage(char* title) {
    struct Node* newNode = createNode(title);
    if (current != NULL) {
        current->next = newNode;
        newNode->prev = current;
    }
    current = newNode;
    printf("Visited: %s at %s\n", current->title, current->timestamp);
}
// Go back
void goBack() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Moved back to: %s at %s\n", current->title, current->timestamp);
    } else {
        printf("No previous page.\n");
    }
}

// Go forward
void goForward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Moved forward to: %s at %s\n", current->title, current->timestamp);
    } else {
        printf("No next page.\n");
    }
}

// Display current page
void displayCurrentPage() {
    if (current != NULL) {
        printf("Current Page: %s at %s\n", current->title, current->timestamp);
    } else {
        printf("No page visited yet.\n");
    }
}

// Display full history
void displayHistory() {
    struct Node* temp = current;
    while (temp != NULL && temp->prev != NULL) {
        temp = temp->prev;
    }

    printf("---- Browsing History ----\n");
    while (temp != NULL) {
        printf("%s at %s\n", temp->title, temp->timestamp);
        temp = temp->next;
    }
    printf("--------------------------\n");
}
int main() {
    int choice;
    char title[100];

    while (1) {
        printf("\n1. Visit New Page\n2. Go Back\n3. Go Forward\n4. Display Current Page\n5. View Full History\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter page title: ");
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = 0; // remove newline
                visitPage(title);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                displayCurrentPage();
                break;
            case 5:
                displayHistory();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
