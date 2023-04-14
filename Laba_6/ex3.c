// Номер тактики: 1 (статический массив)

#include <stdio.h>

void print(int numArr[], int size);
void insert(int numArr[], int size, int numInput);
void append(int numArr[], int size, int numInput);

int main() {

    int size;
    int elem;
    int numInput;
    int numFun;

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

    print(numArr, size);
        
    printf("Введите число, которое вы хотите добавить в массив: \n");
    scanf("%d", &numInput);
        
    printf("Введите номер операции, которую вы хотите произвести: \n1. insert\n2. append\n");
    scanf("%d", &numFun);
    if (numFun == 1) {
        insert(numArr, size, numInput);
    } else if (numFun == 2) {
        append(numArr, size, numInput);
    }

    return 0;
}

void print(int numArr[], int size) {
    int j;

    printf("{");
    for (j = 0; j < size; j++) {
        if (j == size - 1) {
            printf("%d}\n", numArr[j]);
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