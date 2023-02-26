/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_insertionsort2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 10:41:31 by amejia            #+#    #+#             */
/*   Updated: 2023/02/25 11:30:04 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_ninsertionsort_otherside(t_sort_params *sortp)
{
	int	size;
	int	position;

	move_to(sortp, 't', sortp->start);
	size = 1;
	movement(sortp, 't' , "p");
	sortp->elements--;
	position = 0;
	while (sortp->elements-- > 0)
	{
		while (l_comparison(sortp, 't',get_nodec(sortp,'o',0)) && position > 0 \
		&& ft_lstgn_size(get_node(sortp, 'o', 0)) > 1)
		{
			position--;
			movement2(sortp, 'o', "rr");
		}
		while (!l_comparison(sortp, 't',get_nodec(sortp,'o',0)) && \
		position < size && ft_lstgn_size(get_node(sortp, 'o', 0)) > 1)
		{
			position++;
			movement2(sortp, 'o', "r");
		}
		movement(sortp, 'o', "u");
		size++;
	}
	move_to(sortp, 'o', -position);
}