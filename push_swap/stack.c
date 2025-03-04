#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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


// === MEMORY WIPE ===
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

// === STACK ACTIONS ===
void push(Node **top, int value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(!newNode)
		return;
	newNode->next = *top;
	newNode->value = value;
	*top = newNode;
}

int main(void){
	Set *set = init_set();
	Node *example = malloc(sizeof(Node));

	push(&(set->a->top), 20);

	print_stack(set->a->top);
	free_set(set);
	return(0);
}
