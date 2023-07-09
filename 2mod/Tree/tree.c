#include "tree.h"
#include <stdlib.h>

void pushFirst(int value, tree_t* tree) {
    tree->root = (node_t*) malloc(sizeof(node_t));
    tree->root->value = value;
    tree->size = 1;
}

void leftRotate(tree_t* tree, node_t* x) {
    node_t* y = x->right;
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        tree->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rightRotate(tree_t* tree, node_t* x) {
    node_t* y = x->left;
    x->left = y->right;

    if (y->right != NULL)
        y->right->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        tree->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->right = x;
    x->parent = y;
}

void fix(tree_t* tree, node_t* newNode) {
    while (newNode != tree->root && newNode->parent->red) {
        if (newNode->parent == newNode->parent->parent->left) {
            node_t* uncle = newNode->parent->parent->right;
            if (uncle != NULL && uncle->red) {
                newNode->parent->red = false;
                uncle->red = false;
                newNode->parent->parent->red = true;
                newNode = newNode->parent->parent;
            } else {
                if (newNode == newNode->parent->right) {
                    newNode = newNode->parent;
                    leftRotate(tree, newNode);
                }
                newNode->parent->red = false;
                newNode->parent->parent->red = true;
                rightRotate(tree, newNode->parent->parent);
            }
        } else {
            node_t* uncle = newNode->parent->parent->left;
            if (uncle != NULL && uncle->red) {
                newNode->parent->red = false;
                uncle->red = false;
                newNode->parent->parent->red = true;
                newNode = newNode->parent->parent;
            } else {
                if (newNode == newNode->parent->left) {
                    newNode = newNode->parent;
                    rightRotate(tree, newNode);
                }

                newNode->parent->red = false;
                newNode->parent->parent->red = true;
                leftRotate(tree, newNode->parent->parent);
            }
        }
    }

    tree->root->red = false;
}

void push(int value, tree_t* tree) {
    if (tree->root == NULL) {
        pushFirst(value, tree);
        return;
    }
    node_t* parent = NULL;
    node_t* child = tree->root;
    while (child != NULL) {
        parent = child;
        if (value < parent->value) {
            child = parent->left;
        }
        else {
            child = parent->right;
        }
    }
    child = (node_t*) malloc(sizeof(node_t));
    child->parent = parent;
    child->value = value;
    child->red = true;
    if (child->value < parent->value) {
        parent->left = child;
    }
    else {
        parent->right = child;
    }
    fix(tree, child);
    tree->size++;
}

void printRecursive(node_t* node, unsigned int level) {
   if (node == NULL) return;

    for (int i = 0; i < level; i++) {
        printf(" ");
    }
    char colour = 'B';
    if (node->red) {
        colour = 'R';
    }
    printf("%d (%c) ", node->value, colour);
    printf("\n");
    printRecursive(node->left, level + 1);
    printRecursive(node->right, level + 1);

}

void printTree(tree_t* tree) {
    printRecursive(tree->root, 0);
}

void pushRand(unsigned int amount, tree_t* tree) {
    for (unsigned int i = 0; i < amount; i++) {
        push(rand() % 1000 - 500, tree);
    }
}
