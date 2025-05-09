#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int value) {
    // If tree is empty, create a new node as root
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        
        printf("%d ", root->data);
        
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        
        preorderTraversal(root->left);
        
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
 
        postorderTraversal(root->left);
        
        postorderTraversal(root->right);
        
        printf("%d ", root->data);
    }
}

int searchElement(struct Node* root, int value) {
    // Base case: root is NULL or value is found
    if (root == NULL) {
        return 0;
    }
    
    if (root->data == value) {
        return 1;
    }
    
    if (value < root->data) {
        return searchElement(root->left, value);
    } else {
        return searchElement(root->right, value);
    }
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        
        freeTree(root->right);
        
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;
    
    do {
        printf("1.Insert 2.Inorder Traversal 3.Preorder Traversal 4.Postorder Traversal 5.Search an element 6.Exit\n");
        printf("Enter your option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter an element to be inserted : ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Successfully inserted.\n");
                break;
                
            case 2:
                if (root == NULL) {
                    printf("Binary Search Tree is empty.\n");
                } else {
                    printf("Elements of the BST (in-order traversal): ");
                    inorderTraversal(root);
                    printf("\n");
                }
                break;
                
            case 3:
                if (root == NULL) {
                    printf("Binary Search Tree is empty.\n");
                } else {
                    printf("Elements of the BST (pre-order traversal): ");
                    preorderTraversal(root);
                    printf("\n");
                }
                break;
                
            case 4:
                if (root == NULL) {
                    printf("Binary Search Tree is empty.\n");
                } else {
                    printf("Elements of the BST (post-order traversal): ");
                    postorderTraversal(root);
                    printf("\n");
                }
                break;
                
            case 5:
                printf("Enter an element to be searched : ");
                scanf("%d", &value);
                if (searchElement(root, value)) {
                    printf("Element found in the binary search tree.\n");
                } else {
                    printf("Element not found in the binary search tree.\n");
                }
                break;
                
            case 6:
                // Free the memory before exiting
                freeTree(root);
                break;
                
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}
