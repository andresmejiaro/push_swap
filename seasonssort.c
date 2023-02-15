/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seasonssort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:29:48 by amejia            #+#    #+#             */
/*   Updated: 2023/02/15 02:20:18 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	section_count(long **qcount, t_sort_params *sortp)
{
	size_t bigbox;
	size_t box;
	size_t smallbox;

	if (sortp->ascending == 1)
	{
		bigbox = (*qcount)[2]+(*qcount)[3];
		box = (*qcount)[1];
		smallbox = (*qcount)[0];
	}
	if (sortp->ascending == -1)
	{
		bigbox = (*qcount)[0]+(*qcount)[1];
		box = (*qcount)[2];
		smallbox = (*qcount)[3];	
	}
	(*qcount)[0] = smallbox;
	(*qcount)[1] = box;
	(*qcount)[2] = bigbox;
	(*qcount)[3] = smallbox + box + bigbox;
}

void	seasons_forwardpass(t_game *game, t_sort_params *sortp)
{
	int		elements;
	long	*el_list;
	long	*qcount;
	long	*qu;

	elements = sortp->end - sortp->start + 1;
	el_list = node_to_list(game, sortp);
	qu = list_quantiles_long(el_list, elements);
	qcount = count_quantiles_long(el_list, elements);
	section_count(&qcount, sortp);
	free(el_list);
	qu[0] = (1 + sortp->ascending) / 2 * qu[0] - \
		(sortp->ascending - 1) * qu[3];
	while ((qcount[0] > 0) || (qcount[1] > 0) || (qcount[3] > 0))
	{
		if (!l_check(game, sortp, 't', qu[1]) && \
			m_check(game, sortp, 'o', qu[0]))
		{
			mv_trans(game,stack_from_char(game, sortp->cstack), "r2");
			qcount[2]--;
			qcount[1]--;
		}
		else if (m_check(game,sortp,'o',qu[0]) && size_o(game)))
		{
			mv_trans(game, stack_from_char(game, lane_swich(sortp->cstack)), "r");
			qcount[1]--;
		}
		else if (l_check(game, sortp, 't', qu[1]))
			mv_trans(game,stack_from_char(game, sortp->cstack), "p");
		else if (!l_check(game, sortp, 't', qu[1]))
		{
			mv_trans(game,stack_from_char(game, sortp->cstack), "r");
			qcount[2]--;
		}
		else if ((qcount[2] > 0) && (qcount[3] >0))
		{
			mv_trans(game,stack_from_char(game, sortp->cstack), "r2");
			qcount[2]--;
			qcount[0]--;
		}			
		else if((qcount[2] > 0))
		{
			mv_trans(game,stack_from_char(game, sortp->cstack), "r");
			qcount[2]--;
		}	
		else if(qcount[0] >0)
		{
			mv_trans(game, stack_from_char(game, lane_swich(sortp->cstack)), "r");
		}	
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

	elements = sortp->end - sortp->start + 1;
	find_position(game, stack_from_char(game, sortp->cstack), sortp->start);
	seasons_forwardpass(game, sortp);
	seasons_backpass();
	seasons_return();
}
