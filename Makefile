# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joandre- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 21:42:53 by joandre-          #+#    #+#              #
#    Updated: 2024/03/20 04:32:59 by joandre-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.SILENT:
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT = Libft/libft.a
SRC = cmd_push.c cmd_reverse.c cmd_rotate.c cmd_swap.c \
	  argv_check.c stack_utils.c numb_utils.c index_utils.c sort_utils.c \
	  sort_control.c sort_algo.c push_swap.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L Libft -lft
$(LIBFT):
		make -s -C ./Libft
		make clean -s -C ./Libft

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)
		make fclean -s -C ./Libft

re: fclean all
