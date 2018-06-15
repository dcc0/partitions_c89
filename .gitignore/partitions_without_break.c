/*Порождение всех разбиений.   Generation of all partitions*/
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {

    int i = 0;
    int j = 0;
    int sum = 0;
    int first_elem = 0;
    int min_elem = 0;
    int a[100]={}; 		/*Array. Массив*/
    int n = 0;     		/*Число всех объектов в массиве а*/
    int x = 0;			/*Число объектов на опред. итерации.
						Number of objects in the current iteration*/

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
	for (j=0; j !=i; j++) a[j]=1;
	a[j]=0;


    /*Initial number of objects in array A.
    Число объектов (первоначально) в массиве А*/
    for (n; a[n] != 0; n++);
    /*Number of objects in array A (at the moment).
    Число объектов (в текущий момент) в массиве А*/


   do
    {
         /*Обнулим переменную. Unset min_elem*/
        min_elem = 0;

        /*Печать и выход. Print end exit*/
        for (j=0; a[j] != 0; j++) printf("%d ", a[j]);
        printf("\n");


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

    }
      while (a[0] != n);
      printf("%d\n", n);
}
