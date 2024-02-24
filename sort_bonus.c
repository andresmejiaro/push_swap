/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:33:38 by amejia            #+#    #+#             */
/*   Updated: 2023/03/12 01:11:20 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// this mallocs the result
t_sort_params	*sort_params(char cstack, int start, int end, int ascending)
{
	t_sort_params	*params;

	params = (t_sort_params *)ft_calloc(1, sizeof(t_sort_params));
	graceful_malloc_fail(params);
	params->ascending = ascending;
	params->cstack = cstack;
	if (start < end)
	{
		params->start = start;
		params->end = end;
	}
	else
	{
		params->end = start;
		params->start = end;
	}
	params->elements = params->end - params->start + 1;
	params->skip = 0;
	return (params);
}

int	check_sorted(t_sort_params *sortp)
{
	long	*sorted_list;
	int		ct;

	if (sortp->elements <= 1)
		return (1);
	sorted_list = list_from_params(sortp);
	graceful_malloc_fail(sorted_list);
	list_qsort(sorted_list, sortp->elements);
	ct = 0;
	while (ct < sortp->elements)
	{
		if (sortp->ascending == 1 && (get_node(sortp, 't', sortp->start + \
			ct)->content != sorted_list[ct]))
			return (free(sorted_list), 0);
		if (sortp->ascending == -1 && (get_node(sortp, 't', sortp->start + ct)->\
			content != sorted_list[sortp->elements - ct - 1]))
			return (free(sorted_list), 0);
		ct++;
	}
	free(sorted_list);
	return (1);
}
