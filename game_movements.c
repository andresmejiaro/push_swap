/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:43:35 by amejia            #+#    #+#             */
/*   Updated: 2023/02/08 15:58:19 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sa(t_game *game)
{
	t_list	*second;
	t_list	*first;

	first = (game)->stack_a;
	if (first == 0)
		return ;
	second = first->next;
	if (second == 0)
		return ;
	(game)->stack_a =second ;
	first ->next = second -> next;
	second->next = first;
	return ;
}

void	sb(t_game *game)
{
	t_list	*second;
	t_list	*first;

	first = (game)->stack_b;
	if (first == 0)
		return ;
	second = first->next;
	if (second == 0)
		return ;
	(game)->stack_b =second ;
	first ->next = second -> next;
	second->next = first;
	return ;
}

void	ss(t_game *game)
{
	sa(game);
	sb(game);
    return ;
}

void pb(t_game *game)
{
    t_list *first;
    

    first = game->stack_a;

    game -> stack_a = game->stack_a->next;
    ft_lstadd_front(&(game->stack_b),first);
    game->stack_b = first;
}