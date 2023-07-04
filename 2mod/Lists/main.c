#include "list.h"
#include <malloc.h>

int main() {
    list_t* list = (list_t*) malloc(sizeof(list_t));
    for (int i = 10; i > 0; i--) {
        pushTail(i, list);
    }
    randFill(10, list);
    printList(list);
    sortAsc(list);
    printList(list);
    return 0;
}
