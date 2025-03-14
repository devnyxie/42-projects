#include "../includes/push_swap.h"

void print_stack(t_node *top) {
    if (!top) {
        printf("Stack is empty\n");
        printf("------------------\n");
        return;
    }

    printf("Stack Top\n");
    printf("------------------\n");
    
    t_node *current = top;
    while (current) {
        printf("│ %d\n", current->value);
        printf("│ ↓\n");
        current = current->next;
    }
    
    printf("------------------\n");
    printf("Stack Bottom\n");
}
