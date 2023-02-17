/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:44:05 by amejia            #+#    #+#             */
/*   Updated: 2023/02/17 04:55:14 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"


void	sort_quicksort_loop(t_sort_params *sortp, long *w_piv, int *npush, \
	int *coords)
{
	int size_o;

	while (*npush <(long)w_piv[2])
	{
		size_o = ft_lstgn_size(get_node(sortp,'o',0));
		//if (*npush == 2 && l_comparison(sortp, 'o', get_node(sortp,'o',1)->content) && size_o !=2)
		// 	movement(sortp,'o',"s");
		if (!l_comparison(sortp, 'o', w_piv[1])
		  && ((*npush) + coords[1]>0) && size_o > 1)
		{
		 	if (!l_comparison(sortp, 't', w_piv[0]))
		 		coords[0]--;
		 	if (!l_comparison(sortp, 't', w_piv[0]))
		 		movement(sortp, 'o', "r2");
		 	else
		 		move_to(sortp, 'o', 1);
		 	coords[1]--;
		}
		else if (l_comparison(sortp, 't', w_piv[0]))
		{
			movement(sortp, 't', "p");
			(*npush)++;
		}
		else if (*npush < w_piv[2])
		{
			movement(sortp, 't', "r");
			coords[0]--;
		}
		else
			break ;
	}
}

void	sort_quicksort_initialize(long **sorted_list, long *w_piv, int *coords, \
	t_sort_params *sortp)
{
	int counter;

	counter = 0;
	ft_bzero(w_piv , 5 * sizeof(long));
	*sorted_list = list_from_params(sortp);
	list_qsort(*sorted_list, sortp->elements);
	w_piv[0] = (*sorted_list)[sortp->elements / 2];
	w_piv[1] = (*sorted_list)[sortp->elements / 4] * (1 + sortp->ascending) / 2 \
		- (*sorted_list)[sortp->elements * 3 / 4] * (sortp->ascending - 1) / 2;
	while(counter < sortp->elements)
	{
		if(sortp->ascending * (*sorted_list)[counter] < \
		sortp->ascending * w_piv[0])
		{
			w_piv[2]++;
			if(!(sortp->ascending * (*sorted_list)[counter] < \
				sortp->ascending * w_piv[1]))
				w_piv[3]++;
		}
		else
			w_piv[4]++;
		counter++;
	}
	coords[0] = 0;
	coords[1] = 0; 
}


void	sort_quicksort_subsorts(t_sort_params *sortp, int *coords, int npush)
{
	int				counter;
	t_sort_params	**sub_par;

	sub_par = (t_sort_params **)ft_calloc(2, sizeof(t_sort_params *));
	sub_par[0]= sort_params(sortp->cstack, coords[0], sortp->elements - npush + coords[0] -1, sortp->ascending);
	sub_par[1]= sort_params(lane_swich(sortp->cstack), coords[1], \
		npush + coords[1]	-1, -sortp->ascending);
	counter = -1;
	while (++counter < 2)
	{
		sub_par[counter]->game = sortp->game;
		sort_quicksort(sub_par[counter]);
		free(sub_par[counter]);
	}
	
	free(sub_par);
}

void	sort_quicksort_restore(t_sort_params *sortp, int npush, int *coords)
{
	move_to(sortp,'t',0*coords[0]);
	//move_to(sortp,'o',coords[1]);
	while(npush-- > 0)
		movement(sortp,'t',"u");
}

void	sort_quicksort_align(t_sort_params *sortp)
{
	t_sort_params *sort2;

	move_to(sortp,'t',sortp->start);
	sort2 = sort_params(sortp->cstack,0,sortp->elements - 1, sortp->ascending);
	sort2->game=sortp->game;
	sort_quicksort(sort2);
	free(sort2);
}


void	sort_quicksort(t_sort_params *sortp)
{
	long			*sorted_list;
	long			w_piv[5];
	int				npush;
	int				coords[2];

	if (sortp->start != 0)
	{
		sort_quicksort_align(sortp);
		return ;
	}
	if (sortp->elements <= 1)
		return ;
	if ((sortp->elements == 2) && (sortp->start == 0))
	{
		if(!l_comparison(sortp,'t', get_node(sortp,'t',1) ->content))
			movement(sortp,'t',"s");
		return ;
	}
	npush = 0;
	sort_quicksort_initialize(&sorted_list, w_piv, coords, sortp);
	sort_quicksort_loop(sortp, w_piv, &npush, coords);
	sort_quicksort_subsorts(sortp, coords, npush);
	sort_quicksort_restore(sortp, npush, coords);
	free(sorted_list);
}


