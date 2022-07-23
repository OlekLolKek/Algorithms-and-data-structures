#include <stdio.h>
#include <string.h>

#define INF 9999
#define MATRIX_SIZE 20
#define GRAPH_SIZE 8
#define T int


const char* matrixFilename = "C:\\AlgorithmsData\\matrix.txt";
int adjMatrix[MATRIX_SIZE][MATRIX_SIZE];
int n;

// 1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран.

void readAdjMatrix()
{
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    FILE* file = fopen(matrixFilename, "r");
    if (file == NULL)
    {
        printf("Error when opening the file.");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(file, "%d", &adjMatrix[i][j]);
        }
    }
    fclose(file);
}

void printMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    printf("%s", "       ");
    for (int i = 0; i < n; i++)
    {
        printf("%c(%d) ", 'A' + i, i);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c(%d)", 'A' + i, i);
        for (int j = 0; j < n; j++)
        {
            printf("%5d", (matrix[i][j]) == INF ? 0 : matrix[i][j]);
        }
        printf("\n");
    }
}

void adjMatrixStart()
{
    readAdjMatrix();
    printMatrix(adjMatrix);
}

// 2. Написать рекурсивную функцию обхода графа в глубину.

int visited[GRAPH_SIZE];

void depthTraversal(int i)
{
    visited[i] = 1;
    printf("Visited node %c(%d)!\n", 'A' + i, i);
    for (int j = 0; j < GRAPH_SIZE; ++j)
    {
        printf("Node %c(%d) is iterating over node %c(%d)\n", 'A' + i, i, 'A' + j, j);
        if (adjMatrix[i][j] != 0)
        {
            printf("Nodes %c(%d) and %c(%d) are adj\n", 'A' + i, i, 'A' + j, j);
            if (visited[j] != 1)
            {
                printf("Vertex %c(%d) is not visited\n\n", 'A' + j, j);
                depthTraversal(j);
            }
        }
    }
}

void depthTraversalStart()
{
    adjMatrixStart();

    int i = 0, j = 0;

    for (int i = 0; i < GRAPH_SIZE; ++i)
        visited[i] = 0;

    depthTraversal(i);
}

// 3. Написать функцию обхода графа в ширину.

int widthVisited[GRAPH_SIZE];

void widthTraversal()
{
    widthVisited[0] = 2;
    printf("Flooded vertex %c(%d)!\n", 'A' + 0, 0);

    for (int i = 0; i < GRAPH_SIZE; ++i)
    {
        if (widthVisited[i] == 2)
        {
            for (int j = 0; j < GRAPH_SIZE; ++j)
            {
                if (adjMatrix[i][j] != 0)
                {
                    if (widthVisited[j] == 1)
                    {
                        widthVisited[j] = 2;
                        printf("Flooded vertex %c(%d)!\n", 'A' + j, j);
                    }
                }
            }
        }

        widthVisited[i] = 3;
        printf("Overflowed vertex %c(%d)!\n\n", 'A' + i, i);
    }
}

void widthTraversalStart()
{
    readAdjMatrix();
    printMatrix(adjMatrix);

    for (int i = 0; i < GRAPH_SIZE; i++)
        widthVisited[i] = 1;

    widthTraversal();
}

int main_old7()
{
    widthTraversalStart();

    return 0;
}