/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statistics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:40:27 by amejia            #+#    #+#             */
/*   Updated: 2023/02/13 17:44:02 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

#include "libft/ft_calloc.c"
#include "libft/ft_bzero.c"
#include "libft/ft_memset.c"

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
	long	aux;
	size_t  orlen;
	
	if (len <= 1)
		return ;
	orlen = len;
	head = 1;
	len = len -1;
	while (len - head >= 1)
	{
		if (list[len] < list[0])
		{
			aux = list[len];
			list[len] = list[head];
			list[head] = aux;
			head++;
		}
		else
			len--;
	}
	while(list[head] > list[0])
		head--;
	aux = list[0];
	list[0] = list[head];
	list[head] = aux;
	list_qsort(list,head);
	list_qsort(list + head + 1, orlen - head - 1);
}

//this modifies the original list
//this mallocs the result
long *list_quantiles_long(long *list, size_t len)
{
	long *result;
	
	result =(long *)ft_calloc(3, sizeof(long));
	list_qsort(list, len);
	result[0] = list[len/4];
	result[1] = list[len/2];
	result[2] = list[(3*len)/4];
	return(result);
}


