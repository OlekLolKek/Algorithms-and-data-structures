#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

// 1. Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.

#define INPUT_LENGTH 32
#define HASH_LENGTH 16

int hash(char* string)
{
    float sum = 0;
    int length = strlen(string);

    for (int i = 0; i < length; i++)
    {
        sum += string[i];
    }

    return sum;
}

void hashStart()
{
    char input[INPUT_LENGTH] = "";

    puts("Please enter a string: ");
    gets_s(input, INPUT_LENGTH);

    int result = hash(input);

    char after[HASH_LENGTH + 1];
    sprintf(after, "%016d", result);

    printf("Your hash is %s", after);
}

// 2. Переписать программу, реализующую двоичное дерево поиска.
// а) Добавить в него обход дерева различными способами;
// б) Реализовать поиск в двоичном дереве поиска;

typedef struct TreeNode
{
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
} TreeNode;

void printTree(TreeNode* root)
{
    if (root)
    {
        printf("%d", root->value);
        if (root->left || root->right)
        {
            printf("(");

            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");

            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

TreeNode* createTreeNode(int value, TreeNode* parent)
{
    TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));

    tmp->left = tmp->right = NULL;
    tmp->value = value;
    tmp->parent = parent;
    return tmp;
}

void insertTreeNode(TreeNode** head, int value)
{
    TreeNode* tmp = NULL;
    if (*head == NULL)
    {
        *head = createTreeNode(value, NULL);
        return;
    }

    tmp = *head;
    while (tmp)
    {
        if (value >= tmp->value)
        {
            if (tmp->right)
            {
                tmp = tmp->right;
                continue;
            }
            else
            {
                tmp->right = createTreeNode(value, tmp);
                return;
            }
        }
        else if (value < tmp->value)
        {
            if (tmp->left)
            {
                tmp = tmp->left;
                continue;
            }
            else
            {
                tmp->left = createTreeNode(value, tmp);
                return;
            }
        }
    }
}

void preOrderTraversal(TreeNode* root)
{
    if (root)
    {
        printf("%d ", root->value);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void symmetricTraversal(TreeNode* root)
{
    if (root)
    {
        symmetricTraversal(root->left);
        printf("%d ", root->value);
        symmetricTraversal(root->right);
    }
}

void reverseTraversal(TreeNode* root)
{
    if (root)
    {
        reverseTraversal(root->left);
        reverseTraversal(root->right);
        printf("%d ", root->value);
    }
}

void binaryTreeSearch(TreeNode* root, int number)
{
    if (root == NULL)
    {
        printf("\nThe tree's root is NULL.");
        return;
    }

    TreeNode* tmp = root;
    int iterations = 0;

    while (tmp)
    {
        if (tmp->value == number)
        {
            printf("Found the value in %d iterations.", iterations);
            return;
        }
        else if (number > tmp->value)
        {
            if (tmp->right)
            {
                tmp = tmp->right;
                ++iterations;
            }
            else
            {
                printf("The tree doesn't have the entered value.");
                return;
            }
        }
        else if (number < tmp->value)
        {
            if (tmp->left)
            {
                tmp = tmp->left;
                ++iterations;
            }
            else
            {
                printf("The tree doesn't have the entered value.");
                return;
            }
        }
    }
}

void treeStart()
{
    TreeNode* tree = NULL;
    FILE* file = fopen("C:\\AlgorithmsData\\array.txt", "r");

    if (file == NULL)
    {
        puts("Can't open file.");
    }
    else
    {
        int count;
        fscanf(file, "%d", &count);
        for (int i = 0; i < count; i++)
        {
            int value;
            fscanf(file, "%d", &value);
            insertTreeNode(&tree, value);
        }

        fclose(file);
        printTree(tree);
        printf("\nPreOrderTraversal: ");
        preOrderTraversal(tree);
        printf("\nSymmetric Traversal: ");
        symmetricTraversal(tree);
        printf("\nReverse Traversal: ");
        reverseTraversal(tree);
        puts("");
        puts("");
        int searchNumber;
        printf("Please enter a number to search for: ");
        scanf("%d", &searchNumber);

        binaryTreeSearch(tree, searchNumber);
    }
}

int main()
{
    treeStart();

    return 0;
}