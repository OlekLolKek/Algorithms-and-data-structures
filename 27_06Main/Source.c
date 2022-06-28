#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define L long

// Pomazan Oleg, lesson 1 homework

// 1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах.
void bmiCounter()
{
    double weight, height;
    printf("Please enter your weight (kilograms): ");
    scanf("%lf", &weight);
    puts("");
    printf("Please enter your height (meters):");
    scanf("%lf", &height);

    double bmi = weight / (height * height);

    puts("");
    printf("Your BMI is %f", bmi);
}

// 2. Найти максимальное из четырех чисел. Массивы не использовать.
void maxNumber()
{
    int max = 0;

    printf("You need to enter 4 numbers.\n");

    for (int i = 0; i < 4; ++i)
    {
        int number;
        printf("Please enter a number: ");
        scanf("%d", &number);

        if (i == 0 || number > max)
        {
            max = number;
        }
    }

    printf("The maximum number you entered was %d\n", max);
}

// 3. Написать программу обмена значениями двух целочисленных переменных:
// a. с использованием третьей переменной;
void swapNumbersA()
{
    int a, b;
    printf("Please enter numbers a and b (separated with a space): ");
    scanf("%d %d", &a, &b);
    printf("Numbers before swapping: a = %d, b = %d\n", a, b);

    int temp = a;
    a = b;
    b = temp;

    printf("Numbers after swapping: a = %d, b = %d", a, b);
}

// 3. Написать программу обмена значениями двух целочисленных переменных:
// b. *без использования третьей переменной.
void swapNumbersB()
{
    int a, b;
    printf("Please enter numbers a and b (separated with a space): ");
    scanf("%d %d", &a, &b);
    printf("Numbers before swapping: a = %d, b = %d\n", a, b);

    a ^= b;
    b ^= a;
    a ^= b;

    printf("Numbers after swapping: a = %d, b = %d", a, b);
}

// 4. Написать программу нахождения корней заданного квадратного уравнения.
void squareEquation()
{
    //3x^2 - 13x + 14 = 0
    printf("The given square equation is 3 * x^2 - 13 * x + 14 = 0\n");

    float x1, x2;
    float a = 3, b = -13, c = 14;

    float D = pow(b, 2) - 4 * a * c;

    if (a == 0)
    {
        x1 = c / -b;
        printf("The equation has a single root: x = %f", x1);
    }
    else if (D > 0)
    {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        printf("The equation has two roots: x1 = %f, x2 = %f", x1, x2);
    }
    else
    {
        printf("The equation has no roots.");
    }
}

// 5. С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.
void seasonFromMonth()
{
    int month = 0;
    while (month != -1)
    {
        printf("\nPlease enter the month's number or enter -1 to quit: ");
        scanf("%d", &month);

        if (month == -1)
        {
            break;
        }

        if (month < 1 || month > 12)
        {
            printf("You entered a wrong month number.");
        }
        else if (month == 12 || (month > 0 && month < 3))
        {
            printf("Month number %d is a winter month.", month);
        }
        else if (month > 2 && month < 6)
        {
            printf("Month number %d is a spring month.", month);
        }
        else if (month > 5 && month < 9)
        {
            printf("Month number %d is a summer month.", month);
        }
        else if (month > 8 && month < 12)
        {
            printf("Month number %d is a autumn month.", month);
        }
    }
}

// 6. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
// Вывод кириллицей работает некорректно, так что сделал через транслит.
void displayAge()
{
    int age = 0;

    while (age < 1 || age > 150)
    {
        printf("Please enter your age (from 1 to 150 years): ");
        scanf("%d", &age);
    }

    int lastDigit = age % 10;

    if (lastDigit == 1)
    {
        printf("Your age is %d god.", age);
    }
    else if (lastDigit > 1 && lastDigit < 5)
    {
        printf("Your age is %d goda.", age);
    }
    else
    {
        printf("Your age is %d let.", age);
    }
}

