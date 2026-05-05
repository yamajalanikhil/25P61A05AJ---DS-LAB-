#include <stdio.h>
#include <stdlib.h>
/* Structure definition */
struct node
{
int data;
struct node *next;
};
/* Global pointers */
struct node *front = NULL, *rear = NULL;
/* Function declarations */
void enqueue();
void dequeue();
void peek();
void display();
int count();
void search();
int isEmpty();
int isFull();
/* Main function */
int main()
{
int choice;
while(1)
{
printf("\n=========== Queue Using Linked List ===========\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Peek\n");
printf("4. Display\n");
printf("5. Count\n");
printf("6. Search\n");
printf("7. Exit\n");
printf("Enter your choice: ");
if(scanf("%d", &choice) != 1){
printf("Invalid input!\n");
exit(0);
}
switch(choice)
{
case 1: enqueue(); break;
case 2: dequeue(); break;
case 3: peek(); break;
case 4: display(); break;
case 5: printf("Total elements: %d\n", count()); break;
case 6: search(); break;
case 7:
printf("Exiting program...\n");
exit(0);
default:
printf("Invalid choice\n");
}
}
}
/* Check if queue is empty */
int isEmpty()
{
return (front == NULL);
}
/* Check if queue is full (memory check) */
int isFull()
{
struct node *temp = (struct node*)malloc(sizeof(struct node));
if(temp == NULL)
return 1;
free(temp);
return 0;
}
/* Enqueue operation */
void enqueue()
{
struct node *ptr;
int value;if(isFull())
{
printf("Queue Overflow\n");
return;
}
ptr = (struct node*)malloc(sizeof(struct node));
printf("Enter element to insert: ");
scanf("%d", &value);
ptr->data = value;
ptr->next = NULL;
if(rear == NULL)
{
front = rear = ptr;
}
else
{
rear->next = ptr;
rear = ptr;
}
printf("Element inserted successfully\n");
}
/* Dequeue operation */
void dequeue()
{
struct node *temp;
if(isEmpty())
{
printf("Queue Underflow\n");
return;
}
temp = front;
printf("Deleted element: %d\n", temp->data);
front = front->next;
if(front == NULL)
rear = NULL;free(temp);
}
/* Peek operation */
void peek()
{
if(isEmpty())
{
printf("Queue is empty\n");
return;
}
printf("Front element: %d\n", front->data);
}
/* Display operation */
void display()
{
struct node *temp;
if(isEmpty())
{
printf("Queue is empty\n");
return;
}
temp = front;
printf("Queue elements: Front -> ");
while(temp != NULL)
{
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}
/* Count elements */
int count()
{
int c = 0;
struct node *temp = front;while(temp != NULL)
{
c++;
temp = temp->next;
}
return c;
}
/* Search element */
void search()
{
int key, pos = 1, found = 0;
struct node *temp = front;
if(isEmpty())
{
printf("Queue is empty\n");
return;
}
printf("Enter element to search: ");
scanf("%d", &key);
while(temp != NULL)
{
if(temp->data == key)
{
printf("Element found at position %d\n", pos);
found = 1;
break;
}
temp = temp->next;
pos++;
}
if(!found)
printf("Element not found\n");
}
