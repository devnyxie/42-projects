#include "../includes/push_swap.h"

void add(Stack *stack, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
        return;
    
    newNode->value = value;
    newNode->index = -1;
    newNode->next = stack->top;
    stack->top = newNode;
}

void add_end(Stack *stack, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
        return;

    newNode->value = value;
    newNode->index = -1;
    newNode->next = NULL;

    if (!stack->top) {
        stack->top = newNode;
    } else {
        Node *current = stack->top;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

static void fill_stack(char **argv, int argc, Stack *a) {
    char **args;
    int i;

    i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
    while (args[i])
	{
		add_end(a, ft_atoi(args[i]));
		i++;
	}
    index_stack(a);
	if (argc == 2)
        free_args(args);
}

Set *init_set(int argc, char **argv)
{
	Set *set = malloc(sizeof(Set));
	if(!set)
		error(set);
	set->a = malloc(sizeof(Stack));
	set->b = malloc(sizeof(Stack));
	if(!set->a || !set->b)
		error(set);
	set->a->top = NULL;
    set->b->top = NULL;
    fill_stack(argv, argc, set->a);
    return set;
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