/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_game_node_fcts2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 03:16:05 by amejia            #+#    #+#             */
/*   Updated: 2023/02/18 00:38:10 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

int	ft_lstgn_value(t_game_node *node, int position)
{
	int	tmp;

	while (node->next != 0 && position > 0)
	{
		node = node-> next;
		position--;
	}
	if (position != 0)
		return (0);
	tmp = node->content;
	return (tmp);
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
