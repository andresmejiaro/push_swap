/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:54:00 by amejia            #+#    #+#             */
/*   Updated: 2023/02/08 17:27:30 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_game_node
{
	int 				content;
	struct s_game_node	*next;
}	t_game_node;

typedef struct s_game
{
	t_game_node	*stack_a;
	t_game_node	*stack_b;
}	t_game;





t_game_node	*ft_lstgn_new(int content);
void		ft_lstgn_add_back(t_game_node **lst, t_game_node *new);
void	ft_lstgn_iter(t_game_node *lst, void (*f)(int));
void	ft_lstgn_add_front(t_game_node **lst, t_game_node *new);


int		read_and_validate_input(int argc, char **argv, t_game_node **data);
int		check_uniqueness(t_game_node *data);
int		check_valid(int argc, char **argv);
void	game_start(t_game_node *data);
void	sa(t_game *game);
void	print_game_state(t_game *game);
void	print_one(int content);
void	pb(t_game *game);


#endif