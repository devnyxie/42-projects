#include "../includes/push_swap.h"

void error(Set *set){
    ft_print("Error\n");
    free_set(set);
    exit(1);
}