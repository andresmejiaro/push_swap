/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_insertionsort4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 04:28:47 by andres            #+#    #+#             */
/*   Updated: 2023/03/11 04:48:52 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_places_2_assign(t_sort_params *sortp, int from, int to, \
								int *fromb_tob)
{
	if (from < 0)
	{
		fromb_tob[0] = ft_abs(from);
		fromb_tob[1] = ft_lstgn_size(get_node(sortp, 'o', 0)) - fromb_tob[0];
	}
	else
	{
		fromb_tob[1] = ft_abs(from);
		fromb_tob[0] = ft_lstgn_size(get_node(sortp, 'o', 0)) - fromb_tob[1];
	}
	if (to < 0)
	{
		fromb_tob[2] = ft_abs(to);
		fromb_tob[3] = ft_lstgn_size(get_node(sortp, 't', 0)) - fromb_tob[2];
	}
	else
	{	
		fromb_tob[3] = ft_abs(to);
		fromb_tob[2] = ft_lstgn_size(get_node(sortp, 't', 0)) - fromb_tob[3];
	}
}

int	sort_ninsertionsort_realcount(t_sort_params *sortp, int from, int to)
{
	int	fromb_tob[4];
	int	way[3];

	push_places_2_assign(sortp, from, to, fromb_tob);
	push_places_2_way(fromb_tob, way);
	return (ft_min(ft_min(way[0], way[1]), way[2]));
}

void	push_places_2_way_conc_neg(t_sort_params *sortp, int *fromb_tob)
{
	while (fromb_tob[1] > 0 && fromb_tob[3] > 0)
	{
		movement2(sortp, 't', "r2");
		fromb_tob[1]--;
		fromb_tob[3]--;
	}
	while (fromb_tob[1]-- > 0)
		movement2(sortp, 'o', "r");
	while (fromb_tob[3]-- > 0)
		movement2(sortp, 't', "r");
}

void	push_places_2_way_conc_pos(t_sort_params *sortp, int *fromb_tob)
{
	while (fromb_tob[0] > 0 && fromb_tob[2] > 0)
	{	
		movement2(sortp, 't', "rr2");
		fromb_tob[0]--;
		fromb_tob[2]--;
	}
	while (fromb_tob[0]-- > 0)
		movement2(sortp, 'o', "rr");
	while (fromb_tob[2]-- > 0)
		movement2(sortp, 't', "rr");
}

//fromb_tob[0] from left direction
//fromb_tob[1] from right direction
//fromb_tob[2] to	 left direction
//fromb_tob[3] to	 right direction
void	push_places_2(t_sort_params *sortp, int from, int to)
{
	int	fromb_tob[4];
	int	way[3];

	push_places_2_assign(sortp, from, to, fromb_tob);
	push_places_2_way(fromb_tob, way);
	if (way[2] < way[0] && way[2] < way[1] && fromb_tob[0] + fromb_tob[3] < \
		fromb_tob[1] + fromb_tob[2])
	{
		move_to(sortp, 'o', -fromb_tob[0]);
		move_to(sortp, lane_swich('o'), fromb_tob[3]);
		movement(sortp, 'o', "p");
		return ;
	}
	else if (way[2] < way[0] && way[2] < way[1])
	{
		move_to(sortp, 'o', fromb_tob[1]);
		move_to(sortp, lane_swich('o'), -fromb_tob[2]);
	}
	else if (way[1] < way[0])
		push_places_2_way_conc_neg(sortp, fromb_tob);
	else
		push_places_2_way_conc_pos(sortp, fromb_tob);
	movement(sortp, 'o', "p");
}
