/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movements_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:50:43 by amejia            #+#    #+#             */
/*   Updated: 2023/02/12 16:07:11 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	pb(t_game *game)
{
	t_game_node	*first;

	first = game->stack_a;
	game -> stack_a = game->stack_a->next;
	ft_lstgn_add_front(&(game->stack_b), first);
}

void	pa(t_game *game)
{
	t_game_node	*first;

	first = game->stack_b;
	game -> stack_b = game->stack_b->next;
	ft_lstgn_add_front(&(game->stack_a), first);
}
