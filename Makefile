# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amejia <amejia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 14:12:43 by amejia            #+#    #+#              #
#    Updated: 2023/02/14 17:17:26 by amejia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_DEBUG = push_swap_debug

SRCS = game_global_manip.c game_movements_push.c game_movements_rotate.c \
list_game_node_fcts.c main.c quicksort.c seasons.c game_global_manip2.c \
game_movements_reverse_rotate.c game_movements_swap.c list_game_node_fcts2.c \
movement_orchestrator.c statistics.c sort.c seasonssort.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

debug: CFLAGS += -D DEBUG=1 
debug: $(NAME) 

VS_debug: CFLAGS += -D DEBUG=1
VS_debug: $(NAME_DEBUG)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $@

$(NAME_DEBUG): libft/libft.a $(SRCS)
	$(CC) $(CFLAGS) -fdiagnostics-color=always -g $(SRCS) libft/libft.a -o $@

libft/libft.a:
	make -C libft

clean: 
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME) $(NAME_DEBUG)
	make -C libft fclean

re: fclean all
	make  -C libft re

.PHONY: all clean fclean re debug
