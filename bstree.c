
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *left, *right;
} Node;

typedef struct binarySearchTree{
    Node* root;
} BSTree;

void initialize (BSTree *tree){
    tree -> root = NULL;
}

Node *createNode (int value){
    Node* newNode = (Node *) malloc(sizeof(Node));
    
    if (newNode != NULL){
        newNode -> data = value;
        newNode -> left = NULL;
        newNode -> right = NULL;
    }

    return newNode;
}

bool isEmpty (BSTree *tree){
    return (tree -> root == NULL);
}

Node* search (BSTree *tree, int value){
    if (isEmpty(tree)){
        return NULL;
    }

    Node* current = tree -> root;
    while (current != NULL && current -> data != value){
        if (value < current -> data){
            current = current -> left;
        } else if (value > current -> data){
            current = current -> right;
        }
    }

    return current;
}

bool doesExist (BSTree *tree, int value){
    if (search(tree, value) == NULL){
        return false;
    }
    return true;
}

void printHelper (Node* node){
    if (node == NULL){
        return;
    }

    printHelper(node -> left);
    printf("%d ", node -> data);
    printHelper(node -> right);
}

void print(BSTree *tree){
    printHelper(tree -> root);
}

bool insert(BSTree *tree, int value){
    Node* newNode = createNode(value);

    Node* current = tree -> root;
    Node* parent = NULL;

    while (current != NULL){
        parent = current;
        if (value < current -> data){
            current -> left;
        } else {
            current -> right;
        }
    }

    if (value > parent -> data){
        parent -> right = newNode;
        return (parent -> right != NULL);
    } else if (value <= parent -> data){
        parent -> left = newNode;
        return (parent -> left != NULL);
    }
    
}

Node* insertRecursivelyHelper(Node *node, int value){
    if (node == NULL){
        return createNode(value);
    }

    if (value <= node -> data){
        node -> left = insertRecursivelyHelper(node -> left, value);
    } else {
        node -> right = insertRecursivelyHelper(node -> right, value);
    }

    return node;
}

bool insertRecursive (BSTree *tree, int value){
    Node* inserted = insertRecursivelyHelper (tree -> root, value);
    tree -> root = inserted;
    return inserted != NULL;
}

int main(void){
    
}