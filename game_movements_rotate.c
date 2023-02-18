/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movements_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:12:51 by amejia            #+#    #+#             */
/*   Updated: 2023/02/17 22:51:18 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_game_node **first)
{
	t_game_node	*last;
	t_game_node	*second;

	if (*first == 0)
		return ;
	if ((*first)->next == 0)
		return ;
	second = (*first)->next;
	last = *first;
	while (last->next != 0)
	{
		last = last -> next;
	}
	last->next = (*first);
	last->next->next = 0;
	*first = second;
	return ;
}

void	ra(t_game *game)
{
	rotate(&(game->stack_a));
}

void	rb(t_game *game)
{
	rotate(&(game->stack_b));
}

void	rr(t_game *game)
{
	ra(game);
	rb(game);
}
