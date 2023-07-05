typedef struct {
    int option;
    char modifier;
    unsigned int index;
} args_t;

args_t argParse(char input[], unsigned int length);
