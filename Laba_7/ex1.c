#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void selectionSort(char** arr);
void bubbleSort(char** arr);
void combSort(char** arr);
void swap_strings(char* x, char* y);
void getWords(char* arr);
void print(char** arr);


void swap_strings(char* x, char* y) {
	char temp[20];
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}

void selectionSort(char** arr) {
    printf("SelectionSort:\n");   
    int i, j, min_idx, count = 0, size = 10;
    for (i = 0; i < size-1; i++) {
        min_idx = i;
        for (j = i+1; j < size; j++)
        {
          if (strcmp(arr[j], arr[min_idx]) < 0)
              min_idx = j;
        }
        if (min_idx != i) {
            swap_strings(arr[min_idx], arr[i]);
            print(arr);
            count += 1;
        }
    }
    printf("Кол-во итераций (SelectionSort): %d\n", count);
}

void bubbleSort(char** arr) {
    printf("BubbleSort:\n");
    int i, j, count = 0, size = 10;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                swap_strings(arr[j], arr[j + 1]);
                print(arr);
                count += 1;
            }
        }
    }
    printf("Кол-во итераций (BubbleSort): %d\n", count);
}

int main() {
    int i, n = 10; 
    char** strArr = (char**)malloc(sizeof(char*)*n);
    for (i = 0; i < n; i++) {strArr[i] = (char *)malloc(sizeof(char));}

    printf("Введите 10 слов для сортировки их по алфавиту: \n");
    for (i = 0; i < n; i++) {getWords(strArr[i]);}
    
    printf("Введите номер опции:\n1. SelectionSort\n2. BubbleSort\n3. CombSort\n4. Применить всё\n");
    scanf("%d", &i);

    if (i == 1) {selectionSort(strArr);}
    else if (i == 2) {bubbleSort(strArr);}
    else if (i == 3) {combSort(strArr);}
    else if (i == 4) {selectionSort(strArr); bubbleSort(strArr), combSort(strArr);}

    return 0;
}

void getWords(char* arr) {
    char str[20];
    scanf("%s", str);
    strcpy(arr, str);
}

void print(char** arr) {
    printf("[");
    for (int i = 0; i < 10; i++) {
        if (i == 9) {printf("%s", arr[i]);}
        else {printf("%s, ", arr[i]);}
    }
    printf("]\n");
}

void combSort(char** arr) {
    printf("CombSort:\n");
    
    int count = 0, size = 10;

    float gap = (size/1.3);
    int swapped = 1;

    while(gap > 1 || swapped) {

        swapped = 0;
        if (gap < 1) {gap = 1;}
        int igap = (int) gap;

        for(int i = 0; i + igap < size; i++) {
            if(strcmp(arr[i], arr[i +igap]) > 0)
            {swap_strings(arr[i], arr[i + igap]); swapped = 1; print(arr); count += 1;}
        }
        gap /= 1.3;
    }
    printf("Кол-во итераций (CombSort): %d\n", count);
}