#include "tree.h"
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t;
    srand((unsigned) time(&t));
    tree_t* tree = (tree_t*) malloc(sizeof(tree_t));
    pushRand(10, tree);
    printTree(tree);
    return 0;
}
