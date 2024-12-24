#include <stdio.h>   // Use printf
#include <conio.h>   // Use getch
#include <stdlib.h>  // Use malloc

#define HeadData -999 // Special Data of Head Node

struct Node { // Declare structure of node
    int info;
    struct Node *link;
};

struct Node *H, *H1, *p, *q; // Declare pointer nodes
int i, j, k, n, data;
char ch;

Node *Allocate() { // Allocate 1 node from storage pool
    struct Node *temp;
    temp = (Node*)malloc(sizeof(Node)); // Allocate node by size declare
    return temp;
}

void CreateNNode(int n) { // Create N Nodes, put data, and link them
    int i, temp;
    H = p;
    H1 = p;
    for (i = 1; i <= n; i++) { // Count N Nodes
        p = Allocate(); // Allocate Node
        temp = 1 + rand() % 99; // Random difference number 1..99
        p->info = temp; // Put random data into node
        H1->link = p; // Let Last node point to new node
        H1 = p; // Let H1 point to new node
        H1->link = H; // Set link of H1 to HEAD for Circular Linked List
    }
}

void ShowAllNode() {
    printf("H = %x\n", H); // Display address of pointer H
    p = H->link; // Set start point of p pointer at first node
    i = 1; // Set start value of counter
    while (p->info != HeadData) { // While INFO is NOT HeadData
        printf("%d) : %x\t", i, p); // Show COUNTER and POINTER
        printf("INFO : %d\t", p->info); // Show INFO
        printf("LINK : %x\n", p->link); // Show LINK
        p = p->link; // Skip to next node
        i++; // Skip Counter
    }
}

void InsertAfter(int data1) {
    int temp; // Temporary variable
    if (H->link == H) { // If Link points back to HeadNode
        printf("Circular Linked List has no nodes!!..\n");
    } else {
        H1 = H->link; // Let H1 point at first node
        while (H1->info != HeadData) { // Search for the data while INFO <> HeadData
            if (H1->info == data1) { // If Found
                p = Allocate(); // Allocate one node from storage pool
                printf("\nInsert data : "); // Input data for insert
                scanf("%d", &temp); // Read from KBD
                p->info = temp; // Entry temporary data into INFO of node
                p->link = H1->link; // Change pointer 1st for insert node
                H1->link = p; // Change pointer 2nd for insert node
            }
            H1 = H1->link; // Skip H1 to next node
        }
    }
}

void DeleteAfter(int data1) {
    int temp; // Temporary variable
    if (H->link == H) { // If Link points back to HeadNode
        printf("Circular Linked List has no nodes!!..\n");
    } else {
        H1 = H->link; // Let H1 point at start node
        while (H1->info != HeadData) { // Search for the data while INFO <> HeadData
            if (H1->info == data1) { // If Found
                if (H1->link == H) { // If no more nodes
                    printf("This is the HEAD Node, Can't delete it!!!\n");
                } else {
                    p = H1->link; // Mark node for Delete
                    if (p->link == H) { // If p is the last node
                        H1->link = H; // Set link of H1 to Head node
                    } else {
                        H1->link = p->link; // Set link of H1 to the next node
                    }
                    free(p); // Free node to storage pool
                }
            }
            H1 = H1->link; // Skip H1 to next node
        }
    }
}

int main() { // MAIN Function
    p = Allocate(); // Create HEAD Node
    p->info = HeadData; // Assign Special data
    p->link = p; // Link back to itself
    n = 10; // Set amount of nodes
    CreateNNode(n); // Call Fn. Create N nodes
    printf("PROGRAM SINGLY CIRCULAR LINKED LIST \n");
    printf("======================================== \n");
    printf("All Data in Linked List \n");
    ShowAllNode(); // Call Fn. Show all nodes

    ch = ' ';
    while (ch != 'E') {
        printf("MENU : [I:Insert D:Delete E:Exit]");
        ch = getch();
        switch (ch) {
            case 'I':
                printf("\nInsert After data : "); // Input data for insert after
                scanf("%d", &data);
                InsertAfter(data); // Call Fn. Insert after data
                printf("\nAll Data in Linked List AFTER INSERTED\n");
                ShowAllNode(); // Call Fn. Show all nodes
                break;

            case 'D':
                printf("\nDelete After data : "); // Input data for Delete after
                scanf("%d", &data);
                DeleteAfter(data); // Call Fn. Delete after data
                printf("\nAll Data in Linked List AFTER DELETED\n");
                ShowAllNode(); // Call Fn. Show all nodes
                break;
        }
    }
    return 0;
}