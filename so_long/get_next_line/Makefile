NAME = get_next_line.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../libft
BUFFER_SIZE ?= 8

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

LIBFT = ../libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C ../libft

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ../libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ../libft

re: fclean all

.PHONY: all clean fclean re
