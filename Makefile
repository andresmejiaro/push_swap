# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amejia <amejia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 14:12:43 by amejia            #+#    #+#              #
#    Updated: 2023/02/24 04:33:47 by amejia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_DEBUG = push_swap_debug
NAME_DEB = push_swap_deb
NAME_PLAY = push_swap_play

SRCS =  game_global_manip_game_structures2.c game_movements_push.c \
game_movements_swap.c main.c game_movements_reverse_rotate.c \
list_game_node_fcts.c movement_orchestrator.c \
sort.c game_global_manip_game_structures.c game_movements_rotate.c \
list_game_node_fcts2.c  statistics.c radix.c cyclesort.c cyclesort2.c \
radix2.c graceful_malloc_fail.c  quicksort.c quicksort2.c insertionsort.c \
new_quicksort.c game_global_manip_game_structures3.c efficient.c efficient2.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

debug: CFLAGS += -D DEBUG=1 
debug: $(NAME_DEB) 

play: CFLAGS += -D PLAY=1 
play: $(NAME_PLAY) 

VS_debug: CFLAGS += -D DEBUG=1
VS_debug: $(NAME_DEBUG)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $@

$(NAME_DEBUG): libft/libft.a $(SRCS)
	$(CC) $(CFLAGS) -fdiagnostics-color=always -g $(SRCS) libft/libft.a -o $@

$(NAME_DEB): libft/libft.a $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $@

$(NAME_PLAY): libft/libft.a $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $@

libft/libft.a:
	make -C libft

clean: 
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME) $(NAME_DEBUG)
	make -C libft fclean

re: fclean all


.PHONY: all clean fclean re debug play
