#include "get_next_line.h"


# define INITIAL_BUFFER_SIZE (BUFFER_SIZE * 4)
# define BUFFER_GROWTH_FACTOR 2

static char *buffer = NULL;
static size_t buffer_capacity = 0;
static size_t buffer_start = 0;
static size_t buffer_end = 0;

// new_capacity = buffer_capacity == 0 ? INITIAL_BUFFER_SIZE : buffer_capacity * BUFFER_GROWTH_FACTOR;


