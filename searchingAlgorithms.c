// Searching Algorithms
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Sequential Search
int sequentialSearch(int* list, int length, int data){
    for (int i = 0; i < length; i++){
        if (*(list + i) == data){
            return i;
        }
    }
    
    return -1;
}

// Sequential Search Recursive
int rSequentialSearchHelper(int* list, int length, int data, int location){
    if (location == length){
        return -1;
    }

    if (list[location] == data){
        return location;
    } 
    rSequentialSearchHelper(list, length, data, location + 1);
}

int rSequentialSearch(int* list, int length, int data){
    return rSequentialSearchHelper(list, length, data, 0);
}

int rBinarySearchHelper(int *list, int data, int low, int high){
    if (low > high){
        return -1;
    }

    int medium = (low + high) / 2;
    if (data > list[medium]){
        rBinarySearchHelper(list, data, medium + 1, high);
    } else if (data < list[medium]){
        rBinarySearchHelper(list, data, low, medium - 1);
    } else {
        return medium;
    }
}

int rBinarySearch (int* list, int length, int data){
    rBinarySearchHelper (list, data, 0, length - 1);
}

int binarySearch (int* list, int length, int data){
    int low = 0;
    int high = length - 1;

    while (low <= high){
        int middle = (high + low) / 2;
        if (data > list [middle]){
            low = middle + 1;
        } else if (data < list[middle]){
            high = middle - 1;
        } else{
            return middle;
        }
    }

    return -1;
}

int main(void){
    int dub[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("%d ", sequentialSearch(dub, 9, 3));
    printf("%d ", rSequentialSearch(dub, 9, 3));    
    printf("%d ", binarySearch(dub, 9, 8));
    printf("%d", rBinarySearch(dub, 9, 8));
}