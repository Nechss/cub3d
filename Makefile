# Variables
NAME        = cub3D
CC          = gcc
CFLAGS      = -O3 -Wall -Wextra -Werror -fsanitize=address
INCLUDE     = -I./include -I./include/libft/include
RM          = rm -f

SRC_DIR     = src
OBJ_DIR     = obj

LIBFT       = ./include/libft/libft.a

MLX42_DIR = ./include/mlx
BUILD_DIR = $(MLX42_DIR)/build
MLX	= $(BUILD_DIR)/libmlx42.a

SRC         = cub3D.c       \
			init_game.c		\
			events.c        \
			events_move.c   \
			render_map.c    \
			render_scene.c  \
			cast_ray.c		\
			parsing.c		\
			parse_line.c	\
			parse_utils.c	\
			general_utils.c	\
			parse_line_map.c\
			build_map.c		\
			build_list.c	\
			init_structs.c	\
			vertical_parse.c\
			parse_player.c	\
			parse_tabs.c	\
			node_utils.c	\



OBJ         = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DEPS        = ./include Makefile ./include/cub3D.h ./include/libft/Makefile ./include/libft/include/libft.h 

all: makelibft $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@echo "Linking objects into $(NAME)..."
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBFT) $(MLX) -L$(MLX42_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm -o $(NAME)
	@echo "$(NAME) compiled successfully!"

$(MLX): $(BUILD_DIR)
	@echo "Building MLX42..."
	@cmake --build $(BUILD_DIR) -j4

$(BUILD_DIR):
	@echo "Configuring MLX42..."
	@cmake -B $(BUILD_DIR) -S $(MLX42_DIR)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) -c -o $@ $< $(CFLAGS) $(INCLUDE)

makelibft:
	@$(MAKE) -C ./include/libft

clean:
	@echo "Cleaning objects..."
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C ./include/libft clean
	@$(RM) -r $(BUILD_DIR)

fclean: clean
	@echo "Cleaning $(NAME) and libraries..."
	@$(RM) $(NAME)
	@$(MAKE) -C ./include/libft fclean

re: fclean all

.PHONY: all clean fclean re
