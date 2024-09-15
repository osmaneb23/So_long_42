# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 18:30:45 by obouayed          #+#    #+#              #
#    Updated: 2024/09/15 14:18:39 by obouayed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = so_long

# Compilation 
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files and object files
SRC = main.c draw.c utils.c utils_bis.c window.c get_next_line.c get_next_line_utils.c map.c map_check.c map_parsing.c textures_init.c player_moves.c
SRC_DIR = src

OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

# Header file
HEADER = includes/so_long.h

# Commands
RM = rm -f

# Libraries
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
MLX_DIR = minilibx

# Compilation
all: $(NAME)
	
$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(SRC_DIR)/%.o:	$(SRC_DIR)/%.c
	$(CC) -c $< -o $@

# Cleaning
clean:
	cd $(SRC_DIR) && $(RM) *.o* 

fclean: clean
	$(RM) $(NAME)
	
# Re-compile everything
re: fclean all 

# To prevent commands from being treated as files
.PHONY: all clean fclean re 