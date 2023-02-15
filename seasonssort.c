/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seasonssort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:29:48 by amejia            #+#    #+#             */
/*   Updated: 2023/02/15 06:24:43 by amejia           ###   ########.fr       */
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
	long	*el_list;
	long	*qcount;
	long	*qu;
	long		count_push;
	long		count_swicho;
	long	check_t;
	long	check_o;
	long	value_t;
	long 	value_o;
	
	el_list = node_to_list(game, sortp);
	qu = list_quantiles_long(el_list, sortp->end - sortp->start + 1);
	qcount = count_quantiles_long(el_list, sortp->end - sortp->start + 1);
	section_count(&qcount, sortp);
	qu[0] = (1 + sortp->ascending) / 2 * qu[0] - (sortp->ascending - 1) * qu[3];
	
	count_push = qcount[0]+qcount[1];
	count_swicho = qcount[1];
	
	check_o = 0;
	check_t = check_o;
	
	while (1)
	{
		if (!l_check(game, sortp, 't', qu[1]) && \
			!l_check(game, sortp, 'o', qu[0]))
		{
			if(check_o == 0)
			{
				value_o = stack_from_char(game,sortp->cstack)->content;
				check_o++;
			}
			if(check_t ==0)
			{
				value_t = stack_from_char(game,sortp->cstack)->content;
				check_t++;
			}
			mv_trans_c(game,sortp,'t',"r2");
			count_swicho--;
		}
		else if (m_check(game,sortp,'o',qu[0]) && size_c(game,sortp,'o') > 1)
		{
			mv_trans_c(game, sortp, 'o', "r");
			if(check_o == 0)
			{
				value_o = stack_from_char(game,sortp->cstack)->content;
				check_o++;
			}
			count_swicho--;
		}
		else if (l_check(game, sortp, 't', qu[1]))
		{
			mv_trans_c(game, sortp, 't', "p");
			count_push--;
		}
		else if (!l_check(game, sortp, 't', qu[1]) && count_push > 0)
		{
			mv_trans_c(game, sortp, 't', "r");
			if(check_t ==0)
			{
				value_t = stack_from_char(game,sortp->cstack)->content;
				check_t++;
			}
		}
		else
			break;	
	}
	free(el_list);
	free(qu);
	free(qcount);
	find_value(game, stack_from_char(game, sortp->cstack), value_t);
	find_value(game, stack_from_char(game, lane_swich(sortp->cstack)), value_o);
	ft_qsort(game,sort_params(sortp->cstack,0,sortp->end - sortp->start - qcount[0]-qcount[1],sortp->ascending));
	ft_qsort(game,sort_params(lane_swich(sortp->cstack),0, qcount[0]+qcount[1],-sortp->ascending));
	

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
