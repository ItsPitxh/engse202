#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a Node in Doubly Linked List
struct Node {
    int info;
    struct Node *llink;
    struct Node *rlink;
};

// Global pointers
struct Node *H = NULL; // Head pointer

// Function prototypes
struct Node* Allocate();
void CreateNNode(int n);
void ShowAllNode();
void InsertAfter(int data);
void InsertBefore(int data);
void DeleteBefore(int data);
void DeleteSelf(int data);
void DeleteAfter(int data);

// Allocate memory for a new node
struct Node* Allocate() {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if (!temp) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return temp;
}

// Create N Nodes with random data
void CreateNNode(int n) {
    struct Node *H1 = NULL, *p = NULL;
    srand(time(NULL)); // Seed for random numbers
    for (int i = 1; i <= n; i++) {
        p = Allocate();
        p->info = 1 + rand() % 99; // Random number between 1 and 99
        p->llink = H1;
        p->rlink = NULL;
        if (H1) {
            H1->rlink = p;
        } else {
            H = p; // Set head pointer
        }
        H1 = p;
    }
}

// Display all nodes in the list
void ShowAllNode() {
    struct Node *p = H;
    int i = 1;
    printf("\nLinked List:\n");
    if (!p) {
        printf("The list is empty.\n");
        return;
    }
    while (p) {
        printf("%d) Address: %p, LLINK: %p, INFO: %d, RLINK: %p\n", i, p, p->llink, p->info, p->rlink);
        p = p->rlink;
        i++;
    }
}

// Insert a node after a specific node
void InsertAfter(int data) {
    struct Node *p = H;
    while (p) {
        if (p->info == data) {
            struct Node *newNode = Allocate();
            printf("Enter data to insert after %d: ", data);
            scanf("%d", &newNode->info);
            newNode->rlink = p->rlink;
            newNode->llink = p;
            if (p->rlink) {
                p->rlink->llink = newNode;
            }
            p->rlink = newNode;
            return;
        }
        p = p->rlink;
    }
    printf("Data %d not found in the list.\n", data);
}

// Insert a node before a specific node
void InsertBefore(int data) {
    struct Node *p = H;
    while (p) {
        if (p->info == data) {
            struct Node *newNode = Allocate();
            printf("Enter data to insert before %d: ", data);
            scanf("%d", &newNode->info);
            newNode->rlink = p;
            newNode->llink = p->llink;
            if (p->llink) {
                p->llink->rlink = newNode;
            } else {
                H = newNode; // Update head pointer
            }
            p->llink = newNode;
            return;
        }
        p = p->rlink;
    }
    printf("Data %d not found in the list.\n", data);
}

// Delete the node before a specific node
void DeleteBefore(int data) {
    struct Node *p = H;
    while (p) {
        if (p->info == data) {
            if (!p->llink) {
                printf("No node exists before %d.\n", data);
                return;
            }
            struct Node *temp = p->llink;
            if (temp->llink) {
                temp->llink->rlink = p;
            } else {
                H = p; // Update head pointer
            }
            p->llink = temp->llink;
            free(temp);
            return;
        }
        p = p->rlink;
    }
    printf("Data %d not found in the list.\n", data);
}

// Delete the node itself
void DeleteSelf(int data) {
    struct Node *p = H;
    while (p) {
        if (p->info == data) {
            if (p->llink) {
                p->llink->rlink = p->rlink;
            } else {
                H = p->rlink; // Update head pointer
            }
            if (p->rlink) {
                p->rlink->llink = p->llink;
            }
            free(p);
            return;
        }
        p = p->rlink;
    }
    printf("Data %d not found in the list.\n", data);
}

// Delete the node after a specific node
void DeleteAfter(int data) {
    struct Node *p = H;
    while (p) {
        if (p->info == data) {
            if (!p->rlink) {
                printf("No node exists after %d.\n", data);
                return;
            }
            struct Node *temp = p->rlink;
            p->rlink = temp->rlink;
            if (temp->rlink) {
                temp->rlink->llink = p;
            }
            free(temp);
            return;
        }
        p = p->rlink;
    }
    printf("Data %d not found in the list.\n", data);
}

// Main function
int main() {
    int n = 10, data;
    char choice;

    printf("Creating a doubly linked list with %d nodes.\n", n);
    CreateNNode(n);
    ShowAllNode();

    while (1) {
        printf("\nMENU: [B: Insert Before | A: Insert After | O: Delete Before | X: Delete Itself | D: Delete After | E: Exit]\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'B':
                printf("Enter the data to insert before: ");
                scanf("%d", &data);
                InsertBefore(data);
                ShowAllNode();
                break;

            case 'A':
                printf("Enter the data to insert after: ");
                scanf("%d", &data);
                InsertAfter(data);
                ShowAllNode();
                break;

            case 'O':
                printf("Enter the data to delete before: ");
                scanf("%d", &data);
                DeleteBefore(data);
                ShowAllNode();
                break;

            case 'X':
                printf("Enter the data to delete itself: ");
                scanf("%d", &data);
                DeleteSelf(data);
                ShowAllNode();
                break;

            case 'D':
                printf("Enter the data to delete after: ");
                scanf("%d", &data);
                DeleteAfter(data);
                ShowAllNode();
                break;

            case 'E':
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}