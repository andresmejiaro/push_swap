/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:54:00 by amejia            #+#    #+#             */
/*   Updated: 2023/02/12 11:26:43 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SEED_N 658457

typedef struct s_game_node
{
	int 				content;
	char 				*sort_id;
	struct s_game_node	*next;
}	t_game_node;

typedef struct s_game
{
	t_game_node	*stack_a;
	t_game_node	*stack_b;
}	t_game;

typedef struct s_sort_params
{
	int 	start;
	int 	end;
	int 	ascending;
	char 	cstack;
}	t_sort_params;



t_game_node	*ft_lstgn_new(int content);
void		ft_lstgn_add_back(t_game_node **lst, t_game_node *new);
void		ft_lstgn_iter(t_game_node *lst, void (*f)(int));
void		ft_lstgn_add_front(t_game_node **lst, t_game_node *new);
int 		ft_lstgn_value(t_game_node *node, int position);
int 		random_uint(unsigned int range);
int			read_and_validate_input(int argc, char **argv, t_game_node **data);
int			check_uniqueness(t_game_node *data);
int			check_valid(int argc, char **argv);
void		game_start(t_game_node *data);
void		sa(t_game *game);
void		print_game_state(t_game *game);
void		print_one(int content);
void		pb(t_game *game);
void		rotate(t_game_node **first);
void		ra(t_game *game);
void		rb(t_game *game);
void		rra(t_game *game);
void		rrb(t_game *game);
void		ft_qsort(t_game *game, t_sort_params *sortp);
void 		movement_orchestrator(t_game *game,char *mv);
void		movement_translator(t_game *game, t_game_node *stack, char *mv);
void		find_value(t_game *game, t_game_node *stack, int value);
void		find_position(t_game *game, t_game_node *stack, int position);
char 		*sort_chooser(t_game *game, t_sort_params *sortp);
void 		sort(t_game *game, t_sort_params *sortp);
t_game_node *stack_from_char(t_game *game, char c);
t_sort_params *sort_params(char cstack, int start, int end, int ascending);
char lane_swich(char c);
void	qsort_push(t_game *game, t_sort_params *sortp, int pivot, int *npushed);

#endif