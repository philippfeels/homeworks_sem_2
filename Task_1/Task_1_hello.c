﻿#include <stdio.h>

int main(){
    
    int arg;
    
    scanf_s("%d", &arg);
    printf("Hello, %d!", arg);
    return 0;

}

/*
Задания:

    1. Скомпилируйте программу через терминал с выдачей файлов промежуточных этапов.
        (Preprocess -> Compile -> Assemble -> Link, см. help для gcc) 
        Что происходит на каждом этапе?
        
        ОТВЕТ:
        Предобработка - удаление комментариев, текстовые замены, подключение библиотек
        Компиляция и ассемблинг- "перевод" языка высоко уровня в язык машинного кода: появление объектного файла (Task_1_hello.0)
        Линкинг - сборка исполняемого файла: появление a.exe
    
    2. Скомпилируйте программу в VS Code. 

    3. Сломайте эту программу.
        Удалите последовательно из кода программы символы: ;, ), {
        И попробуйте выполнить программу. 
        Проанализируйте ошибки на которые укажет компилятор
    
    4. Доработайте программу
        Обеспечьте возможность передачи аргумента при запуске Task.exe из терминала
        Используqте аргумент как имя для приветствия 
        (вместо "Hello, World!", должно быть "Hello, <Параметр>!")

*/