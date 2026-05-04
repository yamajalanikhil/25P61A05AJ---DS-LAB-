#include <stdio.h>
#include <stdlib.h>

/* Definition of Doubly Linked List Node */
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* Function Prototypes */
void create();
void insert();
void deleteNode();
void traverseForward();
void traverseBackward();

/* Main Function */
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create\n");
        printf("2. Insert at End\n");
        printf("3. Delete\n");
        printf("4. Traverse Forward\n");
        printf("5. Traverse Backward\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: create(); break;
            case 2: insert(); break;
            case 3: deleteNode(); break;
            case 4: traverseForward(); break;
            case 5: traverseBackward(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}

/* Create Doubly Linked List */
void create()
{
    int n, i, value;
    struct node *newnode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
            newnode->prev = temp;
        }
    }
}

/* Insert at End */
void insert()
{
    int value;
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Node inserted successfully\n");
}

/* Delete a Node */
void deleteNode()
{
    int value;
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Value not found\n");
        return;
    }

    /* If deleting first node */
    if (temp->prev == NULL)
        head = temp->next;
    else
        temp->prev->next = temp->next;

    /* If deleting last node */
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node deleted successfully\n");
}

/* Traverse Forward */
void traverseForward()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    printf("Forward Traversal: ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Traverse Backward */
void traverseBackward()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    /* Move to last node */
    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward Traversal: ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}
