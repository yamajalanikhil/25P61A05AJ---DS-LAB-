

#include<stdio.h>

#include<stdlib.h>

#define MAX 5


int queue[MAX];



int front=-1;

int rear=-1;

void enquenue(int value);

void dequeue();

void display();

void peek();

int main()

{

	int choice,value;

	while(1)

	{

		printf("\n---QUEUE ADT USING ARRAYS---\n");

		printf("1.enqueue\n2.dequeue\n3.display\n4.peek\n5.exit\n");

		printf("Enter your choice:");

		scanf("%d",&choice);

		switch(choice)

		{

			case 1:

			printf("Enter the value");

			scanf("%d",&value);

			enquenue(value);

			break;

			case 2:

			dequeue();

			break;

			case 3:

			display();

			break;

			case 4:

			peek();

			break;

			case 5:

			exit(0);

			default:

			printf("Invalid choice");

			}

		}

	}

void enquenue(int value)

{

	if (rear==MAX-1)

	{

		printf("queue overload");

		}

	else

	{

		if (front==-1)

		front=0;

		rear++;

		queue[rear]=value;

		printf("inserted:%d",value);

		}

	}

void dequeue()

{

	if(front==-1||front>rear)

	{

		printf("queue underflow");

		}

	else

	{

		printf("dleted:%d",queue[front]);

		front++;

		}

	}

void display()

{

	int i;

	if(front==-1||front>rear)

	{

		printf("queue is empty");

		}

	else

	{

		printf("queue element are:");

		for(i=front;i<=rear;i++)

		{

			printf("%d",queue[i]);

			}

	}

}

void peek()

{if(front==-1||front>rear)

	{

		printf("queue underflow");

		}

	else

	{

		printf("dleted:%d",queue[front]);

		front++;

		}

	if(front==-1||front>rear)

	{

		printf("queue is empty");

		}

		else

		{

			printf("front element id %d",queue[front]);

			}

	}




