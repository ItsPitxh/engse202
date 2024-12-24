/* Program create DOUBLY CIRCULAR LINKED LIST by...
1. Create Node N Nodes
2. Insert node before/after data as defined
3. Delete node before/itself/after data as defined
4. Show address of Node
Note.- Not allow to delete the HEAD Node
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define HeadInfo -999 // Define data of Head Node

struct Node {
    int info;
    struct Node *llink;
    struct Node *rlink;
};

struct Node *H, *H1, *p, *q; // Declare pointer node
int i, j, k, n, data;
char ch;

Node *Allocate() {
    struct Node *temp;
    temp = (Node*)malloc(sizeof(Node)); // Allocate node
    return temp;
}

void CreateNNode(int n) {
    int i, temp;
    H1 = H; // Start H1 at Head
    for (i = 1; i <= n; i++) {
        p = Allocate(); // Allocate New Node
        temp = 1 + rand() % 99; // Random difference number 1..99
        p->info = temp;
        H1->rlink = p; 
        p->llink = H1; 
        H1 = p; 
        H1->rlink = H;
        H->llink = H1;
    }
}

void ShowAllNode() {
    printf("H = %x\n", H);
    p = H;
    i = 1;

    if (p->rlink != H) {
        p = p->rlink;
        while (p != H) {
            printf("%d) : %x\t", i, p);
            printf("LLINK : %x\t", p->llink);
            printf("INFO : %d\t", p->info);
            printf("RLINK : %x\n", p->rlink);
            p = p->rlink;
            i++;
        }
    }
}

void InsertAfter(int data1) {
    int temp;
    if (H->rlink == H) {
        printf("Linked List have no node!!..\n");
    } else {
        H1 = H->rlink;
        while (H1->info != HeadInfo) {
            if (H1->info == data1) {
                p = Allocate();
                printf("\nInsert data : ");
                scanf("%d", &temp);
                p->info = temp;

                if (H1->rlink == H) {
                    p->rlink = H;
                    H->llink = p;
                } else {
                    p->rlink = H1->rlink;
                    H1->rlink->llink = p;
                }

                p->llink = H1;
                H1->rlink = p;
            }
            H1 = H1->rlink;
        }
    }
}

void InsertBefore(int data1) {
    int temp;
    if (H->rlink == H) {
        printf("Linked List have no node!!..\n");
    } else {
        H1 = H->rlink;
        while (H1->info != HeadInfo) {
            if (H1->info == data1) {
                p = Allocate();
                printf("\nInsert data : ");
                scanf("%d", &temp);
                p->info = temp;

                if (H1->llink == H) {
                    p->llink = H;
                    H->rlink = p;
                } else {
                    H1->llink->rlink = p;
                    p->llink = H1->llink;
                }

                H1->llink = p;
                p->rlink = H1;
            }
            H1 = H1->rlink;
        }
    }
}

void DeleteBefore(int data1) {
    if (H->rlink == H) {
        printf("Linked List have NO NODE!!..\n");
    } else {
        H1 = H->rlink;
        while (H1->info != HeadInfo) {
            if (H1->info == data1) {
                if (H1->llink == H) {
                    printf("No more node before here, Can't delete it!!!\n");
                } else {
                    p = H1->llink;
                    H1->llink = p->llink;
                    p->llink->rlink = H1;
                    free(p);
                }
            }
            H1 = H1->rlink;
        }
    }
}

void DeleteSelf(int data1) {
    if (H->rlink == H) {
        printf("Linked List have NO NODE!!..\n");
    } else {
        H1 = H->rlink;
        while (H1->info != HeadInfo) {
            if (H1->info == data1) {
                p = H1;

                if (p->llink == H && p->rlink == H) {
                    H->llink = H;
                    H->rlink = H;
                } else {
                    p->llink->rlink = p->rlink;
                    p->rlink->llink = p->llink;
                }

                free(p);
            }
            H1 = H1->rlink;
        }
    }
}

void DeleteAfter(int data1) {
    if (H->rlink == H) {
        printf("Linked List have NO NODE!!..\n");
    } else {
        H1 = H->rlink;
        while (H1->info != HeadInfo) {
            if (H1->info == data1) {
                if (H1->rlink == H) {
                    printf("No more node from here, Can't delete it!!!\n");
                } else {
                    p = H1->rlink;
                    H1->rlink = p->rlink;
                    p->rlink->llink = H1;
                    free(p);
                }
            }
            H1 = H1->rlink;
        }
    }
}

int main() {
    p = Allocate();
    p->info = HeadInfo;
    p->llink = p;
    p->rlink = p;
    H = p;

    n = 10;
    CreateNNode(n);

    printf("PROGRAM DOUBLY CIRCULAR LINKED LIST \n");
    printf("================================== \n");
    printf("All Data in Linked List \n");
    ShowAllNode();

    ch = ' ';
    while (ch != 'E') {
        printf("MENU>> [B:InsertBefore A:InsertAfter\n");
        printf(" O:DeleteBefore X:DeleteItself D:DeleteAfter E:Exit]\n");
        ch = getch();
        switch (ch) {
            case 'B':
                printf("\nInsert Before data : ");
                scanf("%d", &data);
                InsertBefore(data);
                printf("\nAll Data in Linked List AFTER INSERTED\n");
                ShowAllNode();
                break;
            case 'A':
                printf("\nInsert After data : ");
                scanf("%d", &data);
                InsertAfter(data);
                printf("\nAll Data in Linked List AFTER INSERTED\n");
                ShowAllNode();
                break;
            case 'O':
                printf("\nDelete Before data : ");
                scanf("%d", &data);
                DeleteBefore(data);
                printf("\nAll Data in Linked List AFTER DELETED\n");
                ShowAllNode();
                break;
            case 'X':
                printf("\nDelete ItSelf data : ");
                scanf("%d", &data);
                DeleteSelf(data);
                printf("\nAll Data in Linked List ITSELF DELETED\n");
                ShowAllNode();
                break;
            case 'D':
                printf("\nDelete After data : ");
                scanf("%d", &data);
                DeleteAfter(data);
                printf("\nAll Data in Linked List AFTER DELETED\n");
                ShowAllNode();
                break;
        }
    }
    return 0;
}#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *llink;
    struct Node *rlink;
};

struct Node *H = NULL, *H1 = NULL, *p = NULL, *q = NULL; 
int i, j, k, n, data;
char ch;

struct Node *Allocate() {
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    return temp;
}

void CreateNNode(int n) {
    int temp;
    H = NULL;
    H1 = NULL;
    for (i = 1; i <= n; i++) {
        p = Allocate();
        temp = 1 + rand() % 99;
        p->info = temp;

        if (i == 1) {
            H = p;
        } else {
            H1->rlink = p;
        }

        p->llink = H1;
        H1 = p;
        H1->rlink = NULL;
    }
}

void ShowAllNode() {
    printf("H = %p\n", H);
    p = H;
    i = 1;

    while (p != NULL) {
        printf("%d) : %p\tLLINK : %p\tINFO : %d\tRLINK : %p\n", 
            i, p, p->llink, p->info, p->rlink);
        p = p->rlink;
        i++;
    }
}

void InsertAfter(int data1) {
    int temp;

    if (H == NULL) {
        printf("Linked List has no nodes!\n");
        return;
    }

    H1 = H;
    while (H1 != NULL) {
        if (H1->info == data1) {
            p = Allocate();
            printf("\nInsert data: ");
            scanf("%d", &temp);
            p->info = temp;

            if (H1->rlink == NULL) {
                p->rlink = NULL;
            } else {
                p->rlink = H1->rlink;
                H1->rlink->llink = p;
            }

            p->llink = H1;
            H1->rlink = p;
        }

        H1 = H1->rlink;
    }
}

void InsertBefore(int data1) {
    int temp;

    if (H == NULL) {
        printf("Linked List has no nodes!\n");
        return;
    }

    H1 = H;
    while (H1 != NULL) {
        if (H1->info == data1) {
            p = Allocate();
            printf("\nInsert data: ");
            scanf("%d", &temp);
            p->info = temp;

            if (H1->llink == NULL) {
                p->llink = NULL;
                H = p;
            } else {
                H1->llink->rlink = p;
                p->llink = H1->llink;
            }

            H1->llink = p;
            p->rlink = H1;
        }

        H1 = H1->rlink;
    }
}

void DeleteBefore(int data1) {
    if (H == NULL) {
        printf("Linked List has no nodes!\n");
        return;
    }

    H1 = H;
    while (H1 != NULL) {
        if (H1->info == data1) {
            if (H1->llink == NULL) {
                printf("No node before this, can't delete!\n");
            } else {
                p = H1->llink;
                if (p->llink == NULL) {
                    H1->llink = NULL;
                    H = H1;
                } else {
                    H1->llink = p->llink;
                    p->llink->rlink = H1;
                }

                free(p);
            }
        }

        H1 = H1->rlink;
    }
}

void DeleteSelf(int data1) {
    if (H == NULL) {
        printf("Linked List has no nodes!\n");
        return;
    }

    H1 = H;
    while (H1 != NULL) {
        if (H1->info == data1) {
            p = H1;

            if (p->llink == NULL && p->rlink == NULL) {
                H = NULL;
            } else if (p->llink == NULL) {
                H = p->rlink;
                H->llink = NULL;
            } else if (p->rlink == NULL) {
                p->llink->rlink = NULL;
            } else {
                p->llink->rlink = p->rlink;
                p->rlink->llink = p->llink;
            }

            free(p);
        }

        H1 = H1->rlink;
    }
}

void DeleteAfter(int data1) {
    if (H == NULL) {
        printf("Linked List has no nodes!\n");
        return;
    }

    H1 = H;
    while (H1 != NULL) {
        if (H1->info == data1) {
            if (H1->rlink == NULL) {
                printf("No node after this, can't delete!\n");
            } else {
                p = H1->rlink;

                if (p->rlink == NULL) {
                    H1->rlink = NULL;
                } else {
                    H1->rlink = p->rlink;
                    p->rlink->llink = H1;
                }

                free(p);
            }
        }

        H1 = H1->rlink;
    }
}

int main() {
    n = 10;
    CreateNNode(n);

    printf("PROGRAM DOUBLY LINKED LIST\n");
    printf("==========================\n");
    printf("All Data in Linked List\n");
    ShowAllNode();

    while (1) {
        printf("MENU >> [B: InsertBefore A: InsertAfter\n");
        printf("O: DeleteBefore X: DeleteSelf\n");
        printf("D: DeleteAfter E: Exit]\n");

        ch = getchar();
        if (ch == 'E') break;

        switch (ch) {
            case 'B':
                printf("\nInsert Before data: ");
                scanf("%d", &data);
                InsertBefore(data);
                printf("\nAll Data in Linked List AFTER INSERTION\n");
                ShowAllNode();
                break;

            case 'A':
                printf("\nInsert After data: ");
                scanf("%d", &data);
                InsertAfter(data);
                printf("\nAll Data in Linked List AFTER INSERTION\n");
                ShowAllNode();
                break;

            case 'O':
                printf("\nDelete Before data: ");
                scanf("%d", &data);
                DeleteBefore(data);
                printf("\nAll Data in Linked List AFTER DELETION\n");
                ShowAllNode();
                break;

            case 'X':
                printf("\nDelete Self data: ");
                scanf("%d", &data);
                DeleteSelf(data);
                printf("\nAll Data in Linked List AFTER SELF-DELETION\n");
                ShowAllNode();
                break;

            case 'D':
                printf("\nDelete After data: ");
                scanf("%d", &data);
                DeleteAfter(data);
                printf("\nAll Data in Linked List AFTER DELETION\n");
                ShowAllNode();
                break;
        }
    }

    return 0;
}