CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
UTILS_DIR = utils
INSTR_DIR = instructions
LIBFT_DIR = libft
INCLUDES_DIR = includes

# Source files
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/radix.c $(SRC_DIR)/simple.c
UTILS_FILES = $(UTILS_DIR)/check_args.c $(UTILS_DIR)/ft_print.c $(UTILS_DIR)/index.c \
              $(UTILS_DIR)/mem.c $(UTILS_DIR)/stack.c $(UTILS_DIR)/stack_utils.c \
              $(UTILS_DIR)/utils.c $(UTILS_DIR)/debug.c $(UTILS_DIR)/ft_atoi.c \
              $(UTILS_DIR)/ft_isdigit.c $(UTILS_DIR)/ft_split.c
INSTR_FILES = $(INSTR_DIR)/pa.c $(INSTR_DIR)/pb.c $(INSTR_DIR)/ra.c $(INSTR_DIR)/rb.c \
              $(INSTR_DIR)/rr.c $(INSTR_DIR)/rra.c $(INSTR_DIR)/rrb.c $(INSTR_DIR)/rrr.c \
              $(INSTR_DIR)/sa.c $(INSTR_DIR)/sb.c $(INSTR_DIR)/ss.c

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o) $(UTILS_FILES:.c=.o) $(INSTR_FILES:.c=.o) $(LIBFT_FILES:.c=.o)

# Executable name
NAME = push_swap

# Include directories
INCLUDES = -I$(INCLUDES_DIR) -I$(LIBFT_DIR)

# Rules
all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re