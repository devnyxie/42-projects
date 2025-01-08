CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC = ft_printf.c \
	  $(LIBFT_DIR)/ft_atoi.c \
	  $(LIBFT_DIR)/ft_bzero.c \
	  $(LIBFT_DIR)/ft_calloc.c \
	  $(LIBFT_DIR)/ft_isalnum.c \
	  $(LIBFT_DIR)/ft_isalpha.c \
	  $(LIBFT_DIR)/ft_isascii.c \
	  $(LIBFT_DIR)/ft_isdigit.c \
	  $(LIBFT_DIR)/ft_isprint.c \
	  $(LIBFT_DIR)/ft_itoa.c \
	  $(LIBFT_DIR)/ft_memchr.c \
	  $(LIBFT_DIR)/ft_memcmp.c \
	  $(LIBFT_DIR)/ft_memcpy.c \
	  $(LIBFT_DIR)/ft_memmove.c \
	  $(LIBFT_DIR)/ft_memset.c \
	  $(LIBFT_DIR)/ft_putchar_fd.c \
	  $(LIBFT_DIR)/ft_putendl_fd.c \
	  $(LIBFT_DIR)/ft_putnbr_fd.c \
	  $(LIBFT_DIR)/ft_putstr_fd.c \
	  $(LIBFT_DIR)/ft_split.c \
	  $(LIBFT_DIR)/ft_strchr.c \
	  $(LIBFT_DIR)/ft_strdup.c \
	  $(LIBFT_DIR)/ft_striteri.c \
	  $(LIBFT_DIR)/ft_strjoin.c \
	  $(LIBFT_DIR)/ft_strlcat.c \
	  $(LIBFT_DIR)/ft_strlcpy.c \
	  $(LIBFT_DIR)/ft_strlen.c \
	  $(LIBFT_DIR)/ft_strmapi.c \
	  $(LIBFT_DIR)/ft_strncmp.c \
	  $(LIBFT_DIR)/ft_strnstr.c \
	  $(LIBFT_DIR)/ft_strrchr.c \
	  $(LIBFT_DIR)/ft_strtrim.c \
	  $(LIBFT_DIR)/ft_substr.c

OBJ = $(SRC:.c=.o)
NAME = ft_printf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re