/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_global_manip_comparisons.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:14:26 by amejia            #+#    #+#             */
/*   Updated: 2023/02/15 02:15:34 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"


/// checks if the value in "this" (t) or other ("o") (the stack you are working
// on) or other is  "less" (modified to more if params is not ascending)
int	l_check(t_game *game,t_sort_params *sortp, char this,long value)
{
	if (this == 't')
	{
		if (stack_from_char(game, sortp->cstack) == 0)
			return (9);
		else if (sortp->ascending * \
				stack_from_char(game, sortp->cstack)->content <= \
				sortp->ascending * value)
			return (1);
	}
	if (this == 'o')
	{
		if (stack_from_char(game, lane_swich(sortp->cstack)) == 0)
			return (9);
		else if (sortp->ascending * \
				stack_from_char(game, lane_swich(sortp->cstack))->content <= \
				sortp->ascending * value)
			return (1);
	}
	return (0);
}

/// checks if the value in "this" (t) or other ("o") (the stack you are working
// on) or other is  "more" (modified to more if params is not ascending)
int	m_check(t_game *game,t_sort_params *sortp, char this,long value)
{
	if (this == 't')
	{
		if (stack_from_char(game, sortp->cstack) == 0)
			return (9);
		else if (sortp->ascending * \
				stack_from_char(game, sortp->cstack)->content >= \
				sortp->ascending * value)
			return (1);
	}
	if (this == 'o')
	{
		if (stack_from_char(game, lane_swich(sortp->cstack)) == 0)
			return (0);
		else if (sortp->ascending * \
				stack_from_char(game, lane_swich(sortp->cstack))->content >= \
				sortp->ascending * value)
			return (1);
	}
	return (0);
}

