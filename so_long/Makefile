NAME = so_long

SRCS = so_long.c utils.c ./map_utils/map.c ./map_utils/map_check_counts.c ./map_utils/map_check_reach.c ./map_utils/map_utils.c movement.c mlx_utils.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I -Imlx -I$(GNL_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

GNL_DIR = get_next_line
GNL = $(GNL_DIR)/get_next_line.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a

all: $(GNL) $(LIBFT) $(FT_PRINTF_DIR) $(MLX) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -O3 -c $< -o $@

$(NAME): $(OBJS) $(GNL) $(LIBFT) $(FT_PRINTF) $(MLX)
	$(CC) $(OBJS) $(GNL) $(LIBFT) $(FT_PRINTF) $(MLX) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

$(GNL):
	$(MAKE) -C $(GNL_DIR) BUFFER_SIZE=32

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(GNL_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(GNL_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	$(MAKE) clean -C $(MLX_DIR)

re: fclean all
