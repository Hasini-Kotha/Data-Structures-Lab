#ifndef SORTS_H
#define SORTS_H

#include <stdio.h>

// Bubble Sort
void bubblesort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

// Selection Sort
void selectionsort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int minindex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }
        int temp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort
void insertionsort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

#endif // SORTS_H
