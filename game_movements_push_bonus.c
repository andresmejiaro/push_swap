/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movements_push copy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:50:43 by amejia            #+#    #+#             */
/*   Updated: 2023/03/11 23:13:52 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap_bonus.h"

void	pb(t_game *game)
{
	t_game_node	*first;

	if (ft_lstgn_size(game ->stack_a) == 0)
		return ;
	first = game->stack_a;
	game -> stack_a = game->stack_a->next;
	ft_lstgn_add_front(&(game->stack_b), first);
}

void	pa(t_game *game)
{
	t_game_node	*first;

	if (ft_lstgn_size(game ->stack_b) == 0)
		return ;
	first = game->stack_b;
	game -> stack_b = game->stack_b->next;
	ft_lstgn_add_front(&(game->stack_a), first);
}
