# Variables
NAME        = cub3D
CC          = gcc
CFLAGS      = -O3 -Wall -Wextra -fsanitize=address #-Werror
INCLUDE     = -I./include -I./include/libft/include
RM          = rm -f

SRC_DIR     = src
OBJ_DIR     = obj

LIBFT       = ./include/libft/libft.a

MLX42_DIR = ./include/mlx
BUILD_DIR = $(MLX42_DIR)/build
MLX      = $(BUILD_DIR)/libmlx42.a

SRC         = cub3D.c         \
			events.c        \
			events_move.c   \
			render_map.c    \
			render_scene.c  \
			parsing.c		\
			parse_line.c	\
			parse_utils.c	\
			general_utils.c	\
			parse_line_map.c\


OBJ         = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DEPS        = ./include Makefile ./include/cub3D.h ./include/libft/Makefile ./include/libft/include/libft.h

all: $(NAME)

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

$(LIBFT):
	@$(MAKE) -C ./include/libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) -c -o $@ $< $(CFLAGS) $(INCLUDE)

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
