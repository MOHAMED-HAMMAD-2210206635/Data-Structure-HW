#include <stdio.h>

void insert(int a[], int *n, int val, int pos) {
    for (int i = *n; i > pos; i--) {
        a[i] = a[i - 1];
    }
    a[pos] = val;
    (*n)++;
}

void remove_at(int a[], int *n, int pos) {
    for (int i = pos; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }
    (*n)--;
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int size = 5;

    // insert 25 at index 2
    insert(arr, &size, 25, 2);

    printf("After Insert: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    // remove element at index 3
    remove_at(arr, &size, 3);

    printf("After Delete: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
