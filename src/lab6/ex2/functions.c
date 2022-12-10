#include <stdio.h>
#include <stdlib.h>


int min_find0(int *mas, int l, int i) {
    int mini = mas[i];
    for (; i < l; i++) {
        if (mas[i] < mas[mini])
            mini = i;
    }
    return mini;
}


int min_find1(int *mas, int l, int i) {
    int mini = mas[i];
    for (; i < l; i++) {
        if (mas[i] <= mas[mini])
            mini = i;
    }
    return mini;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int init_x(int min, int max) {
    int x;
    while (scanf_s("%d", &x) != 1 || x < min || x > max || getchar() != '\n') {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}

int *massive_init(int l) {
    int *mas;
    mas = (int *) calloc(l, sizeof(int));
    return mas;
}

int **massive2_init(int r, int l) {
    int **mas = (int **) calloc(r, sizeof(int *));
    for (int i = 0; i < r; i++)
        mas[i] = massive_init(l);
    return mas;
}


void row_input(int *mas, int l) {
    for (int i = 0; i < l; i++) {
        mas[i] = init_x(-999, 999);
    }
}

void massive2_input(int l, int length, int **mas) {
    for (int i = 0; i < l; i++) {
        printf("Input values of %d row\n", (i + 1));
        row_input(mas[i], length);
    }
}

void massive1_show(int *mas, int l) {
    for (int i = 0; i < l; i++) {
        printf("%4d", mas[i]);
    }
    printf("\n");
}


void massive2_show(int **mas, int r, int l) {
    for (int i = 0; i < r; i++)
        massive1_show(mas[i], l);
}

void ran_input_row(int *mas, int l) {
    for (int i = 0; i < l; i++)
        mas[i] = rand() % 200 - 100;
}

int col_sum(int **mas, int row, int j) {
    int sum = 0;
    for (int i0 = 0; i0 < row; i0++) {
        sum += mas[i0][j];
    }
    return sum;
}

void ran_input_mas(int **mas, int r, int l) {
    for (int i = 0; i < r; i++) {
        ran_input_row(mas[i], l);
    }
    for (int j = 0; j < l; j++)
        mas[r][j] = col_sum(mas, r, j);
}

void col_swap(int **mas, int row, int j1, int j2) {
    for (int i0 = 0; i0 < row; i0++) {
        int temp = mas[i0][j1];
        mas[i0][j1] = mas[i0][j2];
        mas[i0][j2] = temp;
    }
}

/*void qisort(int **MAS, int *mas, int row, int size) {
    int j = size - 1;

    int mid = mas[size / 2];


    do {
        while (mas[i] > mid) {
            i++;
        }
        while (mas[j] < mid) {
            j--;
        }

        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            colSwap(MAS, row, j, i);
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {

        qisort(MAS, mas, row, j + 1);
    }
    if (i < size) {
        qisort(MAS, &mas[i], row, size - i);
    }
}*/

void free_mas(int **mas, int r) {
    for (int i = 0; i < r; i++)
        free(mas[i]);
}


void qi_sort(int **array, int n, int m,int N,int M)
{
  int  f = n, l = m, tmp, base = array[N][((l+f)/2)];
  
  while (f <= l)
  {
    for (; array[N][f] > base; f++);
    for (; array[N][l] < base; l--);
    if (f <= l)
    {
      for (int i = 0; i <=N; i++)
      {
        tmp = array[i][l];
        array[i][l] = array[i][f];
        array[i][f] = tmp;
      }
      f++;
      l--;
    }
  }
  if (n < l) qi_sort(array, n, l,N,M);
  if (f < m) qi_sort(array, f, m,N,M);
}