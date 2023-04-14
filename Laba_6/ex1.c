#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

int maxLength(char arr[], char sym);


int main() {
    char arrSym[] = {'h','e','l','l','l','o', 'o','l','o','\n'};
    char sym;

    printf("Enter a symbol: \n");
    scanf(" %c", &sym);
    printf("%d", maxLength(arrSym, sym));

    return 0;
}

int maxLength(char arr[], char sym) {
    
    int counter = 0;
    int maxCounter = 0;
    int i = 0;
    int arrLength = 8;
    char* ptrArr;

    ptrArr = (char*)malloc(arrLength * sizeof(char));
	
    for (i = 0; i < arrLength; i++) {
		ptrArr[i] = arr[i];
	}
    
    i = 0;

    while  (i < arrLength) {
            if (arr[i] == sym) {
                counter += 1;
                if (counter > maxCounter) {
                    maxCounter = counter;
                }  
            } else {
                counter = 0;
            }
            i += 1;
        }
    
    return maxCounter;
}