/*Порождение всех разбиений.   Generation of all partitions*/
#include <stdio.h>
int main (int argc, char *argv[]) {

    /*Массив целых. This is an array of integers*/
    int a[21]= {1,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1,1,0};

    int i = 0;
    int j = 0;

    int sum = 0;
    int first_elem = 0;
    int min_elem = 0;

    int n = 0; /*Initial number of objects in array A.
    Число объектов (первоначально) в массиве А*/
    for (n; a[n] != 0; n++);
    
    /*Number of objects in array A (at the moment).
    Число объектов (в текущий момент) в массиве А*/
    int x = 0;
    for (x; a[x] != 0; x++);


    while (1)
    {
        /*Печать и выход. Print end exit*/
        for (j=0; a[j] != 0; j++) printf("%d", a[j]);
        printf("\n");
        if (a[0] == n) break;

        /*Элемент в нулевом индексе нашего динамического
        массива на текущий момент.
        First element of our dynamic array*/
        first_elem = a[0];

        i = 0;

        for (x=0; a[x] != 0; x++);
        while (i != x -1)
        {
        
            /*Найдем элемент меньше первого. Here we search min. element*/
            if (a[i] < first_elem)
            {
                first_elem = a[i];
                min_elem = i;
            }

            i++;
        }
        
        /*Перенос элемента  "1". Here we transfer "1". */
        a[min_elem]+= 1;
        a[x - 1]-= 1;
        /*Here we cut A. Обрежем А*/
        a[min_elem+1] = 0;


        /*Добавим в массив единицы заново.
        Here we add 1 (fill)  to the array*/
        for (j = min_elem+1; j != n; j++) a[j] = 1;
        a[j-1] = 0;

        /*Найдем сумму  элементов и обрежем массив А.
         * We count the sum of elements and cut the array A*/
        sum = 0;
        for (j = 0; a[j] != 0; j++)
        {
            sum = sum + a[j];
            if (sum == n) a[j+1] = 0;
        }

        /*Обнулим переменную. Unset min_elem*/
        min_elem = 0;

    }
}

