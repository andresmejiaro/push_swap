/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statistics_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:40:27 by amejia            #+#    #+#             */
/*   Updated: 2023/03/11 23:26:36 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

//this modifies the original list
void	list_qsort(long *list, size_t len)
{
	size_t	head;
	size_t	orlen;

	if (len <= 1)
		return ;
	orlen = len;
	head = 1;
	len = len -1;
	while (len - head >= 1)
	{
		if (list[len] < list[0])
		{
			ft_value_swap_l(list + len, list + head);
			head++;
		}
		else
			len--;
	}
	while (list[head] > list[0])
		head--;
	ft_value_swap_l(list, list + head);
	list_qsort(list, head);
	list_qsort(list + head + 1, orlen - head - 1);
}

//this modifies the original list
//this mallocs the result
long	*list_quantiles_long(long *list, size_t len)
{
	long	*result;

	result = (long *)ft_calloc(3, sizeof(long));
	graceful_malloc_fail(result);
	list_qsort(list, len);
	result[0] = list[len / 4];
	result[1] = list[len / 2];
	result[2] = list[(3 * len) / 4];
	return (result);
}

//this mallocs the result
// Counts the results up to the each quartile (not including except for the 
// last one)

void	list_qsort_int(int *list, size_t len)
{
	size_t	head;
	size_t	orlen;

	if (len <= 1)
		return ;
	orlen = len;
	head = 1;
	len = len -1;
	while (len - head >= 1)
	{
		if (list[len] < list[0])
		{
			ft_value_swap_i(list + len, list + head);
			head++;
		}
		else
			len--;
	}
	while (list[head] > list[0])
		head--;
	ft_value_swap_i(list, list + head);
	list_qsort_int(list, head);
	list_qsort_int(list + head + 1, orlen - head - 1);
}
