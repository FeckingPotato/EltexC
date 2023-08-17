#include <malloc.h>

typedef struct node {
    int value;
    bool red;
    struct node* parent;
    struct node* left;
    struct node* right;
} node_t;

typedef struct {
    node_t* root;
    unsigned int size;
} tree_t;

void push(int value, tree_t* tree);

void pushRand(unsigned int amount, tree_t* tree);

void printTree(tree_t* tree);
