# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 21:51:25 by rvaz-da-          #+#    #+#              #
#    Updated: 2025/11/25 23:40:26 by rvaz-da-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror -g

SRC = src/pushswap.c src/lists.c src/parsing.c src/parsing_utils.c src/movements.c \
		src/movement_combs.c src/algo.c\

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

