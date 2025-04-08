CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC = pipex.c get_cmd_path.c utils.c
OBJ = $(SRC:.c=.o)
NAME = pipex

# Default target to compile everything
all: $(LIBFT) $(NAME)

# Compile pipex.c and link with libft
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

# Compile object files
%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

# Make sure libft is compiled
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Clean object files
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

# Clean everything (lib and obj)
fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
