#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

int maxLength(char sym);

char arrSym[] = {'h', 'h','e','l','l','l','o', 'o','l','o', 'h', '\n'};

int main() {
    char sym;

    printf("Enter a symbol: \n");
    scanf(" %c", &sym);
    printf("%d", maxLength(sym));

    return 0;
}

int maxLength(char sym) {
    
    int counter = 0;
    int maxCounter = 0;
    int i = 0;

    while  (i < sizeof(arrSym)) {
            if (arrSym[i] == sym) {
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