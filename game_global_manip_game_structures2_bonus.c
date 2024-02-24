/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_global_manip_game_structures2_bonus.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:14:48 by amejia            #+#    #+#             */
/*   Updated: 2023/03/11 23:23:43 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	fill_order(t_sort_params *sortp)
{
	long	*elementlist;
	int		counter;
	int		counter2;

	elementlist = list_from_params(sortp);
	graceful_malloc_fail(elementlist);
	list_qsort(elementlist, sortp->elements);
	counter = 0;
	while (counter < sortp->elements)
	{
		counter2 = 0;
		while (counter2 < sortp -> elements)
		{
			if (get_node(sortp, 't', counter)->content \
				== elementlist[counter2])
			{
				get_node(sortp, 't', counter)->\
					ordered_position = counter2 + 1;
				break ;
			}
			counter2++;
		}		
		counter++;
	}	
	free(elementlist);
}

char	lane_swich(char c)
{
	if (c == 'a')
		return ('b');
	if (c == 'b')
		return ('a');
	if (c == 't')
		return ('o');
	if (c == 'o')
		return ('t');
	return ('\0');
}

void	move_to(t_sort_params *sortp, char this, int position)
{
	t_game_node	*node[2];
	int			counter[2];

	counter[0] = 0;
	counter[1] = 0;
	node[0] = get_node(sortp, this, 0);
	if (node[0] == 0)
		return ;
	node[1] = get_node(sortp, this, position);
	while (node[0] != node[1])
	{
		counter[0]++;
		node[0] = node[0]->next;
	}
	while (node[0] != 0)
	{
		counter[1]++;
		node[0] = node[0]->next;
	}
	if (counter[0] < counter[1])
		while (counter[0]-- > 0)
			movement(sortp, this, "r");
	else
		while (counter[1]-- > 0)
			movement(sortp, this, "rr");
}

// This functions mallocs the result;
long	*list_from_paramso(t_sort_params *sortp)
{
	int		counter;
	long	*to_return;

	counter = 0;
	to_return = (long *)ft_calloc(sortp->elements, sizeof(long));
	while (counter < sortp->elements)
	{
		to_return[counter] = get_node(sortp, 't', \
			sortp->start + counter)->ordered_position;
		counter++;
	}
	return (to_return);
}

int	find_value(t_sort_params *sortp, char this, long value)
{
	t_game_node	*node;
	int			counter;

	node = get_node(sortp, this, 0);
	counter = 0;
	while (node != 0)
	{
		if (node->content == value)
			return (counter);
		node = node->next;
		counter++;
	}
	return (-1);
}
