#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "stdarg.h"
void swap(int* a, int* b)
{
    int temp= *a;
    *a=*b;
    *b=temp; 
}

void bubble(int* mas, int n)
{
    for(int k=0; k<n; k++){
        for(int i=0; i<n-1; i++)
        {
        if(mas[i]>mas[i+1])
            swap(&mas[i],&mas[i+1]);
        }
    }
}

void insertion_sort(int* mas, int n)
{
    for(int k=1;k<n;k++)
        for(int i=k;i>0 && mas[i-1]>mas[i];i--)
        swap(&mas[i], &mas[i-1]);
}


void merge(int* mas, int start1, int end1)
{
    int left, right, middle;
    int *mas1;
    mas1=(int*)malloc((end1-start1+1)*sizeof(int));
    middle=(start1+end1)/2;
    left=start1;
    right=middle+1;
    for(int k=start1;k<=end1;k++)
    {
        if((left<=middle) && ((right>end1) || (mas[left]<mas[right]))){
            mas1[k-start1]=mas[left];
            left++;
        }
        else{
            mas1[k-start1]=mas[right];
            right++;
        }
    }
    for(int k=start1;k<=end1;k++)
    mas[k]=*(mas1+k-start1);
}

void merge_sort(int* mas, int start, int end)
{
    if (start<end)
    {
        merge_sort(mas,start,(start+end)/2);
        merge_sort(mas,(start+end)/2+1,end);
        merge(mas, start, end);
    }
}

void shell_sort(int* mas,int n)
{
    for(int step=n/2;step>0;step/=2){
        for(int i=step;i<n;i++){
            for(int j=i-step; j>=0 && mas[j]>mas[j+step];j=-step){
            swap(&mas[j],&mas[j+step]);
            }
        }
    }
}

void qisort(int* mas, int size) {
	int i = 0;
	int j = size - 1;
	int mid = mas[size / 2];
	do {
		while (mas[i] < mid) {
			i++;
		}
		while (mas[j] > mid) {
			j--;
		}
		if (i <= j) {
			swap(&mas[i],&mas[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {
		qisort(mas, j + 1);
	}
	if (i < size) {
		qisort(&mas[i], size - i);
	}
}

int sum(int n, ...)
{
    int result = 0;
    va_list factor;
    va_start(factor, n);
    for(int i = 0; i < n; i++) 
    result+=va_arg(factor, int);
    va_end(factor);
    return result;
}








int main()
{ 
    int length;
    int* mas=NULL;
    printf("Enter the length\n");
    length=init_x(length,1,999);
    mas=massive_init(length);
    row_init(length,mas);
    massive1_show(mas,length);
    printf("\n\n\n%d", sum(length, mas[0], mas[1], mas[2], mas[3], mas[4]));
    massive1_show(mas,length);
    free(mas);
}







void qi_sort(int* mas,int n)
{
    int i=0;
    int j=n-1;
    int mid=mas[n/2];
    do
    {
    while(mas[i]<mid)
    i++;
    while(mas[j]>mid)
    j--;
    if(i<=j)
    {
        swap(&mas[i],&mas[j]);
        i++;
        j--;
    }
    }while(i<=j);
    if(j>0)
    qi_sort(mas,j+1);
    if(i<n-1)
    qi_sort(&mas[i],n-i);
}