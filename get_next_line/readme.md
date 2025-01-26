Bonus approach in mind:

typedef struct {
    char *mem;
    size_t capacity;
    size_t start;
    size_t end;
} bufferInstance;

static bufferInstance *buffer[FD_LIMIT] = { NULL };
