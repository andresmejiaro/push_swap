/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_game_node_fcts2_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 03:16:05 by amejia            #+#    #+#             */
/*   Updated: 2023/03/11 23:16:38 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

//returns nnodes from the actual node, zero after the last one
t_game_node	*ft_lstgn_nnode(t_game_node *node, int position)
{
	while (node != 0 && position > 0)
	{
		node = node-> next;
		position--;
	}
	return (node);
}

int	ft_lstgn_size(t_game_node *node)
{
	int	counter;

	if (node == NULL)
		return (0);
	counter = 1;
	while (node->next != NULL)
	{
		if (node->next != NULL)
			node = node-> next;
		counter++;
	}
	return (counter);
}

void	ft_lstgn_clear(t_game_node *node)
{
	t_game_node	*next;

	while (node != 0)
	{
		next = node->next;
		free(node);
		node = next;
	}
}
