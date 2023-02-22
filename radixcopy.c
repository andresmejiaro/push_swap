/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixcopy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 07:40:51 by amejia            #+#    #+#             */
/*   Updated: 2023/02/22 03:52:34 by amejia           ###   ########.fr       */
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
	free (list);
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

int	linesep(t_sort_params *sortp, char this, int *bit_kick, int size)
{
	int	counter;

	counter = 0;
	while (size--)
	{
		if ((((get_node(sortp, this, 0)->ordered_position) >> bit_kick[0]) \
			& 1) == bit_kick[1])
		{
			movement(sortp, this, "p");
			counter++;
		}
		else
		{
			move_to(sortp, this, 1);
		}
	}
	
	return (counter);
}

void	sort_radix(t_sort_params *sortp)
{
	int	counter[4];
	int	bit_kick[2];
	int	down;
	int down2;

	counter[3] = pseudologbase(sortp->elements, 2);
	ft_bzero(bit_kick, 2 * sizeof(int));
	down = linesep(sortp, 't', bit_kick, ft_lstgn_size(get_node(sortp, 't', 0)));
	while (counter[3]--)
	{
		bit_kick[0]++;
		bit_kick[1] = 0;
		down2 = linesep(sortp, 't', bit_kick, ft_lstgn_size(get_node(sortp, 't', 0)));
		move_to(sortp,'o',down2);
		bit_kick[1] = 1;
		down2 = linesep(sortp, 'o', bit_kick,ft_lstgn_size(get_node(sortp, 'o', 0)) - down2);
		// counter[2] = counter[1];
		// marca = 0;
		// while (counter[1] > 0)
		// 	radix_subloop(sortp, counter, &marca, &valor);
		// move_to(sortp, 't', find_value(sortp, 't', valor));
		// while (counter[2]-- > 0)
		// 	movement(sortp, 't', "u");
		// counter[0]++;
	}
	while (ft_lstgn_size(get_node(sortp, 'o', 0)))
		movement(sortp,'o',"p");
}
