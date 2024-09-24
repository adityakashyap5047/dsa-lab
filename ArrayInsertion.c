// Insert or element in the array

#include <stdio.h>

void travesedArray(int arr[], int *n){
    int i;

    for(i = 0; i < *n; i++){
        printf("%d ", arr[i]);
    }
}

int insertAtEnd(int arr[], int *n, int element, int max) {
    if(*n == max) {
        printf("Array is overflow");
        return -1;
    }

    arr[*n] = element;
    (*n)++;
    return 0;
}

int insertAtBegging(int arr[], int *n, int element, int max) {

    int i;

    if(*n == max) {
        printf("Array is overflow");
        return -1;
    }

    for(i = *n; i >= 0; i --) {
        arr[i + 1] = arr[i];
    }

    arr[0] = element;

    (*n)++;
    return 0;
}

int insertAtIndex(int arr[], int pos, int *n, int element, int max) {
    
    int i;

    if(*n == max) {
        printf("Array is overflow");
        return -1;
    }

    for(i = *n; i >= pos; i --) {
        arr[i + 1] = arr[i];
    }

    arr[pos] = element;

    (*n)++;
    return 0;
}

int deleteElementAtEnd(int arr[], int *n){

    (*n)--;

    return 0;

}

int deleteElementAtIndex(int arr[], int idx, int *n){

    int i;

    for(i = idx; i < *n; i++) {
        arr[i] = arr[i+1];
    }

    (*n)--;
    return 0;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5};
    int element, idx, n = 5;
    int max = 10;

    printf("Original array: ");
    travesedArray(arr, &n);
    printf("\n");

    element = 90;
    insertAtEnd(arr, &n, element, max);
    printf("Array after insertion of %d at end: ", element);
    travesedArray(arr, &n);
    printf("\n");

    element = 34;
    insertAtBegging(arr, &n, element, max);
    printf("Array after insertion of %d at beggining: ", element);
    travesedArray(arr, &n);
    printf("\n");

    idx = 3;
    element = 40;
    insertAtIndex(arr, idx, &n, element, max);
    printf("Array after insertion of %d at index %d: ", element, idx);
    travesedArray(arr, &n);
    printf("\n");

    idx = 7;
    deleteElementAtIndex(arr, idx, &n);
    printf("Array after deletion of element at index %d: ", idx);
    travesedArray(arr, &n);
    printf("\n");

    deleteElementAtEnd(arr, &n);
    travesedArray(arr, &n);

    return 0;
}