/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 07:40:51 by amejia            #+#    #+#             */
/*   Updated: 2023/02/22 07:39:15 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	*radix_precount(t_sort_params *sortp, int prof)
{
	long	*list;
	int		counter;
	int		*precount;

	counter = 0;
	list = list_from_paramso(sortp);
	graceful_malloc_fail(list);
	precount = (int *)ft_calloc(4, sizeof(int));
	graceful_malloc_fail(precount);
	while (counter < sortp->elements)
	{
		if (((list[counter] >> prof) & 1) == 0 && \
			((list[counter] >> (prof +1)) & 1) == 0)
				precount[0]++;
		else if (((list[counter] >> prof) & 1) == 0)
				precount[1]++;
		else if (((list[counter] >> (prof +1)) & 1) == 0)
				precount[2]++;
		else
				precount[3]++;
		counter++;
	}
	free (list);
	return (precount);
}

void	radix_subloop_a(t_sort_params *sortp, int *precount, int valor, \
			long *rst)
{
	movement(sortp, 't', "p");
	if (((get_node(sortp, 't', 0)->ordered_position >> valor) & 1) == \
		1 && get_node(sortp, 't', 0)->ordered_position != *rst)
	{
		if (*rst == -1)
				*rst = get_node(sortp, 't', 0)->content;
		movement(sortp, 'o', "r2");
	}
	else
	{
		movement2(sortp, 'o', "r");
	}
	precount[1]--;
}

void	radix_subloop(t_sort_params *sortp, int *precount, int valor, long *rst)
{
	int	nv;

	nv = get_node(sortp, 't', 0)->ordered_position;
	if (((nv >> valor) & 1) == 0 && ((nv >> (valor +1)) & 1) == 1)
		radix_subloop_a(sortp, precount, valor, rst);
	else if (((nv >> valor) & 1) == 0)
	{
		movement(sortp, 't', "p");
		precount[0]--;
	}	
	else
	{
		if (*rst == -1)
			*rst = get_node(sortp, 't', 0)->content;
		movement2(sortp, 't', "r");
	}
}

void	radix_subloop2(t_sort_params *sortp, int *precount, int valor, \
			long *reset)
{
	int	nv;

	nv = get_node(sortp, 't', 0)->ordered_position;
	if (((nv >> (valor +1)) & 1) == 0)
	{
		movement(sortp, 't', "p");
		precount[2]--;
	}			
	else
	{
		if (*reset == -1)
			*reset = get_node(sortp, 't', 0)->content;
		movement2(sortp, 't', "r");
	}
}

void	radix_bounce(t_sort_params *sortp, int *precount2)
{
	while (precount2[1]--)
	{
		movement2(sortp, 'o', "rr");
		movement(sortp, 't', "u");
	}		
	while (precount2[0]--)
		movement(sortp, 'o', "p");
	while (precount2[2]--)
		movement(sortp, 'o', "p");
}
