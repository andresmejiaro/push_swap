/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_quicksort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:01:29 by amejia            #+#    #+#             */
/*   Updated: 2023/02/25 01:17:13 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

int	push3_way_process_u(t_sort_params *sortp, long *values, int *counts, int *counter)
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


int	push3_way_process_d(t_sort_params *sortp, long *values, int *counts)
{
	if (l_comparison(sortp, 't', values[1]))
	{
		movement(sortp, 't', "p");
		movement2(sortp, 't', "rr");
		movement2(sortp, 'o', "r");
		counts[2]++;
	}
	else if (l_comparison(sortp, 't', values[2]))
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



int	push3_way_method_chooser(t_sort_params *sortp)
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



//divides  in three ways the "highest stays in this lane, the second highest 
//to the positive part of the other stack and the lowest to the negative part"
// of the other stack stays in the limit between the two in the "left lane of 
//the highest"  other head in the right border of the lowest.
void	push3_way(t_sort_params *sortp, long *values, int *counts)
{
	int		counter;

	counter = sortp->elements;

	if (push3_way_method_chooser(sortp))
	{	
		move_to(sortp, 't', sortp->end);
		while (counter-- > 0)
			if (push3_way_process_d(sortp, values, counts) == 0)
				break ;
	}
	else
	{
		move_to(sortp, 't',sortp->start);
		while (counter-- > 0)
			if (push3_way_process_u(sortp, values, counts, &counter) == 0)
				break ;	
	}
}


void sort_nquicksort_subsorts(t_sort_params *sortp, int *counts)
{
	t_sort_params	*sortp2;
	
	sortp2 = sort_params(sortp->cstack, ft_min(-counts[0], -1), -1, sortp->ascending);
	sortp2->game = sortp->game;
	sort_nquicksort(sortp2);
	sortp2 = sort_params(lane_swich(sortp->cstack), 0, ft_max(counts[1] - 1, 0), -sortp->ascending);
	sortp2->game = sortp->game;
	sort_nquicksort(sortp2);
	while (sortp2->elements -- > 0)
		movement(sortp, 'o', "p");
	sortp2 = sort_params(lane_swich(sortp->cstack), -1, -counts[2], -sortp->ascending);
	sortp2->game = sortp->game;
	sort_nquicksort(sortp2);
	while (sortp2->elements -- > 0)
		movement(sortp, 'o', "p");
	free(sortp2);
}

void sort_nquicksort(t_sort_params *sortp)
{
	long			values[4];
	int				counts[3];

	if (sortp->elements <= 40)
	{
		sort_ninsertionsort(sortp);
		return ;
	}
	ft_bzero(counts, 3 * sizeof(int));
	value_choose_3_way(values, sortp);
	push3_way(sortp, values, counts);
	sort_nquicksort_subsorts(sortp, counts);
	move_to(sortp,'t',find_value(sortp,'t',values[0]));
	return ;
}


