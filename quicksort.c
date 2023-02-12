/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:26:19 by amejia            #+#    #+#             */
/*   Updated: 2023/02/12 12:11:19 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_qsort(t_game *game, t_sort_params *sortp)
{
	int		elements;
	int 	counter;
	int 	npushed;
	int 	pivot;
	char 	cstack;
	
	t_sort_params *params;
	elements = sortp->end - sortp->start+1;
	find_position(game, stack_from_char(game,sortp->cstack), sortp->start);
	pivot =stack_from_char(game,sortp->cstack)->content;
	//qsort_push(game, sortp,pivot,&npushed);
	counter = elements;
	npushed = 0;
	while(counter-- > 0)
	{
		if (sortp->ascending * stack_from_char(game,sortp->cstack)->content < sortp->ascending*pivot)
		{
			movement_translator(game, stack_from_char(game,sortp->cstack),"p");
			npushed++;
		}
		else
			movement_translator(game, stack_from_char(game,sortp->cstack),"r");
	}
	find_value(game,stack_from_char(game,sortp->cstack),pivot);
	if (npushed > 0)
	{
		params = sort_params(lane_swich(sortp->cstack),0,npushed-1,-sortp->ascending);
		sort(game,params);
		free(params);
	}
	params = sort_params(sortp->cstack,1,elements -npushed-1,sortp->ascending);
	sort(game,params);
	free(params);
	find_value(game,stack_from_char(game,sortp->cstack),pivot);
	if (npushed > 0 && sortp->ascending*(stack_from_char(game,lane_swich(sortp->cstack))->content) > pivot*(sortp->ascending))
		movement_translator(game,stack_from_char(game,sortp->cstack),"rr");
	while (npushed-- > 0)
		movement_translator(game, stack_from_char(game,sortp->cstack), "u");
}

void	qsort_push(t_game *game, t_sort_params *sortp, int pivot, int *npushed)
{
	int	counter;
	int	elements;

	elements = sortp->end - sortp->start + 1;
	counter = elements;
	npushed = 0;
	while (counter-- > 0)
	{
		if (sortp->ascending * stack_from_char(game,sortp->cstack)->content <\
			sortp->ascending * pivot)
		{
			movement_translator(game, stack_from_char(game, sortp->cstack), "p");
			(*npushed)++;
		}
		else
			movement_translator(game, stack_from_char(game, sortp->cstack), "r");
	}
	find_value(game, stack_from_char(game, sortp->cstack), pivot);
}