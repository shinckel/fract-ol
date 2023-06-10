# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 15:00:40 by shinckel          #+#    #+#              #
#    Updated: 2023/06/10 12:07:50 by shinckel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
CC := gcc
CFLAGS := -Wall -Wextra -Werror -Iheader -g
#CFLAGS += -fsanitize=address

SRC := $(wildcard src/*.c)
OBJ := $(SRC:.c=.o)
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
MINILIBX := minilibx-linux/libmlx_Linux.a -lm -lX11 -lXext

# Define colors
RED := \033[1;41m
YELLOW := \033[1;103m
RESET := \033[0m

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(YELLOW) Pipex compiled $(RESET)"

clean:
	find . -type f -name "*.txt" ! -name "grocery_list.txt" -exec rm -f {} +
	@echo "$(RED) Clean .txt files $(RESET)"
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)
	@echo "$(RED) Clean all $(RESET)"

re: fclean all

clean_libft:
	$(MAKE) -C $(LIBFT_DIR) fclean

.PHONY: all clean fclean re clean_libft

