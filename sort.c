/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:33:38 by amejia            #+#    #+#             */
/*   Updated: 2023/02/26 21:42:50 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

int	l_comparison(t_sort_params *sortp, char stack, long value)
{
	if (get_node(sortp, stack, 0) == 0)
		return (0);
	if (sortp->ascending * get_node(sortp, stack, 0)->content < \
		sortp->ascending * value)
		return (1);
	return (0);
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

void	sort(t_sort_params *sortp)
{
	long *list;

	list = 0;
	if (check_sorted(sortp))
		return ;
	if (sortp->elements <=3)
		sort_efficient3_ascending_cycle(sortp, list);
	if (sortp->elements < 40)
	{
		sortp->skip = 1;
		sort_nquicksort(sortp);
	}
	else
		sort_nquicksort(sortp);
}

void sort_smallchooser(t_sort_params *sortp)
{
	long values[6];

	if (sortp->elements > 3)
		sort_nquicksort(sortp);
	else if (sortp->elements == 2)
		sort_efficient2(sortp);
	else if (sortp->elements == 3 && get_node(sortp,'t',0) == get_node(sortp,'t',3) && sortp->ascending == 1)
		sort_efficient3_ascending_cycle(sortp, values);
	else if (sortp->elements == 3 && sortp->ascending == 1)
			sort_efficient3_ascending(sortp, values);
	else if (sortp->elements == 3 && sortp->ascending == -1)
			sort_efficient3_descending(sortp, values);
	return ;
}