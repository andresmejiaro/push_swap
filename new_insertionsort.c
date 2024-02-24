/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_insertionsort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:37:42 by amejia            #+#    #+#             */
/*   Updated: 2023/03/11 04:50:21 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_ninsertionsort_start_strategy(t_sort_params *sortp, int *counter, \
	int *position, long *list)
{
	list_qsort(list, sortp->elements);
	ft_bzero(counter, 6 * sizeof(int));
	ft_bzero(position, 4 * sizeof(int));
	move_to(sortp, 't', sortp->start);
	if (counter[3] < 3 * counter[4])
	{
		while (counter[1] < counter[3])
			sort_ninsertionsort_fill_upstairs(sortp, counter, position, list);
		move_to(sortp, 't', counter[4]);
		position[2] = counter[4];
		counter[1] += counter[4];
	}
	counter[5]++;
}

void	sort_ninsertionsort_put_in_place(t_sort_params *sortp, \
	int from, int *position)
{
	int	j;

	j = 0;
	while (sortp->ascending * get_nodec(sortp, lane_swich(sortp->cstack), from) \
		> sortp->ascending * get_nodec(sortp, sortp->cstack, \
		-position[0] + j - position[2]) && j < position[2])
		j++;
	push_places_2(sortp, from, -position[0] + j - position[2]);
	position[2]++;
	position[0] = j - position[2];
	position[3]--;
	position[1] += from;
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
	sort_ninsertionsort_start_strategy(sortp, counter, position, list);
	while (counter[1] < sortp->elements)
		sort_ninsertionsort_fill_upstairs(sortp, counter, position, list);
	position[0] = 0;
	sort_ninsertionsort_bring_it_down_ex(sortp, counter, position);
	free(list);
}
