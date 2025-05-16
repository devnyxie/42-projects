CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../libft
SRC = ft_printf.c \
	  helpers.c \
	  handlers.c \

OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

LIBFT = ../libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(LIBFT):
	$(MAKE) -C ../libft

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C ../libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) clean -C ../libft

re: fclean all

.PHONY: all clean fclean re