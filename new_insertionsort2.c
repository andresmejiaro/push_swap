/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_insertionsort2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 10:41:31 by amejia            #+#    #+#             */
/*   Updated: 2023/03/11 04:46:00 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_ninsertionsort_upstairs_manuvers(t_sort_params *sortp, \
			int *position)
{
	movement(sortp, 't', "rr");
	movement(sortp, 't', "s");
	move_to(sortp, 't', 2);
	position[2]++;
}

void	sort_ninsertionsort_upstairs_separator(t_sort_params *sortp, \
	int *counter, int *position, long *list)
{
	if (sortp->ascending * get_nodec(sortp, 't', -1) < \
		sortp->ascending * get_nodec(sortp, 't', 1) && \
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

void	sort_ninsertionsort_fill_upstairs(t_sort_params *sortp, int *counter, \
	int *position, long *list)
{
	if (!l_comparison(sortp, 't', get_nodec(sortp, 't', -1)) && counter[5] == 1)
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
