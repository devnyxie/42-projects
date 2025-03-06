#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

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

    while (*str) {
        if(*str >= '0' && *str <= '9'){
            // Check for overflow before adding new digit
            if (result > (INT_MAX - (*str - '0')) / 10)
                error(set);
            result = result * 10 + (*str - '0');
            str++;
        } else {
            error(set);
        }

    }

    return result * sign;
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

// ??? Find the smallest number in the stack
int find_min(Stack *stack) {
    if (!stack->top)
        return 0;
    
    int min = stack->top->value;
    Node *current = stack->top->next;
    
    while (current) {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return min;
}

// ??? Find the largest number in the stack
int find_max(Stack *stack) {
    if (!stack->top)
        return 0;
    
    int max = stack->top->value;
    Node *current = stack->top->next;
    
    while (current) {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return max;
}

// ??? Find the position of a number in stack
int find_position(Stack *stack, int num) {
    int pos = 0;
    Node *current = stack->top;
    
    while (current) {
        if (current->value == num)
            return pos;
        current = current->next;
        pos++;
    }
    return -1;
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
void sa(Set *set) { swap(set->a); }
void sb(Set *set) { swap(set->b); }
void ss(Set *set) { sa(set); sb(set); }

void pa(Set *set) { push_to(set->b, set->a); }
void pb(Set *set) { push_to(set->a, set->b); }

void ra(Set *set) { rotate(set->a); }
void rb(Set *set) { rotate(set->b); }
void rr(Set *set) { ra(set); rb(set); }

void rra(Set *set) { reverse_rotate(set->a); }
void rrb(Set *set) { reverse_rotate(set->b); }
void rrr(Set *set) { rra(set); rrb(set); }


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

void turk_sort(Set *set) {

}

// === TESTING SUITE ===
int main(int argc, char **argv) {
    Set *set = init_set();

    while(argc > 1){
        add(set->a, ft_atoi(argv[--argc], set));
    }
    
    printf("Before sorting:\n");
    print_stack(set->a->top);

    turk_sort(set);

    printf("\nAfter sorting:\n");
    print_stack(set->a->top);

    free_set(set);
    return(0);
}