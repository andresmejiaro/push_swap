/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_insertionsort3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 04:22:02 by andres            #+#    #+#             */
/*   Updated: 2023/03/11 04:48:06 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_places_2_way(int *fromb_tob, int *way)
{
	way[0] = ft_max(fromb_tob[0], fromb_tob[2]);
	way[1] = ft_max(fromb_tob[1], fromb_tob[3]);
	way[2] = ft_min(fromb_tob[0] + fromb_tob[3], fromb_tob[1] + fromb_tob[2]);
}

int	sort_ninsertionsort_count2down(t_sort_params *sortp, int from, \
									int *position)
{
	int	j;

	j = 0;
	while (sortp->ascending * get_nodec(sortp, lane_swich(sortp->cstack), \
		from) > sortp->ascending * get_nodec(sortp, sortp->cstack, \
		- position[0] + j - position[2]) && j < position[2])
		j++;
	return (sort_ninsertionsort_realcount(sortp, from, \
		- position[0] + j - position[2]));
}

void	sort_ninsertionsort_bring_it_down_ex(t_sort_params *sortp, \
		int *counter, int *position)
{
	int	j[3];

	while (position[2] < sortp->elements)
	{
		j[0] = -position[1];
		j[1] = 99;
		while (j[0] < -position[1] + position[3])
		{
			if (sort_ninsertionsort_count2down(sortp, j[0], position) < j[1])
			{
				j[1] = sort_ninsertionsort_count2down(sortp, j[0], position);
				j[2] = j[0];
			}
			j[0]++;
		}
		sort_ninsertionsort_put_in_place(sortp, j[2], position);
	}
	move_to(sortp, 't', -position[0] - position[2]);
	position[0] = 0 * counter[0];
}
