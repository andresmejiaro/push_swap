/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 06:45:38 by amejia            #+#    #+#             */
/*   Updated: 2023/02/22 18:00:08 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_early_stop(t_sort_params *sortp)
{
	t_sort_params	*sortp2;

	if (sortp->game->stack_a == 0)
		return (0);
	sortp2 = sort_params('a', 0, ft_lstgn_size(sortp->game->stack_a) - 1, 1);
	sortp2->game = sortp->game;
	if (check_sorted(sortp2))
	{
		while (sortp->game->stack_b != 0)
		{
			movement(sortp, 'b', "p");
		}
		return (free(sortp2), 1);
	}
	return (0);
}


void	sort_radix(t_sort_params *sortp)
{
	int		counter;
	long	reset;
	int		*precount[2];

	counter = 0;
	while (!check_sorted(sortp))
	{
		precount[0] = radix_precount(sortp, counter);
		precount[1] = radix_precount(sortp, counter);
		reset = -1;
		while ((precount[0][0] || precount[0][1]))
			radix_subloop(sortp, precount[0], counter, &reset);
		move_to(sortp, 't', find_value(sortp, 't', reset));
		reset = -1;
		if (check_early_stop(sortp))
			break;
		while (precount[0][2])
			radix_subloop2(sortp, precount[0], counter, &reset);
		move_to(sortp, 't', find_value(sortp, 't', reset));
		radix_bounce(sortp, precount[1]);
		counter += 2;
		free(precount[0]);
		free(precount[1]);
	}
}