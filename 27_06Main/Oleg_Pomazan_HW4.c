#include <stdio.h>
#define N 8
#define M 8

void printTwoDimensional(int n, int m, int array[N][M])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%6d", array[i][j]);
        }
        printf("\n");
    }
}


// 1. *Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.
// Например, карта:
// 1 1 1 1 1 0 1 0
// 0 1 0 1 1 0 1 0
// 0 1 0 0 1 1 1 1
// 1 1 1 0 0 1 0 1
// 1 0 1 0 1 1 1 1
// 0 0 1 1 1 0 0 0
// 0 0 1 0 1 1 1 0
// 0 0 1 1 1 1 1 1

void mapStart()
{
    int map[N][M] =
    {
        {1, 1, 1, 1, 1, 0, 1, 0},
        {0, 1, 0, 1, 1, 0, 1, 0},
        {0, 1, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 1, 1, 1}
    };
    int array[N][M];

    for (int j = 0; j < M; j++)
    {
        if (map[0][j] != 0)
            array[0][j] = 1;
        else
            array[0][j] = 0;
    }

    for (int i = 1; i < N; i++)
    {
        if (map[i][0] != 0)
            array[i][0] = 1;
        else
            array[i][0] = 0;

        for (int j = 1; j < M; j++)
        {
            if (map[i][j] == 1)
                array[i][j] = array[i][j - 1] + array[i - 1][j];
            else
                array[i][j] = 0;
        }
    }

    printTwoDimensional(N, M, array);
}

// 2. Вывести на экран задачу о нахождении длины максимальной последовательности с помощью матрицы.

int i, j, m, n, c[20][20];
char x[20], y[20], b[20][20];

void printSequence(int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (b[i][j] == 'c')
    {
        printSequence(i - 1, j - 1);
        printf("%c", x[i - 1]);
    }
    else if (b[i][j] == 'u')
        printSequence(i - 1, j);
    else
        printSequence(i, j - 1);
}

void longestCommonSequence()
{
    m = strlen(x);
    n = strlen(y);
    for (i = 0; i <= m; i++)
        c[i][0] = 0;
    for (i = 0; i <= n; i++)
        c[0][i] = 0;

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'c';
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u';
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
            printf("%2c", b[i][j]);
        }
        printf("\n");
    }
}

void sequenceStart()
{
    printf("Enter the first sequence: ");
    scanf("%s", x);
    printf("Enter the second sequence: ");
    scanf("%s", y);
    longestCommonSequence();
    printf("\nThe Longest Common Subsequence is ");
    printSequence(m, n);
}

int main_old4()
{
    sequenceStart();

    return 0;
}