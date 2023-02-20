/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:52:27 by amejia            #+#    #+#             */
/*   Updated: 2023/02/19 21:45:24 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

void	get_over_here(t_sort_params *sortp, long value)
{
	long	original_v;

	original_v = get_node(sortp, 't', 0)->content;
	if (original_v == value)
		return ;
	move_to(sortp, 't', find_value(sortp, 't', value));
	movement(sortp, 't', "p");
	move_to(sortp, 't', find_value(sortp, 't', original_v));
	movement(sortp, 't', "u");
}

void	sort_insertionsort(t_sort_params *sortp)
{
	long	*sorted_list;
	int		counter;

	sorted_list = list_from_params(sortp);
	list_qsort(sorted_list, sortp->elements);
	move_to(sortp, 't', sortp->start);
	counter = 0;
	while (counter < sortp->elements)
	{
		if (sortp->ascending > 0)
			get_over_here(sortp, sorted_list[counter]);
		else
			get_over_here(sortp, \
				sorted_list[sortp->elements - counter - 1]);
		move_to(sortp, 't', 1);
		counter++;
	}
	if (sortp->ascending > 0)
		move_to(sortp, 't', find_value(sortp, 't', sorted_list[0]));
	else
		move_to(sortp, 't', find_value(sortp, 't', sorted_list[sortp->elements - 1]));
	free(sorted_list);
}

void	sort_insertionsort2(t_sort_params *sortp)
{
	long	*sorted_list;
	int		counter;

	sorted_list = list_from_params(sortp);
	list_qsort(sorted_list, sortp->elements);
	counter = 0;
	while (counter < sortp->elements)
	{
		if (sortp->ascending > 0)
			move_to(sortp, 't', find_value(sortp, 't', sorted_list[counter]));
		else
			move_to(sortp, 't', find_value(sortp, 't', sorted_list[sortp->elements - counter - 1]));
		if (counter != sortp->elements -1)
			movement(sortp, 't', "p");
		counter++;
	}
	counter--;
	while(counter-- > 0)
		movement(sortp, 't', "u");
	free(sorted_list);
}
