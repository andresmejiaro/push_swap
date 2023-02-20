/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statistics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:40:27 by amejia            #+#    #+#             */
/*   Updated: 2023/02/20 01:49:31 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	random_uint(unsigned int range)
{
	static int	seed;
	long		a;
	long		m;

	if (seed == 0)
		seed = SEED_N;
	a = 16807;
	m = 2147483647;
	seed = (a * seed) % m;
	range = seed % range;
	return (range);
}

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
	list_qsort(list, len);
	result[0] = list[len / 4];
	result[1] = list[len / 2];
	result[2] = list[(3 * len) / 4];
	return (result);
}

//this mallocs the result
// Counts the results up to the each quartile (not including except for the 
// last one)
long	*count_quantiles_long(long *list, size_t len)
{
	long	*result;
	long	*result_count;

	result = (long *)ft_calloc(3, sizeof(long));
	list_qsort(list, len);
	result[0] = list[len / 4];
	result[1] = list[len / 2];
	result[2] = list[(3 * len) / 4];
	result_count = (long *)ft_calloc(4, sizeof(size_t));
	while (len-- > 0)
	{
		if (list[len] >= result[2])
			result_count[3]++;
		else if (list[len] >= result[1])
			result_count[2]++;
		else if (list[len] >= result[0])
			result_count[1]++;
		else
			result_count[0]++;
	}
	free(result);
	return (result_count);
}

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

