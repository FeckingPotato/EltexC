#include "list.h"
#include <malloc.h>
#include <stdlib.h>

void pushFirst(int value, list_t* list) {
    list->head = (node_t*) malloc(sizeof(list_t));
    list->tail = list->head;
    list->length = 1;
    list->head->value = value;
}

void pushHead(int value, list_t* list) {
    if (list->head == NULL && list->tail == NULL) {
        pushFirst(value, list);
        return;
    }
    node_t* exHead = list->head;
    list->head = (node_t*) malloc(sizeof(node_t));
    list->head->next = exHead;
    exHead->prev = list->head;
    list->head->value = value;
    list->length++;
}

void pushTail(int value, list_t* list) {
    if (list->head == NULL && list->tail == NULL) {
        pushFirst(value, list);
        return;
    }
    node_t* exTail = list->tail;
    list->tail = (node_t*) malloc(sizeof(node_t));
    list->tail->prev = exTail;
    exTail->next = list->tail;
    list->tail->value = value;
    list->length++;
}

node_t* traverse(unsigned int index, list_t* list) {
    if (index > list->length/2) {
        node_t* current = list->tail;
        for (unsigned int i = list->length-1; i > index; i--) {
            current = current->prev;
        }
        return current;
    }
    node_t* current = list->head;
    for (unsigned int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

void pushInd(int value, unsigned int index, list_t* list) {
   if (index > list->length) {
       return;
   }
    if (list->head == NULL && list->tail == NULL) {
        pushFirst(value, list);
        return;
    }
    if (index == 0) {
        pushHead(value, list);
        return;
    }
    if (index == list->length) {
        pushTail(value, list);
        return;
    }
    node_t* right = traverse(index, list);
    node_t* left = right->prev;
    left->next = (node_t*) malloc(sizeof(node_t));
    right->prev = left->next;
    node_t* current = left->next;
    current->prev = left;
    current->next = right;
    current->value = value;
    list->length++;
}

void removeHead(list_t* list) {
    if (list->head == NULL) {
        return;
    }
    node_t* exHead = list->head;
    if (list->length == 1) {
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    free(exHead);
    list->length--;
}

void removeTail(list_t* list) {
    if (list->tail == NULL) {
        return;
    }
    node_t* exTail = list->tail;
    if (list->length == 1) {
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    free(exTail);
    list->length--;
}

void removeInd(unsigned int index, list_t* list) {
    if (index > list->length-1) {
        return;
    }
    if (index == 0) {
        removeHead(list);
        return;
    }
    if (index == list->length-1) {
        removeTail(list);
        return;
    }
    node_t* toRemove = traverse(index, list);
    node_t* left = toRemove->prev;
    node_t* right = toRemove->next;
    left->next = right;
    right->prev = left;
    free(toRemove);
    list->length--;
}

void setValueHead(int value, list_t* list) {
    if (list->head == NULL) {
        return;
    }
    list->head->value = value;
}

void setValueTail(int value, list_t* list) {
    if (list->tail == NULL) {
        return;
    }
    list->tail->value = value;
}

void setValueInd(int value, unsigned int index, list_t* list) {
    if (index > list->length-1) {
        return;
    }
    traverse(index, list)->value = value;
}

int getValueHead(list_t* list) {
    if (list->head == NULL) {
        return 0;
    }
    return list->head->value;
}

int getValueTail(list_t* list) {
    if (list->tail == NULL) {
        return 0;
    }
    return list->tail->value;
}

int getValueInd(unsigned int index, list_t* list) {
    if (index > list->length-1) {
        return 0;
    }
    return traverse(index, list)->value;
}

void randFill(unsigned int amount, list_t* list) {
    for (unsigned int i = 0; i < amount; i++) {
        pushHead(rand() % 1000 - 500, list);
    }
}

void wipeList(list_t* list) {
    while (list->length > 0) {
        removeHead(list);
    }
}

void printListHead(list_t* list) {
    node_t* current = list->head;
    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("]\n");
}

void printListTail(list_t* list) {
    node_t* current = list->tail;
    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->prev;
    }
    printf("]\n");
}

void printList(list_t* list, bool reverse) {
    if (reverse) {
        printListTail(list);
        return;
    }
    printListHead(list);
}

void swap(node_t* first, node_t* second) {
    int temp = first->value;
    first->value = second->value;
    second->value = temp;
}

void sortAsc(list_t* list) {
    for (unsigned int i = 0; i < list->length - 1; i++) {
        bool swapped = false;
        node_t* current = list->head;
        node_t* next = current->next;
        for (unsigned int j = 0; j < list->length - i - 1; j++) {
            if (current->value > next->value) {
                swap(current, next);
                swapped = true;
            }
            current = next;
            next = current->next;
        }
        if (!swapped) {
            break;
        }
    }
}

void combGapUpdate(unsigned int* gap) {
    *gap = (*gap*10)/13;
    if (*gap < 1) {
        *gap = 1;
    }
}

void sortDesc(list_t* list) {
    unsigned int gap = list->length;
    bool swapped = true;
    while (gap != 1 || swapped) {
        combGapUpdate(&gap);
        swapped = false;
        node_t* current = list->head;
        node_t* next = current->next;
        for (unsigned int i = 0; i < gap - 1; i++) {
            next = next->next;
        }
        for (int i=0; i < list->length - gap; i++) {
            if (current->value < next->value) {
                swap(current, next);
                swapped = true;
            }
            current = current->next;
            next = next->next;
        }
    }
}
