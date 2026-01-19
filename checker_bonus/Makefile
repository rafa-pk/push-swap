# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/19 18:49:19 by rvaz-da-          #+#    #+#              #
#    Updated: 2026/01/19 19:15:07 by rvaz-da-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = cc

FLAGS = -Wall -Wextra -Werror -g

SRC = main.c checker.c ../src/list_utils/lists.c ../src/parsing/parsing.c \
		../src/parsing/parsing_utils.c ../src/list_utils/movements.c \
		../src/list_utils/movement_combs.c ../src/algo/algo.c ../src/algo/algo_utils.c \
		../src/algo/small_sorts.c ../src/general_utils.c \

OBJ = $(SRC:.c=.o)

RM = rm -rf

bonus:  $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ../
	$(CC) $(FLAGS) $(OBJ) ../libft/libft.a -o $(NAME)

clean:
	$(MAKE) clean -C ../
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C ../
	rm -rf $(NAME)

re: fclean bonus

.PHONY: bonus clean fclean re
