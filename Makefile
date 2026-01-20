# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 21:51:25 by rvaz-da-          #+#    #+#              #
#    Updated: 2026/01/19 18:48:56 by rvaz-da-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror -g

SRC = src/pushswap.c src/list_utils/lists.c src/parsing/parsing.c \
		src/parsing/parsing_utils.c src/list_utils/movements.c \
		src/list_utils/movement_combs.c src/algo/algo.c src/algo/algo_utils.c \
		src/algo/small_sorts.c src/general_utils.c\

OBJ = $(SRC:.c=.o)

RM = rm -rf

all:  $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

