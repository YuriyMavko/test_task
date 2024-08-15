#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int* array, int size) {
    int temp;
    int swap;
    for (int i = 0; i < size - 1; i++) {
        swap = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swap = 1;
            }
        }
        if (!swap) break;
    }
}
void findMissing(int arr[], int n) {
    int missingCount = 0;
    int prev = arr[0];
    for (int i = 1; i < n; i++) {
        int diff = arr[i] - prev;
        if (diff > 1) {
            if (missingCount < 2) {
                printf("Missing are: ");
                for (int j = prev + 1; j < arr[i]; j++) {
                    printf("%d ", j);
                    missingCount++;
                    if (missingCount == 2) break;
                }
                printf("\n");
            }
        }
        prev = arr[i];
    }
}
int main() {
    int SIZE = 0;
    int* array;
    printf("Enter the size of the array: ");
    scanf_s("%d", &SIZE);
    if (SIZE < 2) {
        printf("Size must be at least 2\n");
        return 1;
    }
    int actualSize = SIZE - 2;
    array = (int*)malloc(actualSize * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }
    printf("Enter array:\n");
    for (int i = 0; i < actualSize; i++) {
        scanf_s("%d", &array[i]);
    }
    bubbleSort(array, actualSize);
    findMissing(array, actualSize);
    free(array);
    return 0;
}
