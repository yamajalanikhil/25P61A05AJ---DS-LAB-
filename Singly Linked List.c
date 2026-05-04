#include <stdio.h>
#include <stdlib.h>

/* Definition of node */
struct node 
{ 
    int data; 
    struct node *next; 
};

struct node *head = NULL;

/* Function Prototypes */
void create();
void insert();
void deletee(); 
void traverse();

/* Main Function */
int main() 
{ 
    int choice;

    while (1) 
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create\n");
        printf("2. Insert at End\n"); 
        printf("3. Delete\n");
        printf("4. Traverse\n");
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: create();
                    break;
            case 2: insert();
                    break;
            case 3: deletee();
                    break;
            case 4: traverse();
                    break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}

/* Create Linked List */
void create() 
{
    int n, i, value;
    struct node *temp, *newnode;

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
    }

    printf("Node inserted successfully\n");
}

/* Delete a Node */
void deletee() 
{
    int value;
    struct node *temp, *prev;

    if (head == NULL) 
    { 
        printf("List is empty\n");
        return;
    }

    printf("Enter value to delete: "); 
    scanf("%d", &value);

    temp = head;

    /* If first node is to be deleted */
    if (temp->data == value)
    {
        head = temp->next;
        free(temp);
        printf("Node deleted\n");
        return;
    }

    /* Search for the node */
    while (temp != NULL && temp->data != value) 
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted\n");
}

/* Traverse the List */
void traverse() 
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    printf("Linked List: ");

    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
