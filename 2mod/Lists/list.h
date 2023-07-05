typedef struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
} node_t;

typedef struct {
    unsigned int length;
    node_t* head;
    node_t* tail;
} list_t;

void pushHead(int value, list_t* list);

void pushTail(int value, list_t* list);

void pushInd(int value, unsigned int index, list_t* list);

void removeHead(list_t* list);

void removeTail(list_t* list);

void removeInd(unsigned int index, list_t* list);

void setValueHead(int value, list_t* list);

void setValueTail(int value, list_t* list);

void setValueInd(int value, unsigned int index, list_t* list);

int getValueHead(list_t* list);

int getValueTail(list_t* list);

int getValueInd(unsigned int index, list_t* list);

void randFill(unsigned int amount, list_t* list);

void wipeList(list_t* list);

void printList(list_t* list, bool reverse);

void sortAsc(list_t* list);

void sortDesc(list_t* list);
