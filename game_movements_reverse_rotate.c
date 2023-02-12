/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movements_reverse_rotate.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:07:51 by amejia            #+#    #+#             */
/*   Updated: 2023/02/12 16:08:07 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_game_node **first)
{
	t_game_node	*separate;
	t_game_node	*before_last;

	if (*first == 0)
		return ;
	if ((*first)->next == 0)
		return ;
	separate = *first;
	while (separate->next != 0)
	{
		before_last = separate;
		separate = separate->next;
	}
	before_last->next = 0;
	ft_lstgn_add_front(first, separate);
	return ;
}

void	rra(t_game *game)
{
	reverse_rotate(&(game->stack_a));
}

void	rrb(t_game *game)
{
	reverse_rotate(&(game->stack_b));
}

void	rrr(t_game *game)
{
	rra(game);
	rrb(game);
}
