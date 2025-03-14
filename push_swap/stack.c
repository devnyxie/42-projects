#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

typedef struct s_node
{
	int value;
	struct s_node *prev; // simplified rotations
	struct s_node *next;
} Node;

typedef struct s_stack
{
	Node *top;
	Node *bottom; // simplified rotations
	int size;
} Stack;

typedef struct s_ps
{
	Stack *a;
	Stack *b;
} Set;

// === STRUCT INIT ===
Set *init_set(void) {
	Set *set = malloc(sizeof(Set));
	if(!set){
		return(NULL);
	}
	set->a = malloc(sizeof(Stack));
	set->b = malloc(sizeof(Stack));
	if(!set->a || !set->b){
		free(set->a);
		free(set->b);
		free(set);
		return(NULL);
	}
	
	set->a->top = NULL;
	set->a->bottom = NULL;
	set->a->size = 0;

	set->b->top = NULL;
	set->b->bottom = NULL;
	set->b->size = 0;

	return(set);
}

// === MEMORY ===
void free_stack(Stack *stack){
	Node *current = stack->top;
	Node *next;

	while(current){
		next = current->next;
		free(current);
		current = next;		
	}
	free(stack);
}

void free_set(Set *set){
	if(set){
		if(set->a)
			free_stack(set->a);
		if(set->b)
			free_stack(set->b);
		free(set);
	}
}


// === UTILS ===
void print_stack(Node *top) {
    if (!top) {
        printf("Stack is empty\n");
        printf("------------------\n");
        return;
    }

    printf("Stack Top\n");
    printf("------------------\n");
    
    Node *current = top;
    while (current) {
        printf("│ %d\n", current->value);
        printf("│ ↓\n");
        current = current->next;
    }
    
    printf("------------------\n");
    printf("Stack Bottom\n");
}

void error(Set *set){
    printf("Error\n");
    free_set(set);
    exit(1);
}

// modified atoi
int ft_atoi(const char *str, Set *set) {
    int result = 0;
    int sign = 1;

    // Check for negative sign
    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str) {
        if(*str >= '0' && *str <= '9'){
            // Check for overflow before adding new digit
            if (result > (INT_MAX - (*str - '0')) / 10){
                printf("overflow\n");
                error(set);
            }
                
            result = result * 10 + (*str - '0');
            str++;
        } else {
            printf("not a valid digit: %s\n", str);
            error(set);
        }
    }

    return result * sign;
}

void sort_array(int *array, int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}


// === STACK LOW OPERATIONS ===
void swap(Stack *stack) {
    if (!stack->top || !stack->top->next)
        return;
    
    int temp = stack->top->value;
    stack->top->value = stack->top->next->value;
    stack->top->next->value = temp;
}

void add(Stack *stack, int value){
    // update top, size and bottom
    Node* newNode = (Node*)malloc(sizeof(Node));
	if(!newNode)
		return;
    newNode->prev = NULL;
    newNode->next = stack->top;
    newNode->value = value;

    if (stack->top)
        stack->top->prev = newNode; // if top exists, update it's prev ptr to newly created node
    else
        stack->bottom = newNode; // first elem becomes the bottom too
    
    stack->top = newNode;
    stack->size++;
}

void push_to(Stack *src, Stack *dst) {
    if (!src->top)
        return;
    
	// detach node from src
    Node *temp = src->top;
    src->top = src->top->next;
	// if it's not NULL, set prev as NULL (since it's the head)
    if (src->top)
        src->top->prev = NULL;
    else
		// if it is NULL, this means that the stack is empty,
		// therefore the bottom should be NULL as well
        src->bottom = NULL;
    
	// attach detached node to dst
    temp->next = dst->top;
	// if dst is not empty, set prev to the newly attached node
    if (dst->top)
        dst->top->prev = temp;
    else
		// if it is empty, set bottom to the newly attached node (1 element stack)
        dst->bottom = temp;
    dst->top = temp;
    
    src->size--;
    dst->size++;
}

