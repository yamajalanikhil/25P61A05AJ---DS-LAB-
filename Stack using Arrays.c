#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX];
int top = -1;
/* Function Prototypes */
int isFull();
int isEmpty();
void push();
void pop();
void peek();
void traverse();
int main()
{
int choice;
while(1)
{
printf("\n--- Stack Menu ---\n");
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Peek\n");
printf("4. Traverse\n");
printf("5. Exit\n");
printf("Enter your choice: ");
if(scanf("%d",&choice) != 1)
{
printf("Invalid input! Enter a number.\n");
exit(1);
}
switch(choice)
{
case 1: push();
break;
case 2: pop();
break;
case 3: peek();
break;
case 4: traverse();
break;
case 5: printf("Exiting program...\n");
exit(0);
default: printf("Invalid choice! Try again.\n");
}
}
return 0;
}
/* Check if stack is full */
int isFull()
{
return (top == MAX - 1);
}
/* Check if stack is empty */
int isEmpty()
{
return (top == -1);
}
/* Push Operation */
void push()
{
int value;
if(isFull())
{
printf("Stack Overflow!\n");
return;
}
printf("Enter value to push: ");
scanf("%d",&value);
stack[++top] = value;
printf("Element %d inserted successfully.\n", value);
}
/* Pop Operation */
void pop()
{
if(isEmpty())
{
printf("Stack Underflow!\n");
return;
}
printf("Deleted element is %d\n", stack[top--]);
}
/* Peek Operation */
void peek()
{
if(isEmpty())
{
printf("Stack is empty.\n");
return;
}
printf("Top element is %d\n", stack[top]);
}
/* Traverse Stack */
void traverse()
{
int i;
if(isEmpty())
{
printf("Stack is empty.\n");
return;
}
printf("Stack elements are:\n");
for(i = top; i >= 0; i--)
{
printf("%d\n", stack[i]);
}
}
