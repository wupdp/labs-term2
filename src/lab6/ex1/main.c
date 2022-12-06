#include"header.h"
#include <time.h>

int main() {
    clock_t t1, t2, t3;
    printf("Enter the length:\n");
    int length;
    length = initX(1, 200000);
    int *mas = massiveInit(length);
    int *mas2 = massiveInit(length);
    printf("How do you want to input the row?\n\t1 - Random\t 2 - Bad case\n\n");
    int x = initX(1, 2);
    if (x == 1)
        ranInputRow(mas, length);
    else
        badCase(mas, length);
    mas_copy(mas2, mas, length);
    printf("Show the massive?\n\t1 - Yes\t 2 - No\n");
    x = initX(1, 2);
    if (x == 1)
        massive1Show(mas, length);
    printf("\n\n Sorting......\n\n");
    //printf("%d      %d\n",minFind0(mas,length,0),minFind1(mas,length,minFind0(mas,length,0)+1));
    t1 = (long) clock();
    insertionSort(mas, length);
    //q_sort(mas, length);
    t2 = (long) clock();
    bubbleSort(mas2, length);
    t3 = (long) clock();
    //printf("%l      %l\n",minFind0(mas,length,0),minFind1(mas,length,minFind0(mas,length,0)+1));
    printf("\n Insertion sort Time: %li milisec", t2 - t1);
    printf("\n Bubble sort Time: %li milisec\n", t3 - t2);
    printf("Show the sorted massive?\n\t1 - Yes\t 2 - No\n");
    x = initX(1, 2);
    if (x == 1)
        massive1Show(mas, length);
    free(mas);
}