// Different sorting mechanisms

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void printList(int list[], int length){
    for (int i = 0; i < length; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}

// O(n^2), up to n^2 comparisons
void insertionSort(int list[], int length){
    printf("Before: ");
    printList(list, 9);

    for (int i = 1; i < length; i++){
        int value = list[i];
        int j;
        for (j = i; value < list[j - 1] && j > 0; j--){
            list[j] = list[j - 1];
        }

        list[j] = value;
    }
    printf("After: ");
    printList(list, 9);
}

void swap (int list[], int a, int b){
    int temp = list[a];
    list[a] = list[b];
    list[b] = temp;
}

void selectionSort(int list[], int length){
    for (int top = length - 1; top > 0; top--){
        int max = 0;
        
        for (int i = 1; i <= top; i++){
            if (list[i] > list[max]){
                max = i;
            }
        }

        swap(list, max, top);
    }

    printf("After: ");
    printList(list, 9);
}

int partition(int list[], int low, int high){
    int pivot = low, left = low + 1, right = high;
    while (true){
        while (left <= right && list [left] <= list[pivot]){
            left++;
        }
        while (left <= right && list[right] > list[pivot]){
            right--;
        }

        if (left <= right){
            swap(list, left, right);
        } else {
            swap (list, pivot, right);
            return right;
        }
    }
}

void quickSortHelper(int list[], int low, int high){
    if (low < high){
        int pivot = partition(list, low, high);
        quickSortHelper(list, low, pivot - 1);
        quickSortHelper(list, pivot + 1, high);
    }
}

void quickSort(int list[], int length){
    quickSortHelper(list, 0, length - 1);
}

int main(void){
    int list[] = {5,1,2,6,9,3,4,8,7};
    insertionSort(list, 9);
    //selectionSort(list, 9);
    //quickSort(list, 9);
    printf("After: ");
    printList(list, 9);
}

