/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:23:28 by amejia            #+#    #+#             */
/*   Updated: 2023/02/19 21:57:32 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sort_quicksort_align(t_sort_params *sortp)
{
	t_sort_params	*sort2;

	if (sortp->elements != ft_lstgn_size(get_node(sortp,'t',0)))
		move_to(sortp, 't', sortp->start);
	sort2 = sort_params(sortp->cstack, 0, sortp->elements - 1, \
		sortp->ascending);
	sort2->game = sortp->game;
	sort_quicksort(sort2);
	free(sort2);
}
