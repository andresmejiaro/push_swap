/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:00:12 by amejia            #+#    #+#             */
/*   Updated: 2023/03/11 03:19:24 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_efficient3_ascending_cont(t_sort_params *sortp, long *list)
{
	if (get_nodec(sortp, 't', 0) == list[2] && \
		get_nodec(sortp, 't', 1) == list[1])
	{
		movement(sortp, 't', "s");
		movement(sortp, 't', "r");
		movement(sortp, 't', "s");
		movement(sortp, 't', "rr");
		movement(sortp, 't', "s");
	}
	else if (get_nodec(sortp, 't', 0) == list[2] && \
		get_nodec(sortp, 't', 1) == list[0])
	{
		movement(sortp, 't', "s");
		movement(sortp, 't', "r");
		movement(sortp, 't', "s");
		movement(sortp, 't', "rr");
	}
}

void	sort_efficient3_ascending(t_sort_params *sortp, long *list)
{
	list = list_from_params(sortp);
	list_qsort(list, 3);
	move_to(sortp, 't', sortp->start);
	if (get_nodec(sortp, 't', 0) == list[0] && \
		get_nodec(sortp, 't', 1) == list[2])
	{
		movement(sortp, 't', "r");
		movement(sortp, 't', "s");
		movement(sortp, 't', "rr");
	}
	else if (get_nodec(sortp, 't', 0) == list[1] && \
		get_nodec(sortp, 't', 1) == list[0])
		movement(sortp, 't', "s");
	else if (get_nodec(sortp, 't', 0) == list[1] && \
		get_nodec(sortp, 't', 1) == list[2])
	{
		movement(sortp, 't', "r");
		movement(sortp, 't', "s");
		movement(sortp, 't', "rr");
		movement(sortp, 't', "s");
	}
	else
		sort_efficient3_ascending_cont(sortp, list);
	free(list);
}

void	sort_efficient3_descending_cont(t_sort_params *sortp, long *list)
{
	if (get_nodec(sortp, 't', 0) == list[0] && \
		get_nodec(sortp, 't', 1) == list[1])
	{
		movement(sortp, 't', "s");
		movement(sortp, 't', "r");
		movement(sortp, 't', "s");
		movement(sortp, 't', "rr");
		movement(sortp, 't', "s");
	}
	else if (get_nodec(sortp, 't', 0) == list[0] && \
		get_nodec(sortp, 't', 1) == list[2])
	{
		movement(sortp, 't', "s");
		movement(sortp, 't', "r");
		movement(sortp, 't', "s");
		movement(sortp, 't', "rr");
	}
}

void	sort_efficient3_descending(t_sort_params *sortp, long *list)
{
	list = list_from_params(sortp);
	list_qsort(list, 3);
	move_to(sortp, 't', sortp->start);
	if (get_nodec(sortp, 't', 0) == list[2] && \
		get_nodec(sortp, 't', 1) == list[0])
	{
		movement(sortp, 't', "r");
		movement(sortp, 't', "s");
		movement(sortp, 't', "rr");
	}
	else if (get_nodec(sortp, 't', 0) == list[1] && \
		get_nodec(sortp, 't', 1) == list[2])
		movement(sortp, 't', "s");
	else if (get_nodec(sortp, 't', 0) == list[1] && \
		get_nodec(sortp, 't', 1) == list[0])
	{
		movement(sortp, 't', "r");
		movement(sortp, 't', "s");
		movement(sortp, 't', "rr");
		movement(sortp, 't', "s");
	}
	else
		sort_efficient3_descending_cont(sortp, list);
	free(list);
}

void	sort_efficient2(t_sort_params *sortp)
{
	move_to(sortp, 't', sortp->start);
	if (!l_comparison(sortp, 't', get_nodec(sortp, 't', 1)))
		movement(sortp, 't', "s");
}
