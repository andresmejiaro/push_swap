/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_game_node_fcts2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 03:16:05 by amejia            #+#    #+#             */
/*   Updated: 2023/02/14 14:37:37 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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
