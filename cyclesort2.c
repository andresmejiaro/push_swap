/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyclesort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 06:39:24 by amejia            #+#    #+#             */
/*   Updated: 2023/02/22 06:50:07 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cycle_solve(t_sort_params *sortp, int *opt_p)
{
	int	position[2];
	int	distance[3];

	ft_bzero(distance, 3 * sizeof(int));
	while (get_node(sortp, 't', opt_p[0] + distance[2])->ordered_position == \
				distance[2] + 1)
			distance[2]++;
	position[0] = opt_p[0] + distance[2];
	position[1] = get_node(sortp, 't', position[0])->ordered_position -1 \
		- position[0];
	move_to(sortp, 't', position[0]);
	while (distance[0] != 0 || distance[1]++ == 0)
	{
		cycle_solve_loop(sortp, position, distance);
	}
}

void	sort_cyclesort(t_sort_params *sortp)
{
	int	*opt_p;

	opt_p = optimal_starting_p(sortp);
	while (opt_p[1] < sortp->elements)
	{
		cycle_solve(sortp, opt_p);
		opt_p = optimal_starting_p(sortp);
	}
	move_to(sortp, 't', opt_p[0]);
	free(opt_p);
}
