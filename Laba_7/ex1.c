#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void selectionSort(char* arr);
void swap_chars(char* x, char* y);
void getWords(char* arr);
void print(char* arr);
// void combSort(char* arr);


void swap_chars(char* x, char* y) {
	char tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void selectionSort(char* arr) {   
    int i, j, min_idx, length = strlen(arr);
    for (i = 0; i < length-1; i++) {
        min_idx = i;
        for (j = i+1; j < length; j++)
        {
          if (arr[j] < arr[min_idx])
              min_idx = j;
        }
        if (min_idx!=i)
            swap_chars(&arr[min_idx], &arr[i]);
    }

}

void bubbleSort(char* arr) {
    int i, j, length = strlen(arr);
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap_chars(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int i, j, n = 10; 
    char** strArr = (char**)malloc(sizeof(char*)*n);
    for(int i = 0; i < n; i++) {
        strArr[i] = (char *)malloc(sizeof(char));
    }
    
    getWords(strArr[0]);
    print(strArr[0]);
    bubbleSort(strArr[0]);
    print(strArr[0]);

    return 0;
}

void getWords(char* arr) {
    char str[20];
    printf("Введите слово: ");
    scanf("%s", str);
    strcpy(arr, str);
}

void print(char* arr) {
    
    for (int i = 0; i < strlen(arr); i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
}