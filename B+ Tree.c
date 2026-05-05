#include <stdio.h>

#include <stdlib.h>

struct node {

 int data;

 struct node *next;

};

int main()

{

 struct node *head = NULL, *temp, *newnode;

 int n, i, x;

 printf("Enter number of keys: ");

 scanf("%d", &n);

 for (i = 0; i < n; i++)

 {

 newnode = (struct node*)malloc(sizeof(struct node));

 scanf("%d", &x);

 newnode->data = x;

 newnode->next = NULL;

 if (head == NULL)

 head = temp = newnode;

 else

 {

 temp->next = newnode;

 temp = newnode;

 }

 }

 printf("B+ Tree Leaf Traversal: ");

 temp = head;

 while (temp != NULL)

 {

 printf("%d ", temp->data);

 temp = temp->next;

 }

 return 0;

}
