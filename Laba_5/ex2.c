#include <stdio.h>  // Библиотека для работы с функциями ввода-вывода
#include <locale.h> // Библиотека для указания локации (региональной кодировки) для Visual Studio
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char* getInput();
bool testInput();
int strToInt();
void printInt();

int i;
char* smallText;
char* fun1;
int fun3;

char* getInput() {
    
    char* smallText = malloc(sizeof(char) * 256);

    printf("Введите строку: ");
    scanf("%s", smallText);

    return smallText;
}

bool testInput(char* x) {

    int i;
    if (sscanf(x, "%d", &i) == 1) {
        return true;
        }       
    else {
    return false;
    }   
}

int strToInt(char x[]) {

    int y = atoi(x);
    return y;
}

void printInt(int x) {

    printf("%d", x);

}


int main() {
    char* fun1 = getInput();
    
    if (testInput(fun1) == true) {
        fun3 = strToInt(fun1);
        printInt(fun3);
    } else {
        printf("Вторая функция вернула False. Программа завершена.");
    }

    return 0;
}
