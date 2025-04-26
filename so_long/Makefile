NAME = so_long

SRCS = so_long.c utils.c map.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I -Imlx -I$(GNL_DIR) -I$(LIBFT_DIR)

GNL_DIR = get_next_line
GNL = $(GNL_DIR)/get_next_line.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a

all: $(GNL) $(LIBFT) $(MLX) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -O3 -c $< -o $@

$(NAME): $(OBJS) $(GNL) $(LIBFT) $(MLX)
	$(CC) $(OBJS) $(GNL) $(LIBFT) $(MLX) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

$(GNL):
	$(MAKE) -C $(GNL_DIR) BUFFER_SIZE=32

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(GNL_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(GNL_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
