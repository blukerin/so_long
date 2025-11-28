NAME = so_long

SRCS = ./src/main.c ./src/keys.c ./src/alloc_map.c ./src/checker_map.c\
./src/checker_map_utils.c ./src/init_game.c ./src/movements.c

BONUS_SRC = ./src_bonus/main_bonus.c ./src_bonus/keys_bonus.c ./src_bonus/alloc_map_bonus.c ./src_bonus/checker_map_bonus.c\
./src_bonus/checker_map_utils_bonus.c ./src_bonus/init_game_bonus.c ./src_bonus/movements_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

MLX_DIR = mlx
LIBFT_DIR = libft
INCLUDES = -I. -I$(MLX_DIR) -I$(LIBFT_DIR)

CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

bonus: $(BONUS_OBJS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean fclean re bonus
