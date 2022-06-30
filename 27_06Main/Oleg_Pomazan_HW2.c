#include <string.h>
#include <stdio.h>

// 1. Реализовать функцию перевода из десятичной системы в двоичную, используя рекурсию.

void decToBin(int number, char* result, int i)
{
    if (number > 0)
    {
        result[--i] = (number % 2) ? '1' : '0';
        decToBin(number / 2, result, i);
    }
}

void decToBinStart()
{
    char bin[64] = "b'";
    int number;

    printf("Please enter a number to convert: ");
    scanf_s("%d", &number);

    int i = 0;
    int temp = number;
    while (temp != 0)
    {
        temp = temp >> 1;
        i++;
    }
    bin[i] = '\0';

    decToBin(number, &bin, i);
    printf("%s", bin);
}

// 2. Реализовать функцию возведения числа a в степень b:
// a. без рекурсии;

void power()
{
    float number, power, result;
    printf("Enter a number and a power (separated by a space):");
    scanf("%f %f", &number, &power);

    if (power == 0)
    {
        result = 1;
    }
    else if (power > 0)
    {
        result = number;
        for (int i = 1; i < power; i++)
        {
            result *= number;
        }
    }
    else
    {
        number = 1 / number;
        power *= -1;
        result = number;
        for (int i = 1; i < power; i++)
        {
            result *= number;
        }
    }

    printf("The result is %f", result);
}

// 2. Реализовать функцию возведения числа a в степень b:
// б. рекурсивно;

float powerRecursive(float number, float startNumber, float power, int i)
{
    if (i < power)
    {
        number *= startNumber;
        i++;
        number = powerRecursive(number, startNumber, power, i);
    }

    return number;
}

void powerRecursiveStart()
{
    float number, power, result;
    printf("Enter a number and a power (separated by a space):");
    scanf("%f %f", &number, &power);

    if (power == 0)
    {
        result = 1;
    }
    else if (power > 0)
    {
        result = powerRecursive(number, number, power, 1);
    }
    else
    {
        number = 1 / number;
        power *= -1;
        result = powerRecursive(number, number, power, 1);
    }

    printf("The result is %f", result);
}

// 2. Реализовать функцию возведения числа a в степень b :
// c.* рекурсивно, используя свойство четности степени.

float powerOddness(int k, int s, float result)
{
    if (k != 0)
    {
        if (k % 2 == 0)
        {
            s = s * s;
            k = k / 2;
        }
        else
        {
            k--;
            result = result * s;
        }

        return powerOddness(k, s, result);
    }
    else
    {
        return result;
    }
}

void powerOddnessStart()
{
    int number, power;
    float result = 1;

    printf("Enter a number and a power (separated by a space):");
    scanf("%d %d", &number, &power);

    while (power < 0)
    {
        printf("This algorithm cannot process negative powers. Please enter a positive power: ");
        scanf("%d", &power);
    }

    int s = number, k = power;

    result = powerOddness(k, s, result);

    printf("The result is %f", result);
}

int main()
{
    powerOddnessStart();
    return 0;
}