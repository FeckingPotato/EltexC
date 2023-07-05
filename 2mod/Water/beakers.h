typedef struct {
    unsigned int max;
    unsigned int current;
} beaker_t;

int initBeakers(beaker_t beakers[3]);

void pour(beaker_t* from, beaker_t* to);

void solve(beaker_t beakers[3], unsigned int R);
