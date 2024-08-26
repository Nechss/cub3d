# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 16:29:45 by gperez-b          #+#    #+#              #
#    Updated: 2024/01/25 18:40:19 by gperez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDE		= -I./include
RM			= rm -f

SRC_DIR		= src
OBJ_DIR		= obj

SRC			= ft_atoi.c \
			ft_atoidb.c \
			ft_long_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isdigit_plusminus.c \
			ft_isdigit_plusminusdot.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_sort_int.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstlast.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_printf.c \
			ft_putchar_ct.c \
			ft_puthex_ct.c \
			ft_putnbr_ct.c \
			ft_putuns_ct.c \
			ft_putptr_ct.c \
			ft_putstr_ct.c \
			ft_convert_printf.c \
			get_next_line.c 
			


OBJ         = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DEPS        = Makefile ./include/libft.h

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking objects into $(NAME)..."
	@ar -rc $@ $^
	@echo "$(NAME) compiled successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) -c -o $@ $< $(CFLAGS) $(INCLUDE)

clean:
	@echo "Cleaning objects..."
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "Cleaning $(NAME) ..."
	@$(RM) $(NAME)

re: fclean all
