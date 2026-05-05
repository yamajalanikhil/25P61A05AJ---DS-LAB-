#include <stdio.h>

#include <stdlib.h>

#define MAX 3

struct BTreeNode {

 int val[MAX];

 struct BTreeNode *child[MAX + 1];

 int count;

};

struct BTreeNode* createNode(int val)

{

 struct BTreeNode* node = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));

 node->val[0] = val;

 node->count = 1;

 for (int i = 0; i <= MAX; i++)

 node->child[i] = NULL;

 return node;

}

void traverse(struct BTreeNode* root)

{

 if (root != NULL)

 {

 for (int i = 0; i < root->count; i++)

 {

 traverse(root->child[i]);

 printf("%d ", root->val[i]);

 }

 traverse(root->child[root->count]);

 }

}

int main()

{

 struct BTreeNode* root = createNode(10);

 root->child[0] = createNode(5);

 root->child[1] = createNode(20);

 printf("B-Tree Traversal: ");

 traverse(root);

 return 0;

}


