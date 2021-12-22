#include <stdio.h>
#include <stdlib.h>

int size = 0;

int getMeanValue(int *array){
    int meanValue = 0;
    int* current = array;
    for (int i = 0; i < size; i++){
        meanValue += *current;
        current ++;
    }
    return meanValue/size;
}

void printArray(int *array){
    if (array == NULL){
        printf("Array empty!\n");
        return;
    }
    printf("Size of Array: %d\n", size);
    for (int i = 0; i < size; i++){
        printf("%d: ", i);
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int main(){
    int *x = calloc(1, sizeof(int));
    int userInput;
    int* pUserInput = &userInput;
    scanf("%d", pUserInput);
    while (userInput != -1) {
        x[size] = *pUserInput;
        x = realloc(x, sizeof(int) * (size+2));
        size ++;
        printArray(x);
        scanf("%d", pUserInput);
    }
    free(x);
    return 0;
}