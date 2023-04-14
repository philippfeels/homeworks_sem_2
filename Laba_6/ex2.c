#include <stdio.h>

void whereIsNumber(int* ptrArr, int i, int inputNumber);

int main() {
    int numArr[3][3] = {{22,33,41},{3,74,95},{4,48,608}};
    int* ptrArr = numArr[0];
    int i = 3;
    int k = 3;
    int inputNumber;
    
    printf("Enter any number from the list: \n");

    for (i = 0; i < 3; i++) {
        for (k = 0; k < 3; k++) {
            printf("%d ", numArr[i][k]);
        }
    }

    printf("\n");
    scanf(" %d", &inputNumber);

    whereIsNumber(ptrArr, i, inputNumber);

    return 0;
}

void whereIsNumber(int* ptrArr, int i, int inputNumber) {
    
    i = 0;

    for (i = 0; i < 9; i++) {
        if (inputNumber == *(ptrArr + i)) {
            printf("Row: %d\nColomn: %d", i/3 + 1, i%3 + 1);
            break;
        }
    }
}