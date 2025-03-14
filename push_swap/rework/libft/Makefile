# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OUT = libft.a

# Source files and object files
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# Default target
all: $(OUT)

# Create the library
$(OUT): $(OBJ)
	ar rcs $@ $^

# Clean up object files
clean:
	rm -f $(OBJ)

# Clean up object files and the library
fclean: clean
	rm -f $(OUT)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
