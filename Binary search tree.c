#include <stdio.h>

#include <stdlib.h>

struct node {

 int data;

 struct node *left, *right;

};

struct node* insert(struct node* root, int data)

{

 if (root == NULL)

 {

 root = (struct node*)malloc(sizeof(struct node));

 root->data = data;

 root->left = root->right = NULL;

 }

 else if (data < root->data)

 root->left = insert(root->left, data);

 else

 root->right = insert(root->right, data);

 return root;

}

void inorder(struct node* root)

{

 if (root != NULL)

 {

 inorder(root->left);

 printf("%d ", root->data);

 inorder(root->right);

 }

}

int main()

{

 int n, i, x;

 struct node* root = NULL;

 printf("Enter number of nodes: ");

 scanf("%d", &n);

 for (i = 0; i < n; i++)

 {

 scanf("%d", &x);

 root = insert(root, x);
 }

 printf("Inorder Traversal: ");

 inorder(root);

 return 0;

}


