/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_global_manip_game_structures2.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:14:48 by amejia            #+#    #+#             */
/*   Updated: 2023/02/17 01:20:21 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	fill_order(t_sort_params *sortp)
{
	long	*elementlist;
	int		counter;
	int		counter2;

	elementlist = list_from_params(sortp);
	list_qsort(elementlist, sortp->elements);
	counter = 0;
	while (counter < sortp->elements)
	{
		counter2 = 0;
		while (counter2 < sortp -> elements)
		{
			if (get_node(sortp, 't', counter)->content \
				== elementlist[counter2])
			{
				get_node(sortp, 't',counter)->\
					ordered_position = counter2 + 1;
				break ;
			}
			counter2++;
		}		
		counter++;
	}	
	free(elementlist);
}

char	lane_swich(char c)
{
	if (c == 'a')
		return ('b');
	if (c == 'b')
		return ('a');
	if (c == 't')
		return ('o');
	if (c == 'o')
		return('t');
	return ('\0');
}

void	move_to(t_sort_params *sortp, char this, int position)
{
	t_game_node *node[2];
	int			counter[2]; 
	
	counter[0] = 0;
	counter[1] = 0;
	node[0] = get_node(sortp, this, 0);
	if(node[0] == 0)
		return ;
	node[1] = get_node(sortp, this, position);
	while(node[0] != node[1])
	{
		counter[0]++;
		node[0] = node[0]->next;
	}
	while(node[0] != 0)
	{
		counter[1]++;
		node[0] = node[0]->next;
	}
	if (counter[0] < counter[1])
		while(counter[0]-- > 0)
			movement(sortp, this, "r");
	else
		while(counter[1]-- > 0)
			movement(sortp, this, "rr");
}


