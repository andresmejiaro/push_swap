/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix8way2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 06:45:38 by amejia            #+#    #+#             */
/*   Updated: 2023/02/23 23:10:38 by amejia           ###   ########.fr       */
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
		if (sortp->game->stack_b == 0)
			return (free(sortp2), ft_printf("boo"), 1);	
		sortp2 = sort_params('b', 0, ft_lstgn_size(sortp->game->stack_b) - 1, -1);
		sortp2->game = sortp->game;
		if (!check_sorted(sortp2))
			return (free(sortp2), 0);
		while (sortp->game->stack_b != 0)
		{
			movement(sortp, 'b', "p");
		}
		return (free(sortp2), 1);
	}
	free(sortp2);
	return (0);
}


void	sort_radix8(t_sort_params *sortp)
{
//	int		counter;
//	long	reset;
//	int		*precount[8];

	counter = 0;
	while (!check_sorted(sortp))
	{
		precount[0] = radix_precount8(sortp, counter);
		precount[1] = radix_precount8(sortp, counter);
	}
}