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

typedef struct {
    int value;
    int error;
} result_t;

void pushHead(int value, list_t* list);

void pushTail(int value, list_t* list);

int pushInd(int value, unsigned int index, list_t* list);

void removeHead(list_t* list);

void removeTail(list_t* list);

int removeInd(unsigned int index, list_t* list);

int setValueHead(int value, list_t* list);

int setValueTail(int value, list_t* list);

int setValueInd(int value, unsigned int index, list_t* list);

result_t getValueHead(list_t* list);

result_t getValueTail(list_t* list);

result_t getValueInd(unsigned int index, list_t* list);

void randFill(unsigned int amount, list_t* list);

void wipeList(list_t* list);

void printList(list_t* list);

void sortAsc(list_t* list);

void sortDesc(list_t* list);
