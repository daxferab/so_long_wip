NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

LIBFT = lib/libft/libft.a
LIBMLX = lib/mlx
MLX = $(LIBMLX)/build/libmlx42.a
MLXFLAGS = -L $(LIBMLX)/build -l mlx42 -l glfw -l dl -l m -pthread

SRC_FILES = src/hook.c\
			src/initialize/draw_map.c\
			src/initialize/draw_tools.c\
			src/initialize/init_map.c\
			src/parse/arg_validation.c\
			src/parse/map_utils.c\
			src/parse/map_utils2.c\
			src/parse/map_validation.c\
			src/errors.c\
			src/free_map.c\
			src/main.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(MLXFLAGS) -o $(NAME) $(LIBFT) $(MLX)

$(LIBFT):
	make -C lib/libft

$(MLX):
	cmake $(LIBMLX) -B $(LIBMLX)/build
	make -C $(LIBMLX)/build -j4

clean:
	make -C lib/libft clean
	rm -f $(OBJ_FILES)

fclean:
	make -C lib/libft fclean
	rm -rf $(NAME) $(OBJ_FILES) $(LIBMLX)/build

re: fclean all

run: all
	./$(NAME) maptry.ber

.PHONY: all clean fclean re
