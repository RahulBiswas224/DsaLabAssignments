#include <stdio.h>

void insertElement(int arr[], int *n, int pos, int element) {
    for (int i = *n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = element;
    (*n)++;
}

void deleteElement(int arr[], int *n, int pos) {
    for (int i = pos - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int n = 5;

    // Example: Insert 10 at index 2 (position 3)
    insertElement(arr, &n, 3, 10);

    // Example: Delete element at index 2 (position 3)
    deleteElement(arr, &n, 3);

    return 0;
}