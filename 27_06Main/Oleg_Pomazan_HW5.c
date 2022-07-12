#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define T char

struct TNode
{
    T value;
    struct TNode* next;
};

typedef struct TNode Node;

struct Stack
{
    Node* head;
    int size;
    int maxSize;
};

struct Stack globalStack;

int push(T value, struct Stack* stack)
{
    if (stack->size >= stack->maxSize)
    {
        printf("Stack Overflow.\n");
        return -1;
    }

    Node* tmp = (Node*)malloc(sizeof(Node));

    if (tmp != NULL)
    {
        tmp->value = value;
        tmp->next = stack->head;
        stack->head = tmp;
        stack->size++;
        return 0;
    }
    else
    {
        printf("Cannot allocate memory.\n");
        return -1;
    }
}

char pop(struct Stack* stack)
{
    if (globalStack.size == 0)
    {
        printf("The stack is empty.\n");
        return;
    }

    Node* next = NULL;
    T value;
    value = stack->head->value;
    next = stack->head;
    stack->head = stack->head->next;
    free(next);
    stack->size--;
    return value;
}

// 1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.

void decToBinStack(int number)
{
    while (number > 0)
    {
        push(number % 2 ? '1' : '0', &globalStack);
        number /= 2;
    }
}

void decToBinStackStart()
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
    globalStack.maxSize = 100;
    globalStack.head = NULL;

    decToBinStack(number);

    printf("The number in binary is: ");

    while (globalStack.size != 0)
    {
        printf("%c", pop(&globalStack));
    }
}

// 2. Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти.
// Если память не выделяется, то выводится соответствующее сообщение.
// Постарайтесь создать ситуацию, когда память не будет выделяться (добавлением большого количества данных).

void memoryAllocationErrorStart()
{
    globalStack.size = 2147483647;
    int result = 0;

    while (result != -1)
    {
        result = push('1', &globalStack);
    }
}

// Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
// Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.

// Например: (2 + (2 * 2)) или[2 / {5 * (4 + 7)}]

#define BRACES_LENGTH 64

int checkBraceSequence(char braces[BRACES_LENGTH])
{
    int i = 0;
    while (i < strlen(braces))
    {
        if (braces[i] == '(' || braces[i] == '[' || braces[i] == '{')
        {
            push(braces[i], &globalStack);
        }
        else
        {
            if (braces[i] == ')')
                if (pop(&globalStack) != '(')
                    return -1;

            if (braces[i] == ']')
                if (pop(&globalStack) != '[')
                    return -1;

            if (braces[i] == '}')
                if (pop(&globalStack) != '{')
                    return -1;
        }
        ++i;
    }

    return 0;
}

void bracesStart()
{
    globalStack.maxSize = BRACES_LENGTH;
    globalStack.head = NULL;
    char braces[BRACES_LENGTH] = "";
    int number;

    printf("Please enter a brace sequence: ");
    gets_s(braces, BRACES_LENGTH);

    int result = checkBraceSequence(braces);

    printf("The brace sequence is %s", result == 0 ? "correct" : "incorrect");
}

// 4. *Создать функцию, копирующую односвязный список (то есть создает в памяти копию односвязного списка, не удаляя первый список).

void displayStack(struct Stack* displayingStack)
{
    if (displayingStack->head == NULL)
    {
        printf("Empty.");
    }
    else
    {
        Node* current = displayingStack->head;
        while (current != NULL)
        {
            printf("%c ", current->value);
            current = current->next;
        }
    }
}

void reverseStack(struct Node** head)
{
    Node* previous = NULL;
    Node* current = *head;
    Node* next = NULL;
    
    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    *head = previous;
}

struct Stack newStack;

struct Stack* copyStack(struct Stack original)
{
    newStack.head = NULL;
    newStack.maxSize = original.maxSize;

    if (original.head != NULL)
    {
        Node* currentOriginal = original.head;
        Node* currentNew = newStack.head;

        while (currentOriginal != NULL)
        {
            Node* newElement = (Node*)malloc(sizeof(Node));

            newElement->value = currentOriginal->value;
            newElement->next = newStack.head;
            newStack.head = newElement;
            newStack.size++;

            currentOriginal = currentOriginal->next;
            currentNew = newStack.head;
        }
    }

    reverseStack(&newStack.head);

    return &newStack;
}

stackCopyStart()
{
    globalStack.maxSize = 100;
    globalStack.head = NULL;

    push('a', &globalStack);
    push('b', &globalStack);
    push('c', &globalStack);
    push('d', &globalStack);
    push('e', &globalStack);

    printf("Original stack: ");

    displayStack(&globalStack);

    struct Stack* newStack = copyStack(globalStack);

    printf("\nCopied stack: ");

    displayStack(newStack);
}

int main()
{
    stackCopyStart();

    return 0;
}