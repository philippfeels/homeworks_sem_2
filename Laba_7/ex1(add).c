#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_nums(int* x, int* y);
void swap_pointers(char** x, char** y);
void swap_pointers2(char* x, char* y);

int main(int argc, char* argv[]){
	int a, b;
	char* s1 = (char*)malloc(200 * sizeof(char));
	char* s2 = (char*)malloc(200 * sizeof(char));
	a = 3; b = 4;
	swap_nums(&a, &b);
	printf("a is %d\n", a);
	printf("b is %d\n", b);
	strcpy(s1, "I should print second");
	strcpy(s2, "I should print first");
	swap_pointers(&s1, &s2);
	// swap_pointers2(s1, s2);
	printf("s1 is %s\n", s1);
	printf("s2 is %s\n", s2);
	free(s1);
	free(s2);
	return 0;
}

void swap_nums(int* x, int* y){
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
/*void swap_pointers(char* x, char* y){ 				Данная функция меняет указатели локальных переменных,
	char* tmp = (char*)malloc(200 * sizeof(char));		поэтому ее изменения не учитываются в main. Ниже представлены
	tmp = x;											две альтернативные функции, решающие эту проблемую. В первой мы
	x = y;												непосредственно меняет местами указатели на строки. Во второй меняем
	y = tmp;											содеражимое массивов с помощью strcpy. Таким образом все изменения учитываются
}                                                   	в main.*/														
void swap_pointers(char** x, char** y) {
	char *temp = *x;
	*x = *y;
	*y = temp;
}

void swap_pointers2(char* x, char* y) {
	char* tmp = (char*)malloc(200 * sizeof(char));
	strcpy(tmp, x);
	strcpy(x, y);
	strcpy(y, tmp);
	free(tmp);
}
