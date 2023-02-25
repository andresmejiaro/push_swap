/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:33:49 by amejia            #+#    #+#             */
/*   Updated: 2023/02/24 15:53:45 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_efficient4_start1(t_sort_params *sortp)
{
	t_sort_params	*sortp2;
	long			list[4];

	move_to(sortp, 't', sortp->start + 1);
	sortp2 = sort_params('t', 0, 2, sortp->ascending);
	sortp2->game=sortp->game;
	if (sortp->ascending == 1)
		sort_efficient3_ascending(sortp2, list);
	else
		sort_efficient3_descending(sortp2, list);
	movement(sortp, 't', "rr");
	free(sortp2);
}

void	sort_efficient4_start2(t_sort_params *sortp)
{
	t_sort_params	*sortp2;
	long			list[4];

	move_to(sortp, 't', sortp->start);
	movement(sortp, 't', "s");
	sortp2 = sort_params('t', 0, 4, sortp->ascending);
	sortp2->game = sortp->game;
	if (check_sorted(sortp2))
	{
		free(sortp2);
		return ;
	}
	free(sortp2);
	sortp2 = sort_params('t', 1, 3, sortp->ascending);
	sortp2->game = sortp->game;
	if (sortp->ascending == 1)
		sort_efficient3_ascending(sortp2, list);
	else
		sort_efficient3_descending(sortp2, list);
	movement(sortp, 't', "rr");
	movement(sortp, 't', "s");
	free(sortp2);
}
