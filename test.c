#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


void matrix_free(int** A, int N) //освобождение памяти
{
    for (int i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);
}


void print_array(int** A, int n)//(working) (optimized)
{
  for (int i = 0; i < n; i++)
  {
      printf("%d %d\t", A[i][0], A[i][1]);
  }
}


void matrix_print(int** A, int n)//(working) (optimized)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}


int** matrix_alloc(int N)//(working)
{
    int** A = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
    {
        A[i] = (int*)malloc(N * sizeof(int));
    }
    return A;
}


int*** set_of_matrix_alloc(int N)//(working) (optimized)
{
    int*** A = (int***)malloc(N * sizeof(int**));
    return A;
}


int** minor(int** A, int n, int column) //минор по 1-ой строке (working)
{
    int** B = (int**)malloc((n - 1) * sizeof(int*));

    for (int i = 0; i < n - 1; i++)
    {
        B[i] = (int*)malloc((n - 1) * sizeof(int));
    }


    for (int i = 1; i < n; i++) //проход по всем строкам
    {
        int k = 0;
        for (int j = 0; j < n; j++) //проход по всем стобцам
        {
            if (j != column)
            {
                B[i-1][k] = A[i][j];
                k++;
            }
        }
    }
    return B;
}


void minor_free(int** A, int n)//освобождение памяти (working)
{
    for (int i = 0; i < n; i++)
    {
        free(A[i]);
    }
    free(A);
}


int det(int** A, int n) //(working)
{
    int sum = 0;
    switch(n)
    {
        case 1: //(working)
            return A[0][0];
            break;
        case 2: //(working)
            return A[0][0] * A[1][1] - A[0][1] * A[1][0];
            break;
        default:
            for (int i = 0; i < n; i++)//проход по каждому элементу из 1-ой строки ориг матрицы
            {
                int** b = minor(A, n, i);
                sum += pow(-1, 2+i) * A[0][i] * det(b, n - 1);
                minor_free(b, n-1);
            }
            break;
    }
    return sum;
}


void sorting(int** arr, int n) //(working) (optimized)
{
	int control = n - 1;
	int left = 0, right = control;
	int* temp;
	do
	{
		for (int i = left; i < right; i++)
		{
			if (arr[i][1] > arr[i + 1][1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				control = i;
			}
		}
		right = control;
		for (int i = right; i > left; i--)
		{
			if (arr[i][1] < arr[i - 1][1])
			{
				temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
				control = i;
			}
		}
		left = control;
	} while (left < right);
}


void set_of_matrix_free(int*** A, int N, int** coefficient_f) //освобождение памяти
{
    for (int i = 0; i < N; i++) {
      matrix_free(A[i], coefficient_f[i][2]);
    }
    free(A);
}


int main()
{
    int N;
    scanf("%d", &N);
    int*** A = set_of_matrix_alloc(N);
    int size;
    int elem;
    int** coefficient = (int**)malloc(N * sizeof(int*)); //множетсво из пар, где одно из значений будет значением det, а второе индексом i (A[i]) на котором распологается матрица с этим det

    for (int i = 0; i < N; i++)
    {
        coefficient[i] = (int*)malloc(3 * sizeof(int));
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &size);
        A[i] = matrix_alloc(size);
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
              scanf("%d", &elem);
              A[i][j][k] = elem;
            }
        }
        coefficient[i][0] = i;
        coefficient[i][1] = det(A[i], size);
        coefficient[i][2] = size;
    }


    int** coefficient_f = coefficient;
    sorting(coefficient, N);
    //финальный вывод
    for (int i = 0; i < N; i++)
    {
      matrix_print(A[(coefficient[i][0])], coefficient[i][2]);
    }
    //set_of_matrix_free(A, N, coefficient_f);
}
