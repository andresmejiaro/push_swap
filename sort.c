/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:33:38 by amejia            #+#    #+#             */
/*   Updated: 2023/02/17 05:14:22 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

// this mallocs the result
t_sort_params	*sort_params(char cstack, int start, int end, int ascending)
{
	t_sort_params	*params;

	params = (t_sort_params *)ft_calloc(1, sizeof(t_sort_params));
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
	return (params);
}

int	l_comparison(t_sort_params *sortp, char stack,long value)
{
	if (get_node(sortp, stack, 0) == 0)
		return (0);
	if (sortp->ascending * get_node(sortp, stack, 0)->content < \
		sortp->ascending * value)
		return (1);
	return (0);
}