// 7. С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2). Требуется определить, относятся поля к одному цвету или нет.
void chessBoard()
{
    int x1, y1, x2, y2;
    printf("Please enter the first field's coordiantes (x & y): ");
    scanf("%d %d", &x1, &y1);
    printf("Please enter the second field's coordiantes (x & y): ");
    scanf("%d %d", &x2, &y2);

    int x1Even = 0, y1Even = 0, x2Even = 0, y2Even = 0;

    if (x1 % 2 == 0)
        x1Even = 1;
    if (y1 % 2 == 0)
        y1Even = 1;
    if (x2 % 2 == 0)
        x2Even = 1;
    if (y2 % 2 == 0)
        y2Even = 1;

    int sameOddness1 = 0, sameOddness2 = 0;

    if (x1Even == y1Even)
        sameOddness1 = 1;
    if (x2Even == y2Even)
        sameOddness2 = 1;

    if (sameOddness1 == sameOddness2)
    {
        printf("The fields have the same color.");
    }
    else
    {
        printf("The fields have different colors.");
    }
}

// 8. Ввести a и b и вывести квадраты и кубы чисел от a до b.
void squaresAndCubes()
{
    int a, b;
    printf("Please enter numbers a and b (separated by a space): ");
    scanf("%d %d", &a, &b);

    for (int i = a; i <= b; ++i)
    {
        printf("\nCurrent number: %3d | Current number squared: %6.1f | Current number cubed: %8.1f", i, pow(i, 2), pow(i, 3));
    }
}

// 9. Даны целые положительные числа N и K. Используя только операции сложения и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления.
void division()
{
    int N = 0, K = 0;

    while (N <= 0 || K <= 0)
    {
        printf("Please enter positive numbers N and K (separated by a space): ");
        scanf("%d %d", &N, &K);
    }

    int result = 0, reminder = 0;
    int N2 = N;
    while (N2 - K >= 0)
    {
        N2 -= K;
        ++result;
    }

    reminder = N2;

    printf("The result of dividing %d by %d is %d\nThe reminder is %d", N, K, result, reminder);
}

// 10. Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа N нечетные цифры.
// Если имеются, то вывести True, если нет — вывести False.
void findOddDigits()
{
    int N = 0;

    while (N <= 0)
    {
        printf("Please enter positive number N: ");
        scanf("%d", &N);
    }
    puts("");

    int lastDigit;
    int N2 = N;

    while (N2 > 0)
    {
        lastDigit = N2 % 10;
        if (lastDigit % 2 == 1)
        {
            printf("True");
            return;
        }

        N2 /= 10;
    }

    printf("False");
}

// 11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8.
void average()
{
    int num;
    int sum = 0;
    int count = 0;

    while (1)
    {
        printf("Please enter a number or enter 0 to exit: ");
        scanf("%d", &num);

        if (num == 0)
            break;

        if (num > 0 && num % 2 == 0 && num % 10 == 8)
        {
            sum += num;
            ++count;
        }
    }

    if (count == 0)
    {
        printf("You didn't enter any positive even numbers ending with 8.");
    }
    else
    {
        float average = sum / count;
        printf("The average of all positive even numbers ending with 8 is %.2f", average);
    }
}

#define COUNT 3

// 12. Написать функцию нахождения максимального из трех чисел.
// Вроде это почти то же самое, что в задании 2, так что сделал через массивы.
void maxFromThree()
{
    int numbers[COUNT];

    for (int i = 0; i < COUNT; i++)
    {
        printf("Please enter a number: ");
        scanf("%d", &numbers[i]);
    }

    int max = numbers[0];
    for (int i = 0; i < COUNT; i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }

    printf("The maximum number you entered is %d", max);
}

// 13. * Написать функцию, генерирующую случайное число от 1 до 100.
// а) с использованием стандартной функции rand()
void randomA()
{
    srand(time(NULL));

    int count = rand() % 10;
    int result = rand() % 100;

    for (int i = 0; i < count; i++)
    {
        result = rand() % 100;
    }

    printf("Your random number is %d", result);
}

// 13. * Написать функцию, генерирующую случайное число от 1 до 100.
// б) без использования стандартной функции rand()
void randomB()
{
    int count = time(NULL) % 100;

    int x = 1, m = 100;
    int a = 3, b = 14;

    for (int i = 0; i < count; i++)
    {
        x = (a * x + b) % m;
        printf("%d\n", x);
    }

    printf("Your random number is %d", x);
}

int main(int argc, char* argv[])
{
    randomB();

    return 0;
}