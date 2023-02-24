/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix8way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 07:40:51 by amejia            #+#    #+#             */
/*   Updated: 2023/02/23 23:07:06 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	*radix_precount8(t_sort_params *sortp, int prof)
{
	long	*list;
	int		counter;
	int		*precount;
	int 	bits[3];
	
	counter = 0;
	list = list_from_paramso(sortp);
	graceful_malloc_fail(list);
	precount = (int *)ft_calloc(8, sizeof(int));
	graceful_malloc_fail(precount);
	while (counter < sortp->elements)
	{
		bit[0] = (list[counter] >> prof) & 1;
		bit[1] = (list[counter] >> prof + 1) & 1;
		bit[2] = (list[counter] >> prof + 2) & 1;
		precount[bit[0] + 2 * bit[1] + 4 * bit[2]]++;
		counter++;
	}
	free (list);
	return (precount);
}

