CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC = pipex.c get_cmd_path.c processes.c utils.c
OBJ = $(SRC:.c=.o)
NAME = pipex

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

# Compile object files
%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

# Compile libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Clean obj files
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

# Clean everything (lib and obj)
fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
