/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_quicksorta.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:01:29 by amejia            #+#    #+#             */
/*   Updated: 2023/02/25 12:07:18 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	value_choose_2_way(long *values, t_sort_params *sortp)
{
	long	*list;

	list = list_from_params(sortp);
	list_qsort(list, sortp->elements);
	if (sortp->ascending == 1)
	{
		values[0] = list[0];
		values[1] = list[1 * sortp->elements / 2];
		values[2] = list[sortp->elements - 1];
	}
	if (sortp->ascending == -1)
	{
		values[2] = list[0];
		values[1] = list[1 * sortp->elements / 2];
		values[0] = list[sortp->elements - 1];
	}
	free(list);
}

int	push2_way_process_u(t_sort_params *sortp, long *values, int *counts)
{
	if (l_comparison(sortp, 't', values[1]))
	{
		movement(sortp, 't', "p");
		counts[1]++;
	}
	else if (get_node(sortp, 't', 1) == get_node(sortp, 't', 0))
		return (0);
	else
	{
		movement2(sortp, 't', "r");
		counts[0]++;
	}
	return (1);
}


int	push2_way_process_d(t_sort_params *sortp, long *values, int *counts)
{
	if (l_comparison(sortp, 't', values[1]))
	{
		movement(sortp, 't', "p");
		movement2(sortp, 't', "rr");
		counts[1]++;
	}
	else if (get_node(sortp, 't', 1) == get_node(sortp, 't', 0))
		return (0);
	else
	{
		movement2(sortp, 't', "rr");
		counts[0]++;
	}
	return (1);
}



int	push2_way_method_chooser(t_sort_params *sortp)
{
	int		start_end[3];
	
	start_end[0] = sortp->start;
	start_end[1] = sortp->end;
	start_end[2] = ft_lstgn_size(get_node(sortp,'t',0));
	while (start_end[0] < 0)
		start_end[0] += start_end[2];
	while (start_end[0] > start_end[2])
		start_end[0] -= start_end[2];
	while (start_end[1] < 0)
		start_end[1] += start_end[2];
	while (start_end[1] > start_end[2])
		start_end[1] -= start_end[2];
	start_end[0] = ft_min(start_end[0],start_end[2]-start_end[0]);
	start_end[1] = ft_min(start_end[1],start_end[2]-start_end[1]);
	if (start_end[1] + sortp->elements < start_end[0])
		return (1);
	return (0);
}



void	push2_way(t_sort_params *sortp, long *values, int *counts)
{
	int		counter;

	counter = sortp->elements;

	if (push2_way_method_chooser(sortp))
	{	
		move_to(sortp,'t',sortp->end);
		while (counter-- > 0)
			if (push2_way_process_d(sortp, values, counts) == 0)
				break ;	
	}
	else
	{
		move_to(sortp,'t',sortp->start);
		while (counter-- > 0)
			if (push2_way_process_u(sortp, values, counts) == 0)
				break ;	
	}
}


void sort_nquicksorta(t_sort_params *sortp)
{
	long			values[4];
	t_sort_params	*sortp2;
	int				counts[3];


	if (sortp->elements <= 27)
	{
		sort_ninsertionsort(sortp);
		return ;
	}
	ft_bzero(counts, 3 * sizeof(int));
	value_choose_2_way(values, sortp);
	push2_way(sortp, values, counts);
	sortp2 = sort_params(sortp->cstack, ft_min(-counts[0], -1), -1, sortp->ascending);
	sortp2->game = sortp->game;
	sort_nquicksorta(sortp2);
	sortp2 = sort_params(lane_swich(sortp->cstack), 0, ft_max(counts[1] - 1, 0), -sortp->ascending);
	sortp2->game = sortp->game;
	sort_nquicksorta(sortp2);
	while (sortp2->elements -- > 0)
	{
		movement(sortp, 'o', "p");
	}
	while (sortp2->elements -- > 0)
	{
		movement(sortp, 'o', "p");
	}
	free(sortp2);
	move_to(sortp,'t',find_value(sortp,'t',values[0]));
}


void sort_nquicksorta_100(t_sort_params *sortp)
{
	long			values[4];
	t_sort_params	*sortp2;
	int				counts[3];

	ft_bzero(counts, 3 * sizeof(int));
	value_choose_2_way(values, sortp);
	push2_way(sortp, values, counts);
	sortp2 = sort_params(sortp->cstack, ft_min(-counts[0], -1), -1, sortp->ascending);
	sortp2->game = sortp->game;
	sort_ninsertionsort(sortp2);
	sortp2 = sort_params(lane_swich(sortp->cstack), 0, ft_max(counts[1] - 1, 0), sortp->ascending);
	sortp2->game = sortp->game;
	sort_ninsertionsort_otherside(sortp2);
	free(sortp2);
	move_to(sortp,'t',find_value(sortp,'t',values[0]));
}