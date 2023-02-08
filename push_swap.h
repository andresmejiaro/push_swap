/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:54:00 by amejia            #+#    #+#             */
/*   Updated: 2023/02/08 14:49:15 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


typedef struct s_game
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_game;

int		read_and_validate_input(int argc, char **argv, t_list **data);
int		sort_data(t_list **data);
int		check_uniqueness(t_list *data);
int		check_valid(int argc, char **argv);
void	game_start(t_list *data);
void	sa(t_game *game);
void	print_game_state(t_game *game);
void	print_one(void *content);


#endif