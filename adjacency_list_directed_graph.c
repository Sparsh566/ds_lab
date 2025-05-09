#include <stdio.h>
#include <stdlib.h>

struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

struct Graph {
    int numVertices;
    struct AdjList* array;
};

struct AdjListNode* createNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int n) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    graph->numVertices = n;
    
    graph->array = (struct AdjList*)malloc(n * sizeof(struct AdjList));
    if (graph->array == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    for (int i = 0; i < n; i++) {
        graph->array[i].head = NULL;
    }
    
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    if (src <= 0 || src > graph->numVertices || dest <= 0 || dest > graph->numVertices) {
        printf("Invalid vertex\n");
        return;
    }
    
    src--;
    dest--;
    
    struct AdjListNode* newNode = createNode(dest);
    
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void insertVertex(struct Graph* graph) {
    // Increase number of vertices
    graph->numVertices++;
    
    graph->array = (struct AdjList*)realloc(graph->array, graph->numVertices * sizeof(struct AdjList));
    if (graph->array == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    graph->array[graph->numVertices - 1].head = NULL;
}

void deleteEdge(struct Graph* graph, int src, int dest) {
 
    if (src <= 0 || src > graph->numVertices || dest <= 0 || dest > graph->numVertices) {
        printf("Invalid vertex\n");
        return;
    }
    
   
    src--;
    dest--;
    
    struct AdjListNode* temp = graph->array[src].head;
    struct AdjListNode* prev = NULL;
    
  
    if (temp != NULL && temp->dest == dest) {
        graph->array[src].head = temp->next;
        free(temp);
        return;
    }
    
   
    while (temp != NULL && temp->dest != dest) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Edge not found\n");
        return;
    }
    
    prev->next = temp->next;
    free(temp);
}

void deleteVertex(struct Graph* graph, int vertex) {
    if (vertex <= 0 || vertex > graph->numVertices) {
        printf("Invalid vertex\n");
        return;
    }
    
    vertex--;
    
    for (int i = 0; i < graph->numVertices; i++) {
        if (i != vertex) {
            struct AdjListNode* temp = graph->array[i].head;
            struct AdjListNode* prev = NULL;
            
            while (temp != NULL) {
                if (temp->dest == vertex) {
                    // Delete this edge
                    if (prev == NULL) {
                        graph->array[i].head = temp->next;
                        free(temp);
                        temp = graph->array[i].head;
                    } else {
                        prev->next = temp->next;
                        free(temp);
                        temp = prev->next;
                    }
                } else if (temp->dest > vertex) {
                    temp->dest--;
                    prev = temp;
                    temp = temp->next;
                } else {
                    prev = temp;
                    temp = temp->next;
                }
            }
        }
    }
    
    struct AdjListNode* temp = graph->array[vertex].head;
    while (temp != NULL) {
        struct AdjListNode* next = temp->next;
        free(temp);
        temp = next;
    }
    
    for (int i = vertex; i < graph->numVertices - 1; i++) {
        graph->array[i] = graph->array[i + 1];
    }
    
    graph->numVertices--;
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct AdjListNode* temp = graph->array[i].head;
        printf("%d=>", i + 1);  // Adjust for 1-based indexing in output
        
        while (temp) {
            printf("%d→", temp->dest + 1);  // Adjust for 1-based indexing in output
            temp = temp->next;
        }
        
        printf("\n");
    }
}

void freeGraph(struct Graph* graph) {
    if (graph == NULL) return;
    
    for (int i = 0; i < graph->numVertices; i++) {
        struct AdjListNode* temp = graph->array[i].head;
        while (temp) {
            struct AdjListNode* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    
    free(graph->array);
    
    free(graph);
}

int main() {
    int nVertices, nEdges;
    
    printf("Enter the number of vertices : ");
    scanf("%d", &nVertices);
    
    struct Graph* graph = createGraph(nVertices);
    
    printf("Enter the number of edges : ");
    scanf("%d", &nEdges);
    
    for (int i = 0; i < nEdges; i++) {
        int src, dest;
        printf("Enter source : ");
        scanf("%d", &src);
        printf("Enter destination : ");
        scanf("%d", &dest);
        addEdge(graph, src, dest);
    }
    
    int choice, src, dest, vertex;
    
    do {
        printf("1.Insert vertex 2.Insert edge 3.Delete vertex 4.Delete edge 5.Print adjacency list 6.Exit\n");
        printf("Enter your option : ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insertVertex(graph);
                printf("After inserting vertex the adjacency list is : \n");
                printGraph(graph);
                break;
                
            case 2:
                printf("Enter the source vertex of the edge : ");
                scanf("%d", &src);
                printf("Enter the destination vertex of the edge : ");
                scanf("%d", &dest);
                addEdge(graph, src, dest);
                printf("After inserting edge the adjacency list is : \n");
                printGraph(graph);
                break;
                
            case 3:
                printf("Enter the vertex to be deleted : ");
                scanf("%d", &vertex);
                deleteVertex(graph, vertex);
                printf("After deleting vertex the adjacency list is : \n");
                printGraph(graph);
                break;
                
            case 4:
                printf("Enter the source vertex of the edge : ");
                scanf("%d", &src);
                printf("Enter the destination vertex of the edge : ");
                scanf("%d", &dest);
                deleteEdge(graph, src, dest);
                printf("After deleting edge the adjacency list is : \n");
                printGraph(graph);
                break;
                
            case 5:
                printGraph(graph);
                break;
                
            case 6:
                freeGraph(graph);
                break;
                
            default:
                printf("Invalid option\n");
        }
    } while (choice != 6);
    
    return 0;
}
