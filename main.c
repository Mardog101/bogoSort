#include <stdlib.h> 
#include <stdio.h>
#include <time.h>

void readArr(int *arr, int length) {
  for (int i = 0; i < length; i++) {
    scanf("%d", &arr[i]);
  }
}

void printArr(int *arr, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
} 

int isSorted(int *arr, int length) {
  for (int i = 1; i < length; i++) {
    if (arr[i-1]>arr[i]) {
      return 0;
    }
  }
  return 1;
}

void bogoSort(int *arr, int length) {
  int x = 0;
  time_t t;

  srand((unsigned) time(&t));
  
  while (!isSorted(arr, length)) {
    int temp, rnd;

    for (int i = 0; i < length; ++i) {
      rnd = rand() % length;
      temp = arr[i];
      arr[i] = arr[rnd];
      arr[rnd] = temp;
    }
    printf("%d\t %d\t", x++, rnd);
    printArr(arr, length);    
  }
}

int main(int argc, char *argv[]) {
  int length;
  scanf("%d\n", &length);
  int *arr = malloc(length*sizeof(int));
  
  readArr(arr, length);

  printf("Computing");

  bogoSort(arr, length);

  printArr(arr, length);

  return 0;
}
