#include <stdio.h>
#include <stdlib.h>
/* Node structure */
struct node {
int data;
struct node *next;
};
struct node *head = 0;
/* Function declarations */
void create();
void insertBegin(); // Insert at beginning
void insertEnd(); // Insert at end
void deleteNode();
void traverse();
/* Main function */
int main() {
int choice;
while (1) {
printf("\n--- Circular Linked List Menu ---\n");
printf("1. Create List\n");
printf("2. Insert at Beginning\n");
printf("3. Insert at End\n");
printf("4. Delete Node\n");
printf("5. Traverse List\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1: create(); break;
case 2: insertBegin(); break;
case 3: insertEnd(); break;
case 4: deleteNode(); break;
case 5: traverse(); break;
case 6: exit(0);
default: printf("Invalid choice\n");
}
}
}
/* Create circular linked list */
void create() {
int n, i, val;
struct node *newnode, *temp;
printf("Enter number of nodes: ");
scanf("%d", &n);
for (i = 0; i < n; i++) {
newnode = (struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d", &val);
newnode->data = val;
if (head == NULL) {
head = newnode;
newnode->next = head;
} else {
temp = head;
while (temp->next != head)
temp = temp->next;
temp->next = newnode;
newnode->next = head;
}
}
printf("Circular Linked List created successfully.\n");
}
/* Insert node at beginning */
void insertBegin() {
int val;
struct node *newnode, *temp;
newnode = (struct node*)malloc(sizeof(struct node));
printf("Enter value to insert at beginning: ");
scanf("%d", &val);
newnode->data = val;
if (head == NULL) {
head = newnode;
newnode->next = head;
}
else {
temp = head;
while (temp->next != head)
temp = temp->next;
newnode->next = head;
temp->next = newnode;
head = newnode;
}
printf("Node inserted at beginning successfully.\n");
}
/* Insert node at end */
void insertEnd() {
int val;
struct node *newnode, *temp;
newnode = (struct node*)malloc(sizeof(struct node));
printf("Enter value to insert at end: ");
scanf("%d", &val);
newnode->data = val;
if (head == NULL) {
head = newnode;
newnode->next = head;
}
else {
temp = head;
while (temp->next != head)
temp = temp->next;
temp->next = newnode;
newnode->next = head;
}
printf("Node inserted at end successfully.\n");
}
/* Delete node by value */
void deleteNode() {
int val;
struct node *temp, *prev;
if (head == NULL) {
printf("List is empty. Nothing to delete.\n");
return;
}
printf("Enter value to delete: ");
scanf("%d", &val);
temp = head;
prev = NULL;
if (temp->data == val) {
if (temp->next == head) {
free(temp);
head = NULL;
printf("Only node deleted. List is now empty.\n");
return;
}
prev = head;
while (prev->next != head)
prev = prev->next;
prev->next = temp->next;
head = temp->next;
free(temp);
printf("Head node deleted successfully.\n");
return;
}
prev = temp;
temp = temp->next;
while (temp != head && temp->data != val) {
prev = temp;
temp = temp->next;
}
if (temp == head) {
printf("Value not found in list.\n");
}
else {
prev->next = temp->next;
free(temp);
printf("Node deleted successfully.\n");
}
}
/* Traverse circular linked list */
void traverse() {
struct node *temp;
if (head == NULL) {
printf("List is empty.\n");
return;
}
printf("Circular Linked List: ");
temp = head;
do {
printf("%d -> ", temp->data);
temp = temp->next;
} while (temp != head);
printf("(back to head)\n");
}
