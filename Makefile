# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 15:00:40 by shinckel          #+#    #+#              #
#    Updated: 2023/06/10 17:54:10 by shinckel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
CC := gcc
CFLAGS := -Wall -Wextra -Werror -Iheader -g
CFLAGS += -I/opt/X11/include
#CFLAGS += -fsanitize=address

MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -L/usr/X11/lib -L/opt/X11/lib
# to confirm... do I need this flag?
MLXFLAGS += -L/opt/X11/lib

SRC := $(wildcard src/*.c)
OBJ := $(SRC:.c=.o)
LIBFT_DIR := ./libft
MINILIBX_DIR := ./minilibx-linux
LIBFT := $(LIBFT_DIR)/libft.a
MINILIBX := $(MINILIBX_DIR)/libmlx_Linux.a

# Define colors
RED := \033[1;41m
YELLOW := \033[1;103m
GREEN := \033[1;42m
RESET := \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MINILIBX_DIR)
	@echo "$(YELLOW) MiniLibX compiled $(RESET)"
	@$(CC) $(CFLAGS) -lm $(SRC) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN) Ready to FRACT-OL $(RESET)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED) Clean .o files $(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED) Clean all $(RESET)"

re: fclean all

clean_libft:
	@$(MAKE) -C $(LIBFT_DIR) fclean

.PHONY: all clean fclean re clean_libft
