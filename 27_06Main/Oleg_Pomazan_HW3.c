#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

#define ARRAY_SIZE 100

void swap(int* a, int* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void print(int size, int* array)
{
    for (int i = 0; i < size; i++)
    {
        printf("%6i", array[i]);
    }
    puts("");
}

// 1. Попробовать оптимизировать пузырьковую сортировку.
// Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
// Написать функции сортировки, которые возвращают количество операций.

void bubbleSortDefault(int size, int* array)
{
    int swaps = 0;
    clock_t t;
    t = clock();

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                ++swaps;
            }
        }
    }

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("\nThe sort was made with %d swaps and %f seconds.\n", swaps, time_taken);
}

void bubbleSortAdvanced(int size, int* array)
{
    int swaps = 0;
    clock_t t;
    t = clock();

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i + 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                ++swaps;
            }

            if (j > i && array[i] < array[j])
            {
                swap(&array[j], &array[i]);
                ++swaps;
            }
        }
    }

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("\nThe advanced sort was made with %d swaps and %f seconds.\n", swaps, time_taken);
}

// 2. *Реализовать шейкерную сортировку.

void shakerSort(int size, int* array)
{
    int swaps = 0;
    clock_t t;
    t = clock();

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                ++swaps;
            }
        }

        for (int j = size - 1; j > 0; j--)
        {
            if (array[j - 1] < array[j])
            {
                swap(&array[j - 1], &array[j]);
                ++swaps;
            }
        }
    }

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("\nThe shaker sort was made with %d swaps and %f seconds.\n", swaps, time_taken);
}

//3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив.
// Функция возвращает индекс найденного элемента или -1, если элемент не найден

int binarySearch(int size, int* array, int elementToFind)
{
    int leftTerminator = 0, rightTerminator = size - 1;
    int middle = leftTerminator + (rightTerminator - leftTerminator) / 2;


    while (leftTerminator <= rightTerminator)
    {
        if (array[middle] == elementToFind)
        {
            return middle;
        }

        if (array[middle] < elementToFind)
        {
            rightTerminator = middle - 1;
        }
        else
        {
            leftTerminator = middle + 1;
        }

        middle = leftTerminator + (rightTerminator - leftTerminator) / 2;
    }
        
    return -1;
}

void menu()
{
    int numbersArray[ARRAY_SIZE];
    FILE* stream;

    char path[128];

    puts("This program needs an array to work with. Please specify a file with 100 lines of integer numbers.");
    printf("Please enter the file's path: ");
    gets(path);

    stream = fopen(path, "r");

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        fscanf(stream, "%i", &numbersArray[i]);
    }
    fclose(stream);

    puts("\nArray before sort: ");
    print(ARRAY_SIZE, numbersArray);

    int choice = 0;
    while (choice < 1 || choice > 3)
    {
        puts("Please choose a sorting algorithm:\n1 - bubble sort\n2 - advanced bubble sort\n3 - shaker sort");
        scanf("%d", &choice);
    }
    
    switch (choice)
    {
    case 1:
        bubbleSortDefault(ARRAY_SIZE, numbersArray);
        break;
    case 2:
        bubbleSortAdvanced(ARRAY_SIZE, numbersArray);
        break;
    case 3:
        shakerSort(ARRAY_SIZE, numbersArray);
        break;
    default:
        puts("Something went wrong. Using bubble sort.");
        bubbleSortDefault(ARRAY_SIZE, numbersArray);
        break;
    }

    puts("\nArray after sort:");
    print(ARRAY_SIZE, numbersArray);

    int valueToSearch;
    printf("Please enter a value for search: ");
    scanf("%d", &valueToSearch);

    int result = binarySearch(ARRAY_SIZE, numbersArray, valueToSearch);
    if (result == -1)
    {
        printf("Element wasn't found.");
    }
    else
    {
        printf("The element's index is %d", result);
    }
}

int main_old3()
{
    menu();

    return 0;
}