# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amejia <amejia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 14:12:43 by amejia            #+#    #+#              #
#    Updated: 2023/03/16 19:41:09 by amejia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_DEBUG = push_swap_debug

NAME_CHECKER = checker

SRCS =  game_global_manip_game_structures2.c game_movements_push.c \
game_movements_swap.c main.c game_movements_reverse_rotate.c \
list_game_node_fcts.c movement_orchestrator.c \
sort.c game_global_manip_game_structures.c game_movements_rotate.c \
list_game_node_fcts2.c  statistics.c graceful_malloc_fail.c  \
new_quicksort.c game_global_manip_game_structures3.c efficient.c efficient2.c \
new_insertionsort.c  new_insertionsort2.c new_insertionsort3.c \
new_insertionsort4.c new_quicksort2.c 

BONUS_SRCS = game_global_manip_game_structures_bonus.c \
game_movements_rotate_bonus.c list_game_node_fcts_bonus.c \
game_movements_push_bonus.c game_movements_swap_bonus.c main_bonus.c \
game_movements_reverse_rotate_bonus.c list_game_node_fcts2_bonus.c \
movement_orchestrator_bonus.c game_global_manip_game_structures2_bonus.c \
checker_bonus.c graceful_malloc_fail_bonus.c statistics_bonus.c sort_bonus.c 

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}


CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

debug: CFLAGS += -D DEBUG=1 
debug: $(NAME_DEBUG) 

VS_debug: CFLAGS += -D DEBUG=1
VS_debug: $(NAME_DEBUG)

bonus:	$(NAME_CHECKER)


$(NAME_CHECKER): $(BONUS_OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(BONUS_OBJS) libft/libft.a -o $@

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $@

$(NAME_DEBUG): libft/libft.a $(SRCS)
	$(CC) $(CFLAGS) -fdiagnostics-color=always -g $(SRCS) libft/libft.a -o $@

libft/libft.a:
	make -C libft

clean: 
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME) $(NAME_DEBUG) $(NAME_CHECKER)
	make -C libft fclean

re: fclean all


.PHONY: all clean fclean re debug bonus
