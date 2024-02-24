/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:00:12 by amejia            #+#    #+#             */
/*   Updated: 2023/03/11 03:18:32 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_efficient3_ascending_cycle_cont(t_sort_params *sortp, long *list)
{
	if (get_nodec(sortp, 't', 0) == list[2] && \
		get_nodec(sortp, 't', 1) == list[1])
	{
		movement(sortp, 't', "s");
		movement(sortp, 't', "rr");
	}
	else if (get_nodec(sortp, 't', 0) == list[2] && \
		get_nodec(sortp, 't', 1) == list[0])
		movement(sortp, 't', "r");
}

void	sort_efficient3_ascending_cycle(t_sort_params *sortp, long *list)
{
	list = list_from_params(sortp);
	list_qsort(list, 3);
	move_to(sortp, 't', sortp->start);
	if (get_nodec(sortp, 't', 0) == list[0] && \
		get_nodec(sortp, 't', 1) == list[2])
	{
		movement(sortp, 't', "s");
		movement(sortp, 't', "r");
	}
	else if (get_nodec(sortp, 't', 0) == list[1] && \
		get_nodec(sortp, 't', 1) == list[0])
		movement(sortp, 't', "s");
	else if (get_nodec(sortp, 't', 0) == list[1] && \
		get_nodec(sortp, 't', 1) == list[2])
		movement(sortp, 't', "rr");
	else
		sort_efficient3_ascending_cycle_cont(sortp, list);
	free(list);
}

void	small_efficient_sort(t_sort_params *sortp)
{
	long	values[4];

	if (sortp->elements == 1)
		sort_ninsertionsort(sortp);
	else if (sortp-> elements == 2)
		sort_efficient2(sortp);
	else if (sortp->elements == 3 && sortp->ascending == 1 && \
		get_node(sortp, 't', sortp->start - 1) == \
		get_node(sortp, 't', sortp->end))
		sort_efficient3_ascending_cycle(sortp, values);
	else if (sortp->elements == 3 && sortp->ascending == 1)
		sort_efficient3_ascending(sortp, values);
	else if (sortp->elements == 3 && sortp->ascending == -1)
		sort_efficient3_descending(sortp, values);
	else
		sort_ninsertionsort(sortp);
	return ;
}
