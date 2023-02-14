/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:26:19 by amejia            #+#    #+#             */
/*   Updated: 2023/02/14 16:41:12 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_qsort(t_game *game, t_sort_params *sortp)
{
	int		elements;
	int		npushed;
	int		pivot;

	elements = sortp->end - sortp->start + 1;
	find_position(game, stack_from_char(game, sortp->cstack), sortp->start);
	pivot = stack_from_char(game, sortp->cstack)->content;
	qsort_push(game, sortp, pivot, &npushed);
	find_value(game, stack_from_char(game, sortp->cstack), pivot);
	if (npushed > 0)
		call_sort(lane_swich(sortp->cstack), 0, npushed - 1, -sortp->ascending);
	call_sort(sortp->cstack, 1, elements - npushed - 1, sortp->ascending);
	find_value(game, stack_from_char(game, sortp->cstack), pivot);
	if (npushed > 0 && sortp->ascending * (stack_from_char(game, \
		lane_swich(sortp->cstack))->content) > pivot * (sortp->ascending))
		mv_trans(game, stack_from_char(game, sortp->cstack), "rr");
	while (npushed-- > 0)
		mv_trans(game, stack_from_char(game, sortp->cstack), "u");
}

// 0 counter 1 elements 2 elements to push
void	qsort_push(t_game *game, t_sort_params *sortp, int pivot, int *npushed)
{
	int			counter[3];
	t_game_node	*position;

	counter[1] = sortp->end - sortp->start + 1;
	position = stack_from_char(game, sortp->cstack);
	counter[0] = counter[1];
	counter[2] = 0;
	while (counter[0]-- > 0)
	{
		if (sortp->ascending * position->content < sortp->ascending * pivot)
			counter[2]++;
		position = position->next;
	}
	(*npushed) = counter[2];
	while (counter[1]-- > 0 && counter[2] > 0)
	{
		if (sortp->ascending * stack_from_char(game, sortp->cstack)->content < \
					sortp->ascending * pivot)
		{
			mv_trans(game, stack_from_char(game, sortp->cstack), "p");
			counter[2]--;
		}
		else
			mv_trans(game, stack_from_char(game, sortp->cstack), "r");
	}
}
