#include "tree.h"

void pushFirst(int value, tree_t* tree) {
    tree->root = (node_t*) malloc(sizeof(node_t));
    tree->root->value = value;
}

node_t* getGrandparent(node_t* node) {
    return node->parent->parent;
}

node_t* getUncle(node_t* node) {
    node_t* grandparent = getGrandparent(node);
    if (node->parent == grandparent->left) {
        return grandparent->right;
    }
    return grandparent->left;
}

void rotate(node_t* parent, node_t* child) {
    while (parent->red) {

    }
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
    rotate(parent, child);
}
