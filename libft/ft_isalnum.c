#include "ft_isalpha.h"
#include "ft_isdigit.h"

#include <stdio.h>

int ft_isalnum(int c){
	return (ft_isalpha(c) || ft_isdigit(c));
}
