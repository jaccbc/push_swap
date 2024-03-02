# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joandre- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 21:42:53 by joandre-          #+#    #+#              #
#    Updated: 2024/03/01 21:52:00 by joandre-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT = Libft/libft.a
SRC = stack_utils.c number_utils.c cmd_push.c cmd_reverse.c cmd_rotate.c cmd_swap.c \
	  argv_check.c push_swap.c
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
