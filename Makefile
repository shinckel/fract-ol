# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 15:00:40 by shinckel          #+#    #+#              #
#    Updated: 2023/06/08 15:21:31 by shinckel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
CC := gcc
CFLAGS := -Wall -Wextra -Werror -Iheader -g -L./minilibx-linux -lmlx -lm -lX11 -lXext

