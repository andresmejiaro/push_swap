/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movements_swap_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:43:35 by amejia            #+#    #+#             */
/*   Updated: 2023/03/11 23:15:39 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_game_node	*swap(t_game_node *first)
{
	t_game_node	*second;

	if (first == 0)
		return (first);
	second = first->next;
	if (second == 0)
		return (first);
	first ->next = second -> next;
	second->next = first;
	return (second);
}

void	sa(t_game *game)
{
	game->stack_a = swap(game ->stack_a);
}

void	sb(t_game *game)
{
	game->stack_b = swap(game ->stack_b);
}

void	ss(t_game *game)
{
	sa(game);
	sb(game);
	return ;
}
