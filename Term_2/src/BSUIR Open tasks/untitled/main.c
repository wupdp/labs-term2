#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t = 100;
    int n = 100;
    int* sum = 0;
    int *arr = (int*)calloc(60, sizeof(int ));
    int max = 0, imax = 0;
    //algorithm
    for (int i = 0; i < t; i++){
        for (int j = 0; j < n; j++) { //massive of int start
            if (arr[j] > max) {
                max = arr[j];
                arr[j] = -1;
            }
            if (arr[j] == 0){
                arr[j] = -1;
                sum+=max;
                max = 0;
                j = 0;
            }
        }
    }
    return 0;
}