#include <stdio.h>
#include <stdlib.h>

    /*Функция перестановок. Permutations function.*/
    int permute(int * argv) {

        int k = 0;
        int i = 0;
        int j = 0;
        int x = 0; //Хранит длину строки. Var to let know length of a string
        int c = 0; //Для обмена. Buffer
		int reverse_argv[100] = {};


        /*Buble sort the array. Упорядочим алфавит*/
        for (x; argv[x]; x++);

        for (i = 0; i < x; i++) {
            for (j = x - 1; j > i; j--) {
                if (argv[j - 1] > argv[j]) {
                    c = argv[j - 1];
                    argv[j - 1] = argv[j];
                    argv[j] = c;
                }
            }
        }
        /*Here we reverse an array to stop the alorithm later.
         *Перевернем массив, чтобы остановить его позже в цикле*/

        i = x - 1;
        while (k < x) {
            reverse_argv[k] = argv[i];
            i--;
            k++;
        }

        /*Main part: here we permute. Порождаем перестановки*/

        while (1) {

            for (j = 0; argv[j] != 0; j++) printf("%d ", argv[j]);
            printf("\n");

            for (k = 0; k != x + 1; k++) {
                if (reverse_argv[k] == argv[k] && argv[k] == 0) return 0;
                if (reverse_argv[k] != argv[k]) break;
            }

            i = x - 2;
            /*Here we search next. Ищем новую перестановку*/
            while (argv[i] >= argv[i + 1]) i--;
            j = x - 1;
            while (argv[j] <= argv[i]) j--;

            /*Change. Обмен*/
            c = argv[j];
            argv[j] = argv[i];
            argv[i] = c;
            i++;
            /*Tail reverse. Оборачиваем хвост*/
            for (j = x - 1; j > i; i++, j--) {
                c = argv[i];
                argv[i] = argv[j];
                argv[j] = c;
            }

        }
    }

int main(int argc, char * argv[]) {

    int i = 0;
    int j = 0;
    int sum = 0;
    int first_elem = 0;
    int min_elem = 0;

    /*Проверим число аргументов. Here we check a number
     * of arguments*/
    if (argc != 2) {
        printf("Restart it with an argument\n");
        return 0;
    }

    /*String (argument) to integer conversion.
     * Конвертируем аргумент (строку) в целое число*/
    i = atoi(argv[1]);
    if (i > 99) return 0;


    /*Массив целых. This is an array of integers*/
    int a[100] = {};
    for (j = 0; j != i; j++) a[j] = 1;
    a[j] = 0;


    int n = 0;
    /*Initial number of objects in array A.
       Число объектов (первоначально) в массиве А*/
    for (n; a[n] != 0; n++);
    /*Number of objects in array A (at the moment).
    Число объектов (в текущий момент) в массиве А*/
    int x = 0;

    while (1) {
        /*Обнулим переменную. Unset min_elem*/
        min_elem = 0;

        /*Печать и выход. Print end exit*/

        permute(a);
        if (a[0] == n) break;

        /*Элемент в нулевом индексе нашего динамического
        массива на текущий момент.
        First element of our dynamic array*/
        first_elem = a[0];

        i = 0;

        for (x = 0; a[x] != 0; x++);
        while (i != x - 1) {

            /*Найдем элемент меньше первого. Here we search min. element*/
            if (a[i] < first_elem) {
                first_elem = a[i];
                min_elem = i;
            }

            i++;
        }

        /*Перенос элемента  "1". Here we transfer "1". */
        a[min_elem] += 1;
        a[x - 1] -= 1;
        /*Here we cut A. Обрежем А*/
        a[min_elem + 1] = 0;


        /*Добавим в массив единицы заново.
        Here we add 1 (fill)  to the array*/
        for (j = min_elem + 1; j != n; j++) a[j] = 1;
        a[j - 1] = 0;

        /*Найдем сумму  элементов и обрежем массив А.
         * We count the sum of elements and cut the array A*/
        sum = 0;
        for (j = 0; a[j] != 0; j++) {
            sum = sum + a[j];
            if (sum == n) a[j + 1] = 0;
        }

    }
}
