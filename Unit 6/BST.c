#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value <= root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

int isValidBST(struct TreeNode* root, struct TreeNode* minNode, struct TreeNode* maxNode) {
    if (root == NULL) {
        return 1;
    }

    if ((minNode != NULL && root->value <= minNode->value) || (maxNode != NULL && root->value >= maxNode->value)) {
        return 0;
    }

    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}

struct TreeNode* search(struct TreeNode* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }

    if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    struct TreeNode* root = NULL;

    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);

    if (isValidBST(root, NULL, NULL)) {
        printf("Binary Search Tree is valid.\n");
    } else {
        printf("Binary Search Tree is not valid.\n");
    }

    int valueToSearch = 4;
    struct TreeNode* result = search(root, valueToSearch);

    if (result != NULL) {
        printf("%d is present in the tree.\n", valueToSearch);
    } else {
        printf("%d is not present in the tree.\n", valueToSearch);
    }

    return 0;
}
