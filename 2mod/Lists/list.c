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

int pushInd(int value, unsigned int index, list_t* list) {
   if (index > list->length) {
       return 1;
   }
    if (list->head == NULL && list->tail == NULL) {
        pushFirst(value, list);
        return 0;
    }
    if (index == 0) {
        pushHead(value, list);
        return 0;
    }
    if (index == list->length) {
        pushTail(value, list);
        return 0;
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
    return 0;
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

int removeInd(unsigned int index, list_t* list) {
    if (index > list->length-1) {
        return 1;
    }
    if (index == 0) {
        removeHead(list);
        return 0;
    }
    if (index == list->length-1) {
        removeTail(list);
        return 0;
    }
    node_t* toRemove = traverse(index, list);
    node_t* left = toRemove->prev;
    node_t* right = toRemove->next;
    left->next = right;
    right->prev = left;
    free(toRemove);
    list->length--;
    return 0;
}

int setValueHead(int value, list_t* list) {
    if (list->head == NULL) {
        return 1;
    }
    list->head->value = value;
    return 0;
}

int setValueTail(int value, list_t* list) {
    if (list->tail == NULL) {
        return 1;
    }
    list->tail->value = value;
    return 0;
}

int setValueInd(int value, unsigned int index, list_t* list) {
    if (index > list->length-1) {
        return 1;
    }
    traverse(index, list)->value = value;
    return 0;
}

result_t getValueHead(list_t* list) {
    result_t result = {0, 0};
    if (list->head == NULL) {
        result.error = 1;
        return result;
    }
    result.value = list->head->value;
    return result;
}

result_t getValueTail(list_t* list) {
    result_t result = {0, 0};
    if (list->tail == NULL) {
        result.error = 1;
        return result;
    }
    result.value = list->tail->value;
    return result;
}

result_t getValueInd(unsigned int index, list_t* list) {
    result_t result = {0, 0};
    if (index > list->length-1) {
        result.error = 1;
        return result;
    }
    result.value = traverse(index, list)->value;
    return result;
}

void randFill(unsigned int amount, list_t* list) {
    for (unsigned int i = 0; i < amount; i++) {
        pushHead(rand(), list);
    }
}

void wipeList(list_t* list) {
    while (list->length > 0) {
        removeHead(list);
    }
}

void printList(list_t* list) {
    node_t* current = list->head;
    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("]\n");
}

void swap(node_t* first, node_t* second) {
    int temp = first->value;
    first->value = second->value;
    second->value = temp;
}

void sortAsc(list_t* list) {
    bool swapped;
    for (unsigned int i = 0; i < list->length - 1; i++) {
        swapped = false;
        node_t* current = traverse(i, list);
        for (unsigned int j = 0; j < list->length - i - 1; j++) {
            if (current->value > current->next->value) {
                swap(current, current->next);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void sortDesc(list_t* list) {

}
