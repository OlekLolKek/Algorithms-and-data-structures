#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

#define COUNT_NUMBER_RANGE 100
#define ARRAY_PATH_25 "C:\\AlgorithmsData\\array25.txt"
#define ARRAY_PATH_100 "C:\\AlgorithmsData\\array100.txt"
#define ARRAY_PATH_10000 "C:\\AlgorithmsData\\array10000.txt"
#define ARRAY_PATH_1000000 "C:\\AlgorithmsData\\array100000.txt"

void printArray(int* array, int length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", array[i]);
    }
}

// Проанализировать время работы каждого из вида сортировок для 100, 10000, 1000000 элементов.
// Если самостоятельно реализовать сортировку не получается, разрешается найти сортировку в Интернете.
// Желательно прокомментировать строки программы.
// Записывайте в начало программы условие и свою фамилию.
// Все решения создавайте в одной программе.
// Снабдите программу меню.


#pragma region Task 1 (Count Sort)

// 1. Реализовать сортировку подсчетом.

int countSort(int* array)
{
    int iterations = 0;
    int countArray[COUNT_NUMBER_RANGE];            // this array will be used to store each number's repeat count

    for (int i = 0; i < COUNT_NUMBER_RANGE; ++i)
    {
        countArray[i] = 0;
        ++iterations;
    }


    for (int i = 0; i < ARRAY_SIZE; ++i)           // counting how many times each number appears in the entered array
    {
        int value = array[i];
        countArray[value]++;
        ++iterations;
    }

    for (int j = 0, i = 0; j < ARRAY_SIZE; )       // putting the values in the original array in the correct order
    {
        if (countArray[i] != 0)
        {
            --countArray[i];
            array[j] = i;
            ++j;
        }
        else
        {
            ++i;
        }
        ++iterations;
    }

    return iterations;
}

void countSortStart(int* array)
{
    printf("Before count sort: \n");
    printArray(array, ARRAY_SIZE);
    int iterations = countSort(array);
    puts("\n");
    printf("After count sort that took %d iterations: \n", iterations);
    printArray(array, ARRAY_SIZE);
}

#pragma endregion


#pragma region Task 2 (Quick Sort)

// 2. Реализовать быструю сортировку.

int quickSort(int* array, int left, int right)
{
    int comparisons = 0;
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = array[left];

    while (left < right)                           // moving the left and right bounds until they meet
    {
        ++comparisons;
        while ((array[right] >= pivot) && (left < right)) // moving the right bound until an element less than pivot is found
        {
            ++comparisons;
            right--;
        }

        if (left != right)                                // once it is found, swapping the elements
        {
            array[left] = array[right];
            left++;
        }
        ++comparisons;

        while ((array[left] <= pivot) && (left < right))  // moving the left bound until an element bigger than pivot is found
        {
            ++comparisons;
            left++;
        }

        if (left != right)                                // once it is found, swapping the elements
        {
            array[right] = array[left];
            right--;
        }
        ++comparisons;
    }

    array[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;

    if (left < pivot)
    {
        comparisons += quickSort(array, left, pivot - 1);         // sorting the left part of the array
    }
    ++comparisons;

    if (right > pivot)
    {
        comparisons += quickSort(array, pivot + 1, right);        // sorting the right part of the array
    }
    ++comparisons;

    return comparisons;
}

void quickSortStart(int* array)
{
    printf("Before quick sort: \n");
    printArray(array, ARRAY_SIZE);
    int comparisons = quickSort(array, 0, ARRAY_SIZE - 1);
    puts("\n");
    printf("After quick sort that made %d comparisons: \n", comparisons);
    printArray(array, ARRAY_SIZE);
}

#pragma endregion


#pragma region Task 3 (Merge Sort)

// 3. *Реализовать сортировку слиянием.

// Source: https://prog-cpp.ru/sort-merge/

int mergeSort(int* array, int left, int right)
{
    int iterations = 0;
    if (left == right)
        return iterations;

    int mid = (left + right) / 2;
    iterations += mergeSort(array, left, mid);                          // splitting the array into 2 halfs until it becomes a pair of elements
    iterations += mergeSort(array, mid + 1, right);
    int i = left;
    int j = mid + 1;
    int* tmp = (int*)malloc(right * sizeof(int));
    for (int step = 0; step < right - left + 1; step++)   // merging the two halfs together in the right order
    {
        if ((j > right) || ((i <= mid) && (array[i] < array[j])))
        {
            tmp[step] = array[i];
            i++;
        }
        else
        {
            tmp[step] = array[j];
            j++;
        }
        ++iterations;
    }

    for (int step = 0; step < right - left + 1; step++)   // writing the data to the source array
    {
        array[left + step] = tmp[step];
        ++iterations;
    }

    return iterations;
}

void mergeSortStart(int* array)
{
    printf("Before merge sort: \n");
    printArray(array, ARRAY_SIZE);
    int iterations = mergeSort(array, 0, ARRAY_SIZE - 1);
    puts("\n");
    printf("After merge sort that made %d iterations: \n", iterations);
    printArray(array, ARRAY_SIZE);
}

#pragma endregion


#pragma region Bubble Sort (for comparison)

int bubbleSort(int* array)
{
    int swaps = 0;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        for (int j = 0; j < ARRAY_SIZE - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                ++swaps;
            }
        }
    }

    return swaps;
}

void bubbleSortStart(int* array)
{
    printf("Before bubble sort: \n");
    printArray(array, ARRAY_SIZE);
    int swaps = mergeSort(array, 0, ARRAY_SIZE - 1);
    puts("\n");
    printf("After bubble sort that made %d swaps: \n", swaps);
    printArray(array, ARRAY_SIZE);
}

#pragma endregion



void menuLesson8()
{
    printf("This program sorts an array with numbers from 0 to 99 (inclusive, 100 values in total) using 3 different algorithms.\n");

    int input = -1;
    while (input < 0 || input > 4)
    {
        printf("Please choose an algorithm to use:\n0 - exit\n1 - count sort\n2 - quick sort\n3 - merge sort\n4 - bubble sort\n");
        scanf("%d", &input);
    }

    FILE* file = fopen(ARRAY_PATH_1000000, "r");
    if (file == NULL)
    {
        printf("Couldn't open the file.\n");
        return;
    }

    int array[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++)           // reading the numbers from the file
    {
        fscanf(file, "%d", &array[i]);
    }

    clock_t start = clock();

    switch (input)
    {
    case 0:
        return;
    case 1:
        countSortStart(array);
        break;
    case 2:
        quickSortStart(array);
        break;
    case 3:
        mergeSortStart(array);
        break;
    case 4:
        bubbleSortStart(array);
        break;
    default:
        printf("Something went wrong.");
        break;
    }

    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("\nThe algorithm took %f seconds to complete.", seconds);
}

int main()
{
    menuLesson8();

    return 0;
}