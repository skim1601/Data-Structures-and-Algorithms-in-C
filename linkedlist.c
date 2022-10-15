#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

typedef struct linkedList{
   Node* head; 
} LinkedList;


Node* createNode(int data){
    Node* newNode = (Node *) malloc (sizeof(Node));
    if (newNode != NULL){
        newNode -> data = data;
        newNode -> next = NULL;
    }
}

bool insertAtFront (LinkedList* list, int data){
    Node* newNode = createNode(data);
    if (!newNode){
        return false;
    }

    newNode -> next = list -> head;
    list -> head = newNode;
    return true;
}

void initList(LinkedList *list){
    list -> head = NULL;
}

bool isEmpty(LinkedList *list){
    if (list -> head == NULL){
        return true;
    } else{
        return false;
    }
}

void printList(LinkedList *list){
    Node * current = list -> head;

    while (current != NULL){
        printf("%d ", current -> data);
        current = current -> next;
    }
}

Node *findFirstNode (LinkedList * list, int value){
    Node * current = list -> head;

    while (current != NULL && current -> data != value){
        current = current -> next;
    }

    return current;
}

bool insertAtBack (LinkedList *list, int value){
    Node* current = list -> head;
    while (current -> next != NULL){
        current = current -> next;
    }
    
    current -> next = createNode(value);

    if (current -> next == NULL){
        return false;
    }

    return true;
}

bool insertIntoIncreasingList(LinkedList *orderedList, int value){
    if (isEmpty(orderedList) || orderedList -> head -> data > value){
       return insertAtFront(orderedList, value);
    }
    
    Node * current = orderedList -> head;
    while (current -> next != NULL && current -> next -> data < value){
        current = current -> next; 
    }

    Node* newNode = createNode(value);
    if (newNode == NULL){
        return false;
    }

    newNode -> next = current -> next;
    current -> next = newNode; 

    return true;
}

void deleteFront(LinkedList* list){
    if (isEmpty(list)){
        return;
    }

    Node* newHead = list -> head -> next;
    free(list -> head);
    list -> head = newHead;
}

void deleteBack(LinkedList *list){
    if (isEmpty(list)){
        return;
    }

    if (list -> head -> next == NULL){
        deleteFront(list);
        return;
    }

    Node* current = list -> head;
    while (current -> next -> next != NULL){
        current = current -> next;
    }

    free(current -> next);
    current -> next = NULL;
}

int deleteAllNodes(LinkedList *list){
    int count = 0;

    while(!isEmpty(list)){
        deleteFront(list);
        count++;
    }

    list -> head = NULL;
    return count;
}

bool deleteFirstMatch(LinkedList *list, int value){
    if (isEmpty(list)){
        return false;
    }

    if (list -> head -> data == value){
        deleteFront(list);
        return true;
    }

    Node* current = list -> head;

    while (current -> next != NULL && current -> next -> data != value){
        current = current -> next;
    }

    if (current -> next == NULL){
        return false;
    }

    Node* nextNext = current -> next -> next;
    free(current -> next);
    current -> next = nextNext;
}

int deleteAllMatches(LinkedList *list, int value){
    int numDeleted = 0;

    while(deleteFirstMatch(list, value)){
        numDeleted++;
    }

    return numDeleted;
}

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

int main(void){
    LinkedList list;

    initList(&list);
    insertAtFront(&list, 4);
    insertAtFront(&list, 99);
    insertAtFront(&list, 2);
    insertAtFront(&list, 3);
    bubbleSortLinkedList(&list);
    printList(&list);
    printf("\n%d", deleteAllNodes(&list));
}