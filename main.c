#include <stdio.h>

void swap(int* arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void bubbleSort(int arr[], int n, int* swaps) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr, j, j + 1);
        (*swaps)++;
      }
    }
  }
}

void selectionSort(int arr[], int n, int* swaps) {
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
        (*swaps)++;
      }
    }
    swap(arr, min_idx, i);;
  }
}

int main() {
  int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
  int n1 = sizeof(array1) / sizeof(array1[0]);
  int n2 = sizeof(array2) / sizeof(array2[0]);

  int swaps1 = 0;
  bubbleSort(array1, n1, &swaps1);

  int swaps2 = 0;
  bubbleSort(array2, n2, &swaps2);

  printf("array1:\n");
  for (int i = 0; i < n1; i++) {
    printf("%d: # of times %d is swapped\n", array1[i], i);
  }
  printf("total # of swaps: %d\n\n", swaps1);

  printf("array2:\n");
  
  for (int i = 0; i < n2; i++) {
    printf("%d: # of times %d is swapped\n", array2[i], i);
  }
  printf("total # of swaps: %d\n", swaps2);

  return 0;
}
