/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 07:40:51 by amejia            #+#    #+#             */
/*   Updated: 2023/02/19 17:21:36 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	radix_precount(t_sort_params *sortp, int prof)
{
	long	*list;
	int		counter[2];

	ft_bzero(counter, 2 * sizeof(int));
	list = list_from_paramso(sortp);
	while (counter[0] < sortp->elements)
	{
		if (((list[counter[0]] >> prof) & 1) == 0)
			counter[1]++;
		counter[0]++;
	}
	return (counter[1]);
}

void	radix_subloop(t_sort_params *sortp, int *counter, \
			int *marca, int *valor)
{
	if ((((get_node(sortp, 't', 0)->ordered_position) >> counter[0]) \
			& 1) == 0)
	{
		movement(sortp, 't', "p");
		counter[1]--;
	}
	else if (*marca == 0)
	{
		*marca = 1;
		*valor = get_node(sortp, 't', 0)->content;
	}
	else
		move_to(sortp, 't', 1);
}

void	sort_radix(t_sort_params *sortp)
{
	int	counter[4];
	int	marca;
	int	valor;

	counter[0] = 0;
	counter[3] = pseudologbase(sortp->elements, 2);
	while (counter[3]--)
	{
		counter[1] = radix_precount(sortp, counter[0]);
		counter[2] = counter[1];
		marca = 0;
		while (counter[1] > 0)
			radix_subloop(sortp, counter, &marca, &valor);
		move_to(sortp, 't', find_value(sortp, 't', valor));
		while (counter[2]-- > 0)
			movement(sortp, 't', "u");
		counter[0]++;
	}
}
