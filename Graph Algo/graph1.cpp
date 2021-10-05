#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
} *root = NULL;
typedef struct node NODE;
void insert(NODE **root, int data)
{
    NODE *temp = NULL;
    if (!(*root))
    {
        temp = (NODE *)malloc(sizeof(NODE));
        temp->left = temp->right = NULL;
        temp->data = data;
        *root = temp;
        return;
    }
    if (data < (*root)->data)
    {
        insert(&(*root)->left, data);
    }
    else if (data > (*root)->data)
    {
        insert(&(*root)->right, data);
    }
}
int search(NODE *root, int Data)
{
    if (!(root))
    {
        return 0;
    }
    if (root->data == Data)
        return 1;
    if (Data < root->data)
    {
        search(root->left, Data);
    }
    else if (Data > root->data)
    {
        search(root->right, Data);
    }
}
int ancestors(NODE *root, int Data)
{
    if (root == NULL)
    {
        printf("NO node in tree is present");
        return 0;
    }
    if (root->data == Data)
    {
        printf("Given node reach");
        return 0;
    }
    else
    {
        if (root->data < Data)
        {
            printf("%d ", root->data);
            ancestors(root->right, Data);
            return 0;
        }
        else
        {
            printf("%d ", root->data);
            ancestors(root->left, Data);
            return 0;
        }
    }
}
int main()
{
    int i, n, data;
    printf("Enter the number of nodes: \n");
    scanf("%d", &n);
    printf("Enter the data for the %d nodes: \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insert(&root, data);
    }
    printf("Enter the node data that you want to find ancestors: ");
    scanf("%d", &data);
    if (search(root, data) == 1)
    {
        printf("Ancestors of the given data is :\n");
        ancestors(root, data);
    }
    else
    {
        printf("Node not present in the tree\n");
    }
    return 0;
}