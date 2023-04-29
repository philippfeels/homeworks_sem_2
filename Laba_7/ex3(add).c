/* Время выполнения каждого алгоритма различно: на первом месте по скорости CombSort, второе место разделяют
SelectionSort и BubbleSort (часто их время одинаково, хотя есть случаи, когда BubbleSort значительно отстоет).
Результаты говорят о том, что CombSort прекрасно подходит для сортировки большого объема данных. SelectionSort, несмотря
на скорость медленнее, чем у CombSort, сортирует всегда приблизительно за одно и то же время, что говорит о его стабильности,
в то время как у BubbleSort разброс значительный.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void selectionSort(char arr[10000][11]);
void bubbleSort(char arr[10000][11]);
void combSort(char arr[10000][11]);
void rand_string(char* str, int num);
void copy(char arr[10000][11], char copy[10000][11]);
void swap_strings(char* x, char* y);

int main() {
    srand(time(NULL));
    int i;
    char strArr[10000][11];
    char copyArr[10000][11];
    char x[11];
    for (i = 0; i < 10000; i++) {rand_string(x, 10); strcpy(strArr[i], x);}
    
    copy(strArr, copyArr);
    clock_t start = 0, end = 0;
    start = clock();
    selectionSort(copyArr);
    end = clock();
    printf("Время выполнения: %10lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    copy(strArr, copyArr);
    start = 0, end = 0;
    start = clock();
    bubbleSort(copyArr);
    end = clock();
    printf("Время выполнения: %10lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    start = 0, end = 0;
    start = clock();
    combSort(strArr);
    end = clock();
    printf("Время выполнения: %10lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

void selectionSort(char arr[10000][11]) {
    printf("SelectionSort:\n");   
    int i, j, min_idx, size = 10000;
    for (i = 0; i < size-1; i++) {
        min_idx = i;
        for (j = i+1; j < size; j++)
        {
          if (strcmp(arr[j], arr[min_idx]) < 0)
              min_idx = j;
        }
        if (min_idx != i) {
            swap_strings(arr[min_idx], arr[i]);
        }
    }
}

void bubbleSort(char arr[10000][11]) {
    printf("BubbleSort:\n");
    int i, j, size = 10000;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                swap_strings(arr[j], arr[j + 1]);
            }
        }
    }
}

void combSort(char arr[10000][11]) {
    printf("CombSort:\n");
    
    int size = 10000, swapped = 1;
    float gap = (size/1.3);

    while(gap > 1 || swapped) {
        swapped = 0;
        if (gap < 1) {gap = 1;}
        int igap = (int) gap;

        for(int i = 0; i + igap < size; i++) {
            if(strcmp(arr[i], arr[i +igap]) > 0) {swap_strings(arr[i], arr[i + igap]); swapped = 1;}
        }
        gap /= 1.3;
    }
}

void copy(char arr[10000][11], char copyArr[10000][11]) {
    for (int i = 0; i < 10; i++) {strcpy(copyArr[i], arr[i]);}
}

void swap_strings(char* x, char* y) {
	char temp[20];
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}

void rand_string(char* str, int num) {
    for (int i = 0; i < num; i++) {str[i] = rand() % ('z' - 'a' + 1) + 'a';}
    str[num] = 0;
}