int is_sorted(Stack *stack) {
    Node *current = stack->top;
    
    while (current && current->next) {
        if (current->value > current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
}

// Rotate: top element goes to bottom
void rotate(Stack *stack) {
    if (!stack->top || stack->size <= 1)
        return;
    
    Node *temp = stack->top;
    stack->top = stack->top->next;
    stack->top->prev = NULL;
    
    temp->next = NULL;
    temp->prev = stack->bottom;
    stack->bottom->next = temp;
    stack->bottom = temp;
}

// Reverse rotate: bottom element goes to top
void reverse_rotate(Stack *stack) {
    if (!stack->top || stack->size <= 1)
        return;
    
    Node *temp = stack->bottom;
    stack->bottom = stack->bottom->prev;
    stack->bottom->next = NULL;
    
    temp->prev = NULL;
    temp->next = stack->top;
    stack->top->prev = temp;
    stack->top = temp;
}

// === STACK HIGH OPERATIONS ===
void sa(Set *set) { printf("sa\n"); swap(set->a); }
void sb(Set *set) { printf("sb\n"); swap(set->b); }
void ss(Set *set) { printf("ss\n"); sa(set); sb(set); }

void pa(Set *set) { printf("pa\n"); push_to(set->b, set->a); }
void pb(Set *set) { printf("pb\n"); push_to(set->a, set->b); }

void ra(Set *set) { printf("ra\n"); rotate(set->a); }
void rb(Set *set) { printf("rb\n"); rotate(set->b); }
void rr(Set *set) { printf("rr\n"); ra(set); rb(set); }

void rra(Set *set) { printf("rra\n"); reverse_rotate(set->a); }
void rrb(Set *set) { printf("rrb\n"); reverse_rotate(set->b); }
void rrr(Set *set) { printf("rrr\n"); rra(set); rrb(set); }


// === ALGORITHM ===
void sort_three(Set *set) {
    int a = set->a->top->value;
    int b = set->a->top->next->value;
    int c = set->a->bottom->value;

    if (a > b && b < c && a < c)
        sa(set);
    else if (a > b && b > c)
    {
        sa(set);
        rra(set);
    }
    else if (a > b && b < c && a > c)
        ra(set);
    else if (a < b && b > c && a < c)
    {
        sa(set);
        ra(set);
    }
    else if (a < b && b > c && a > c)
        rra(set);
}

// Thoughts

// 0. Sort the stack
// 1. Find the square root of the stack size
// 2. Divide the stack into N chunks
// 3. Push each chunk to stack B
// 4. Push everything from stack B to stack A
// 5. Sort the stack if needed

void turk_sort(Set *set, int *sorted_array) {
    int size = set->a->size;
    if (size <= 3) {
        sort_three(set);
        return;
    }

    // Calculate optimal chunk size based on input size
    int chunk_count = (int)sqrt(size);
    int chunk_size = size / chunk_count;
    
    // Step 1: Divide the stack into chunks and push to B
    for (int i = 0; i < chunk_count; i++) {
        int start_idx = i * chunk_size;
        int end_idx = (i + 1) * chunk_size - 1;
        if (i == chunk_count - 1)
            end_idx = size - 1; // Last chunk may be larger
            
        // Find values in current chunk
        int min = sorted_array[start_idx];
        int max = sorted_array[end_idx];
        
        // Process stack A until we've checked all elements
        int checked = 0;
        int initial_size = set->a->size;
        while (checked < initial_size) {
            if (set->a->top->value >= min && set->a->top->value <= max) {
                pb(set); // Push to B if in current chunk
                
                // Optimize B stack organization
                if (set->b->size > 1 && set->b->top->value < min + (max - min) / 2) {
                    rb(set); // Rotate B if value is in lower half of chunk
                }
            } else {
                ra(set); // Keep value in A if not in current chunk
            }
            checked++;
        }
    }
    
    // Step 2: Push remaining elements (if any)
    while (set->a->size > 0) {
        pb(set);
    }
    
    // Step 3: Push back elements to A in descending order
    while (set->b->size > 0) {
        int max_pos = 0;
        int max_val = INT_MIN;
        Node *current = set->b->top;
        int pos = 0;
        
        // Find the maximum value in B
        while (current) {
            if (current->value > max_val) {
                max_val = current->value;
                max_pos = pos;
            }
            current = current->next;
            pos++;
        }
        
        // Optimize rotation direction
        if (max_pos < set->b->size / 2) {
            // Position is in first half, rotate until at top
            while (set->b->top->value != max_val)
                rb(set);
        } else {
            // Position is in second half, reverse rotate
            while (set->b->top->value != max_val)
                rrb(set);
        }
        
        // Push maximum to A
        pa(set);
    }
}




// === TESTING SUITE ===

int main(int argc, char **argv) {
    Set *set = init_set();
    int *sorted_arr = NULL;

    if(argc > 1){
        sorted_arr = malloc(sizeof(int) * argc - 1);
        if(!sorted_arr){
            printf("mem fail\n");
            error(set);
        }
            
        while(argc > 1){
            int num = ft_atoi(argv[--argc], set);
            add(set->a, num);
            sorted_arr[argc] = num;
        }
        sort_array(sorted_arr, argc - 1);

        // printf("Before sorting:\n");
        // print_stack(set->a->top);

        turk_sort(set, sorted_arr);

        // printf("\nAfter sorting:\n");
        // print_stack(set->a->top);

        free_set(set);
    }
    return(0);
}