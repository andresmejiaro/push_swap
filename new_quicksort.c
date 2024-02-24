/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_quicksort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:01:29 by amejia            #+#    #+#             */
/*   Updated: 2023/03/12 01:10:21 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push3_way_process_u(t_sort_params *sortp, long *values, \
		int *counts, int *counter)
{
	if (l_comparison(sortp, 't', values[1]))
	{
		movement(sortp, 't', "p");
		if (!l_comparison(sortp, 't', values[2]) && *counter > 0)
		{
			movement2(sortp, 'o', "r2");
			(*counter)--;
			counts[0]++;
		}
		else
			movement2(sortp, 'o', "r");
		counts[2]++;
	}
	else if (l_comparison(sortp, 't', values[2]))
	{
		movement(sortp, 't', "p");
		counts[1]++;
	}
	else if (get_node(sortp, 't', 1) != get_node(sortp, 't', 0))
	{
		movement2(sortp, 't', "r");
		counts[0]++;
	}
	return (1);
}

void	value_choose_3_way(long *values, t_sort_params *sortp)
{
	long	*list;

	list = list_from_params(sortp);
	list_qsort(list, sortp->elements);
	if (sortp->ascending == 1)
	{
		values[0] = list[0];
		values[1] = list[1 * sortp->elements / 3];
		values[2] = list[2 * sortp->elements / 3];
		values[3] = list[sortp->elements - 1];
	}
	if (sortp->ascending == -1)
	{
		values[3] = list[0];
		values[2] = list[1 * sortp->elements / 3];
		values[1] = list[2 * sortp->elements / 3];
		values[0] = list[sortp->elements - 1];
	}
	free(list);
}

void	sort_nquicksort_subsorts(t_sort_params *sortp, int *counts)
{
	t_sort_params	*sortp2;

	sortp2 = sort_params(sortp->cstack, ft_min(-counts[0], -1), -1, \
		sortp->ascending);
	sortp2->game = sortp->game;
	sort_nquicksort(sortp2);
	free(sortp2);
	sortp2 = sort_params(lane_swich(sortp->cstack), 0, ft_max(counts[1] - 1, \
	0), -sortp->ascending);
	sortp2->game = sortp->game;
	sort_nquicksort(sortp2);
	free(sortp2);
	while (sortp2->elements -- > 0)
		movement(sortp, 'o', "p");
	sortp2 = sort_params(lane_swich(sortp->cstack), -1, -counts[2], \
		-sortp->ascending);
	sortp2->game = sortp->game;
	sort_nquicksort(sortp2);
	while (sortp2->elements -- > 0)
		movement(sortp, 'o', "p");
	free(sortp2);
}

void	sort_nquicksort(t_sort_params *sortp)
{
	long			values[4];
	int				counts[3];

	if (sortp-> elements <= 3)
	{
		sort_smallchooser(sortp);
		return ;
	}
	if (sortp->elements <= 100 && sortp->skip != 1)
	{
		sort_ninsertionsort(sortp);
		return ;
	}
	sortp->skip = 0;
	ft_bzero(counts, 3 * sizeof(int));
	value_choose_3_way(values, sortp);
	push3_way(sortp, values, counts);
	sort_nquicksort_subsorts(sortp, counts);
	move_to(sortp, 't', find_value(sortp, 't', values[0]));
	return ;
}
