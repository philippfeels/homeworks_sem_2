#include <stdio.h>  // Библиотека для работы с функциями ввода-вывода
// #include <stdlib.h>	//Данная библиотека для многих функций Си нужна, но не здесь
#include <locale.h> // Библиотека для указания локации (региональной кодировки) для Visual Studio
#include <stdbool.h>


int bisector(double x, double y) {
    bool isItShaded = false;
    isItShaded = y <= -x;
    return isItShaded;
}

int bisector_itself(double x, double y) {
    bool isItShaded = false;
    isItShaded = y == -x;
    return isItShaded;
}

int horizontal(double x, double y) {
    bool isItShaded = false;
    isItShaded = y > 3;
    return isItShaded;
}
int vertical(double x, double y) {
    bool isItShaded = false;
    isItShaded = x > 4;
    return isItShaded;
}
int main() {

    setlocale(LC_ALL, "chcp 65001");

    int x, y;

    printf("Введи координату X: ");
    scanf_s("%d", &x);
    printf("Введи координату Y: ");
    scanf_s("%d", &y);
    
    printf("%d", vertical(x,y) && horizontal(x,y) || !vertical(x,y) && !horizontal(x,y) && bisector(x, y)  || bisector_itself(x, y));
    return 0;   
}

// (5,5) - проверка множества x > 4, y > 3: True
// (4,3) - проверка границы множества x > 4, y > 3: False
// (-5,5) - проверка y = -x: True
// (-5, 2) - проверка y < 3 && x < 4 %% y <= -x (2-ая четверть): True
// (-4, -4) - проверка y < 3 && x < 4 %% y <= -x (3-ая четверть): True
// (2, -8) - проверка y < 3 && x < 4 %% y <= -x (4-ая четверть): True
// (1,2) - проверка области, не принадлежащей ни одному из заданных множеств (1-ая четверть): False
// (3,6) - проверка области, не принадлежащей ни одному из заданных множеств (1-ая четверть): False
// (-1,2) - проверка области, не принадлежащей ни одному из заданных множеств (2-ая четверть): False
// (-6,4) - проверка области, не принадлежащей ни одному из заданных множеств (2-ая четверть): False
// (2,1) - проверка области, не принадлежащей ни одному из заданных множеств (4-ая четверть): False
// (5,-8) - проверка области, не принадлежащей ни одному из заданных множеств (4-ая четверть): False

