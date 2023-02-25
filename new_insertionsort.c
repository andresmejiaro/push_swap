/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_insertionsort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:37:42 by amejia            #+#    #+#             */
/*   Updated: 2023/02/25 00:40:27 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_ninsertionsort_upstairs_separator(t_sort_params *sortp, \
	int *counter, int *position, long *list)
{
	if (l_comparison(sortp, 'o', list[sortp->elements / 2]) \
		&& counter[2] - position[1] > 0)
	{
		movement(sortp, 't', "r2");
		position[1]++;
	}
	else
		movement(sortp, 't', "r");
	counter[0]++;
}

void	sort_ninsertionsort_fill_upstairs(t_sort_params *sortp, int *counter, \
	int *position, long *list)
{
	if (!l_comparison(sortp, 't',get_nodec(sortp, 't', -1)))
		sort_ninsertionsort_upstairs_separator(sortp, counter, position, \
		list);
	else if (l_comparison(sortp, 'o', list[sortp->elements / 2]) \
		&& ft_lstgn_size(get_node(sortp, 'o', 0)) > 1 && \
		counter[2] - position[1] > 0)
	{
		movement2(sortp, 'o', "r");
		counter[1]--;
		position[1]++;
	}
	else if (counter[0] == 1 || \
		!l_comparison(sortp, 't', get_nodec(sortp, 't', -2)))
	{
		movement(sortp, 't', "rr");
		movement(sortp, 't', "s");
		move_to(sortp, 't', 2);
		counter[0]++;
	}
	else
	{
		movement(sortp, 't', "p");
		counter[2]++;
	}
	counter[1]++;
}

void	sort_ninsertionsort_unravel(t_sort_params *sortp, int *counter, \
	int *position)
{
	while (sortp->ascending * get_nodec(sortp, 't', -1) > \
		sortp->ascending * get_nodec(sortp, 'o', -1) &&
		position[1] > 0 && position[0] > 0 )
	{
		position[1]--;
		position[0]--;
		movement(sortp, 't', "rr2");
	}
	if (position[1] + counter[0] == sortp->elements && position[1] != 0)
	{
		position[1]--;
		movement2(sortp,'o',"rr");
	}
}

void	sort_ninsertionsort_bring_it_down(t_sort_params *sortp, int *counter, \
	int *position)
{
	while (counter[0] < sortp->elements)
	{
		if (position[1] + counter[0] == sortp->elements && position[1] != 0)
			sort_ninsertionsort_unravel(sortp, counter, position);
		while (l_comparison(sortp, 'o', get_nodec(sortp, 't', -1)) \
			&& position[0] > 0)
		{
			movement(sortp, 't', "rr");
			position[0]--;
		}
		while (!l_comparison(sortp, 'o', get_nodec(sortp, 't', 0)) \
		&& position[0] < counter[0])
		{
			movement(sortp, 't', "r");
			position[0]++;
		}
		movement(sortp, 't', "u");
		counter[0]++;
	}
	move_to(sortp, 't', -position[0]);
	position[0] = 0;
}


// counter[0] size of the sorted area downstairs
// counter[1] just an iterator
// position[0] distance from the start of the sorted area (to the left)
// position[1] size of the "left stack" upstairs
// counter[2] people upstairs
void	sort_ninsertionsort(t_sort_params *sortp)
{
	int		counter[3];
	int		position[3];
	long	*list;

	list = list_from_params(sortp);
	list_qsort(list, sortp->elements);
	ft_bzero(counter, 3 * sizeof(int));
	ft_bzero(position, 3 * sizeof(int));
	while (sortp->ascending * get_nodec(sortp, 't', sortp->start + counter[0]) \
		< sortp->ascending * (get_nodec(sortp, 't', sortp->start + counter[0] \
			+ 1)))
		counter[0]++;
	move_to(sortp, 't', sortp->start + ++counter[0]);
	counter[1] = counter[0];
	while (counter[1] < sortp->elements)
		sort_ninsertionsort_fill_upstairs(sortp, counter, position, list);
	if (get_nodec(sortp, 't', 0)== get_nodec(sortp, 't', -counter[0]))
		position[0] = 0;
	else
	{
		movement(sortp, 't', "rr");
		position[0] = counter[0] - 1;
	}
	sort_ninsertionsort_bring_it_down(sortp, counter, position);
	free(list);
}
