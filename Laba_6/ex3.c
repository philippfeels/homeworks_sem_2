// Статический массив

#include <stdio.h>

void print(int numArr[], int size);
void insert(int numArr[], int size, int numInput);
void append(int numArr[], int size, int numInput);

int main() {

    int size;
    int elem;
    int numInput;
    int numFun;

    printf("Номер тактики: 1 (статический массив)\n\n");

    printf("Введите размер массива: \n");
    scanf("%d", &size);
    
    printf("Введите количество элементов: \n");
    scanf("%d", &elem);

    if (elem > size) {
        printf("Ошибка! Кол-во элементов превосходит размер массива. \n");
        return 0;
    }
    
    int numArr[size];

    int k;

    for (k = 0; k < size; k++) {
        if (k < elem) {
            numArr[k] = k;
        } else if (k >= elem) {
            numArr[k] = 0;
        }
    }   

    // Тесты insert

    printf("append:\n\n");
    
    printf("Добавляем 3\n");
    append(numArr, size, 3);
    
    printf("Добавляем 5\n");
    append(numArr, size, 5);
    
    printf("Добавляем 7\n");
    append(numArr, size, 7);
    
    printf("Добавляем 12\n");
    append(numArr, size, 12);
    
    printf("Добавляем 24\n");
    append(numArr, size, 24);

    //Тесты append

    printf("insert:\n\n");
    
    printf("Добавляем 3\n");
    insert(numArr, size, 3);
    
    printf("Добавляем 5\n");
    insert(numArr, size, 5);
    
    printf("Добавляем 7\n");
    insert(numArr, size, 7);
    
    printf("Добавляем 12\n");
    insert(numArr, size, 12);
    
    printf("Добавляем 24\n");
    insert(numArr, size, 24);

    return 0;
}

void print(int numArr[], int size) {
    int j;

    printf("{");
    for (j = 0; j < size; j++) {
        if (j == size - 1) {
            printf("%d}\n\n", numArr[j]);
            break;
        }
        printf("%d, ", numArr[j]);
    }
}

void insert(int numArr[], int size, int numInput) {
    numArr[size/2] = numInput;
    print(numArr, size);
}
    
void append(int numArr[], int size, int numInput) {
    numArr[size - 1] = numInput;
    print(numArr, size);
}