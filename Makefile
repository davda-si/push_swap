# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 13:52:10 by davda-si          #+#    #+#              #
#    Updated: 2023/11/15 14:10:26 by davda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

MOVES = moves/

SRC = main.c errors.c initstack_a.c sort_it.c stacks.c sort_utils_a.c \
sort_utils_b.c $(MOVES)rotate.c $(MOVES)rrotate.c $(MOVES)push.c $(MOVES)swap.c

CC = @cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT_PATH = ./libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_PATH)

clean:
	@rm -f $(OBJS)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:         all clean fclean re