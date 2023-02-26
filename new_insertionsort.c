/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_insertionsort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:37:42 by amejia            #+#    #+#             */
/*   Updated: 2023/02/26 20:43:57 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_ninsertionsort_upstairs_separator(t_sort_params *sortp, \
	int *counter, int *position, long *list)
{
	if (sortp->ascending * get_nodec(sortp, 't', -1) < \
		sortp->ascending * 	get_nodec(sortp, 't', 1) && \
		!l_comparison(sortp, 't', get_nodec(sortp, 't', 1)))
	{
		movement(sortp, 't', "s");
		move_to(sortp, 't', 1);
	}
	else if (l_comparison(sortp, 'o', list[sortp->elements / 2]) \
		&& position[3] - position[1] > 0 * counter[0])
	{
		movement(sortp, 't', "r2");
		position[1]++;
	}
	else
		movement(sortp, 't', "r");
	position[2]++;
}

void	sort_ninsertionsort_upstairs_manuvers(t_sort_params *sortp, int *position)
{
		movement(sortp, 't', "rr");
		movement(sortp, 't', "s");
		move_to(sortp, 't', 2);
		position[2]++;
}


void	sort_ninsertionsort_fill_upstairs(t_sort_params *sortp, int *counter, \
	int *position, long *list)
{
	if (!l_comparison(sortp, 't',get_nodec(sortp, 't', -1)) && counter[5] == 1)
		sort_ninsertionsort_upstairs_separator(sortp, counter, position, \
		list);
	else if (l_comparison(sortp, 'o', list[sortp->elements / 2]) \
		&& ft_lstgn_size(get_node(sortp, 'o', 0)) > 1 && \
		position[3] - position[1] > 0)
	{
		movement2(sortp, 'o', "r");
		counter[1]--;
		position[1]++;
	}
	else if ((position[2] == 1 || \
		!l_comparison(sortp, 't', get_nodec(sortp, 't', -2))) \
		&& counter[5] == 1)
		sort_ninsertionsort_upstairs_manuvers(sortp, position);
	else
	{
		movement(sortp, 't', "p");
		position[3]++;
	}
	counter[1]++;
}

void	sort_ninsertionsort_unravel(t_sort_params *sortp, int *counter, \
	int *position)
{
	while (sortp->ascending * get_nodec(sortp, 't', -1) > \
		sortp->ascending * get_nodec(sortp, 'o', -1) &&
		position[1] > 0 && position[0] > 0 * counter[0])
	{
		position[1]--;
		position[0]--;
		movement(sortp, 't', "rr2");
	}
	if (position[1] + position[2] == sortp->elements && position[1] != 0)
	{
		position[1]--;
		movement2(sortp,'o',"rr");
	}
}

void	sort_ninsertionsort_bring_it_down(t_sort_params *sortp, int *counter, \
	int *position)
{
	while (position[2] < sortp->elements)
	{
		if (position[1] + position[2] == sortp->elements && position[1] != 0)
			sort_ninsertionsort_unravel(sortp, counter, position);
		while (l_comparison(sortp, 'o', get_nodec(sortp, 't', -1)) \
			&& position[0] > 0)
		{
			movement(sortp, 't', "rr");
			position[0]--;
		}
		while (!l_comparison(sortp, 'o', get_nodec(sortp, 't', 0)) \
		&& position[0] < position[2])
		{
			movement(sortp, 't', "r");
			position[0]++;
		}
		movement(sortp, 't', "u");
		position[2]++;
	}
	move_to(sortp, 't', -position[0]);
	position[0] = 0;
}

void longest_run(t_sort_params *sortp, int *counter)
{
	int	ct[3];

	ft_bzero(ct,3 * sizeof(int));
	if (get_node(sortp,'t',0)==get_node(sortp,'t',sortp->elements))
		ct[2] = 2;
	else
		ct[2] = 1;
	while (ct[0] < ct[2] * sortp->elements )
	{
		ct[1] = ct[0] + 1;
		while (sortp->ascending * get_nodec(sortp,'t',sortp->start + ct[1] - 1) < \
		sortp->ascending * get_nodec(sortp,'t',sortp->start + ct[1]) &&
		ct[1] < ct[2] * sortp->elements)
			ct[1]++;
		if (ct[1] - ct[0] > counter[4] - counter[3])
		{
			counter[4] = ct[1];
			counter[3] = ct[0];
		}
		ct[0]++;
	}
	counter[4] = counter[4] - counter[3];
}

void sort_ninsertionsort_start_strategy(t_sort_params *sortp, int *counter, \
	int *position, long *list)
{
	list_qsort(list, sortp->elements);
	ft_bzero(counter, 6 * sizeof(int));
	ft_bzero(position, 4 * sizeof(int));
	longest_run(sortp,counter);
	move_to(sortp,'t',sortp->start);
	if (counter[3] <  3 * counter[4])
	{
		while (counter[1] < counter[3])
			sort_ninsertionsort_fill_upstairs(sortp, counter, position, list);
		move_to(sortp, 't', counter[4]);
		position[2] = counter[4];
		counter[1] += counter[4];
	}
	counter[5]++;
}


// from i stack "stack",  push to "other" stack
void push_places(t_sort_params *sortp, char this, int from, int to)
{
	int	t;

	if (from * to <= 0)
	{
		move_to(sortp, this, from);
		move_to(sortp, lane_swich(this), to);
		movement(sortp, this, "p");
		return ;
	}
	t = ft_min(ft_abs(from),ft_abs(to)) * to / ft_abs(to);
	while (t > 0)
	{			
		movement(sortp, 't', "r2");
		t--;
	}
	while (t ++ < 0)			
		movement(sortp, this, "rr2");
	t = ft_min(ft_abs(from),ft_abs(to));
	move_to(sortp, this, to * (ft_abs(from)- t) / ft_abs(to));
	move_to(sortp, lane_swich(this), to * (ft_abs(to) -t) / \
		ft_abs(to));
	movement(sortp, this, "p");
}

int	sort_ninsertionsort_count2down(t_sort_params *sortp, int from, int *position)
{
	int j;

	j = 0;
	while (sortp->ascending * get_nodec(sortp, lane_swich(sortp->cstack), from) > sortp->ascending * get_nodec(sortp, sortp->cstack, - \
	- position[0] + j -position[2]) && j < position[2])
		j++;
	if ((-  position[0] + j) * from > 0 && from < 0)
		return (ft_max(ft_abs(from),ft_abs( - position[0] + j -position[2]))*(ft_abs(from)+1)) ;
	else if ((-  position[0] + j) * from > 0)
		return (ft_max(ft_abs(from),ft_abs( - position[0] + j -position[2]))*(ft_abs(from)+1));
	else
		return (ft_abs(from)+ft_abs( - position[0] + j)*(ft_abs(from)+1));
}

void sort_ninsertionsort_put_in_place(t_sort_params *sortp, int from, int *position)
{
	int j;
	
	j = 0;
	while (sortp->ascending * get_nodec(sortp, lane_swich(sortp->cstack), from) > \
	sortp->ascending * get_nodec(sortp, sortp->cstack, - position[0] + j -position[2]) && 	j < position[2])
		j++;
	push_places(sortp, 'o', from, - position[0] + j -position[2]);
	position[2] ++;
	position[0] = j - position[2];
	position[3]--;
	position[1] += from;	
}

void	sort_ninsertionsort_bring_it_down_ex(t_sort_params *sortp, int *counter, \
	int *position)
{
	int j[3];
	
	sort_ninsertionsort_unravel(sortp,counter,position);
	while (position[2] < sortp->elements)
	{
		j[0] = ft_max(-position[1], -3);
		j[1] = 99;
		while(j[0] < ft_min(4,-position[1] + position[3]))
		{
			if(sort_ninsertionsort_count2down(sortp,j[0],position) < j[1])
			{
				j[1] = sort_ninsertionsort_count2down(sortp,j[0],position);
				j[2] = j[0];
			}
			j[0]++;	
		}
		sort_ninsertionsort_put_in_place(sortp, j[2], position);
	}
	move_to(sortp, 't', -position[0] -position[2]);
	position[0] = 0 * counter[0];

}


// position[2] size of the sorted area downstairs
// counter[1] just an iterator
// position[3] people upstairs
// counter[3] start of run
// counter[4] end of run
// counter[5] flag for complete upstairs fun
// position[0] distance from the start of the sorted area (to the left)
// position[1] size of the "left stack" upstairs
void	sort_ninsertionsort(t_sort_params *sortp)
{
	int		counter[6];
	int		position[4];
	long	*list;
	
	list = list_from_params(sortp);
	sort_ninsertionsort_start_strategy(sortp,counter, position, list);
	while (counter[1] < sortp->elements)
		sort_ninsertionsort_fill_upstairs(sortp, counter, position, list);
	position[0] = 0;
	sort_ninsertionsort_bring_it_down_ex(sortp, counter, position);
	free(list);
}

