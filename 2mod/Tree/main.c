#include "tree.h"
#include <stdio.h>

int main() {
    tree_t* tree = (tree_t*) malloc(sizeof(tree_t));
    push(10, tree);
    push(5, tree);
    push(15, tree);
    return 0;
}
