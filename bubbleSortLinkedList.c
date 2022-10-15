#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct linkedList {
    Node *head;
} LinkedList;

void bubbleSortLinkedList (LinkedList *list){
    int sortedCount = 0;

    if (list -> head == NULL || list -> head -> next == NULL){
        return;
    }

    do {
        sortedCount = 0;
        Node* current = list -> head;
        while (current -> next != NULL){
            if (current -> data > current -> next -> data){
                int temp = current -> data;
                current -> data = current -> next -> data;
                current -> next -> data = temp;
                sortedCount++;
            }  
            current = current -> next;
        }
    } while (sortedCount != 0);
}