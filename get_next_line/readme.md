Awesome code passing all possible tests. Was too lazy to rework it for norminette, so I just left it as is.

Bonus approach in mind:
```c
typedef struct {
    char *mem;
    size_t capacity;
    size_t start;
    size_t end;
} bufferInstance;

static bufferInstance *buffer[FD_LIMIT] = { NULL };
```
