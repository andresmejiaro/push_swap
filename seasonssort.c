/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seasonssort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:29:48 by amejia            #+#    #+#             */
/*   Updated: 2023/02/14 18:28:14 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"


/// checks if the value in "this" (t) or other ("o") (the stack you are working
// on) or other is  "less" (modified to more if params is not ascending)
int	l_check(t_game *game,t_sort_params *sortp, char this,long value)
{
	if (this == 't')
		if (sortp->ascending * \
				stack_from_char(game, sortp->cstack)->content < \
				sortp->ascending * value)
			return (1);
	if (this == 'o')
		if (sortp->ascending * \
				stack_from_char(game, lane_swich(sortp->cstack))->content < \
				sortp->ascending * value)
			return (1);
	return (0);
}

/// checks if the value in "this" (t) or other ("o") (the stack you are working
// on) or other is  "more" (modified to more if params is not ascending)
int	m_check(t_game *game,t_sort_params *sortp, char this,long value)
{
	if (this == 't')
		if (sortp->ascending * \
				stack_from_char(game, sortp->cstack)->content > \
				sortp->ascending * value)
			return (1);
	if (this == 'o')
		if (sortp->ascending * \
				stack_from_char(game, lane_swich(sortp->cstack))->content > \
				sortp->ascending * value)
			return (1);
	return (0);
}


void	seasons_forwardpass(t_game *game, t_sort_params *sortp, long *quantiles)
{
	long	central_pivot;
	long 	down_pivot;
	int		elements;

	central_pivot = quantiles[1];
	down_pivot = (1 + sortp->ascending) / 2 * quantiles[0] - \
		(sortp->ascending - 1) * quantiles[3];
	elements = sortp->end - sortp->start + 1;
	while (1)
	{
		if (!l_check(game,sortp,'t',central_pivot) && \
			m_check(game,sortp,'o',down_pivot))
			mv_trans(game,stack_from_char(game, sortp->cstack), "r2");
		else if (l_check(game,sortp,'t',central_pivot))
			mv_trans(game,stack_from_char(game, sortp->cstack), "p");
		else if (!l_check(game,sortp,'t',central_pivot))
			mv_trans(game,stack_from_char(game, sortp->cstack), "r");
		else if (m_check(game,sortp,'o',down_pivot))
			mv_trans(game,stack_from_char(game,lane_swich(sortp->cstack)), "r");
		else break;	
			
			
			
	/*	if (sortp->ascending * \
			stack_from_char(game,lane_swich(sortp->cstack))->content \
			> sortp->ascending * down_pivot)
			mv_trans(game, stack_from_char(game, sortp->cstack),"r");
		else
			mv_trans(game, stack_from_char(game, sortp->cstack),"r2");*/
	}
}


void seasons_backpass(void)
{
	
}


void seasons_return(void)
{
	
}

void seasonssort(t_game *game, t_sort_params *sortp)
{
	int elements;
	long *el_list;
	long *quantiles;

	elements = sortp->end - sortp->start + 1;
	el_list = node_to_list(game, sortp);
	quantiles = list_quantiles_long(el_list,elements);
	free(el_list);
   	find_position(game, stack_from_char(game, sortp->cstack), sortp->start);
	seasons_forwardpass(game,sortp,quantiles);
	seasons_backpass();
	seasons_return();
	free(quantiles);
}
