/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:44:05 by amejia            #+#    #+#             */
/*   Updated: 2023/02/19 21:36:37 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	sort_quicksort_loop(t_sort_params *sortp, long *w_piv, int *npush, \
	int *coords)
{
	if (!l_comparison(sortp, 'o', w_piv[1]) && ((*npush) + coords[1] > 0) \
		&& ft_lstgn_size(get_node(sortp, 'o', 0)) > 1)
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
	else if (npush[1]++ > 0)
		return (0);
	return (1);
}

void	sort_quicksort_initialize(long **sorted_list, long *w_piv, int *coords, \
	t_sort_params *sortp)
{
	int	counter;

	counter = 0;
	ft_bzero(w_piv, 5 * sizeof(long));
	*sorted_list = list_from_params(sortp);
	list_qsort(*sorted_list, sortp->elements);
	w_piv[0] = (*sorted_list)[sortp->elements / 2];
	w_piv[1] = (*sorted_list)[sortp->elements / 4] * (1 + sortp->ascending) / 2 \
		- (*sorted_list)[sortp->elements * 3 / 4] * (sortp->ascending - 1) / 2;
	while (counter < sortp->elements)
	{
		if (sortp->ascending * (*sorted_list)[counter] < \
			sortp->ascending * w_piv[0])
		{
			w_piv[2]++;
			if (!(sortp->ascending * (*sorted_list)[counter] < \
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
	int 			set_back;

	sub_par = (t_sort_params **)ft_calloc(2, sizeof(t_sort_params *));
	sub_par[0] = sort_params(sortp->cstack, coords[0], sortp->elements - npush \
		+ coords[0] -1, sortp->ascending);
	sub_par[1] = sort_params(lane_swich(sortp->cstack), 0, \
		npush + coords[1] - 1, -sortp->ascending);
	sub_par[2] = sort_params(lane_swich(sortp->cstack), coords[1], \
			- 1, -sortp->ascending);
	set_back = get_node(sortp, 'o', 0)->content;
	counter = -1;
	while (++counter < 3)
	{
		sub_par[counter]->game = sortp->game;
		if (counter == 1)
			move_to(sortp, 'o', find_value(sortp, 'o', set_back));
		sort(sub_par[counter]);
		free(sub_par[counter]);
	}
	free(sub_par);
}

void	sort_quicksort_restore(t_sort_params *sortp, int npush, int *coords)
{
	move_to(sortp, 't', 0 * coords[0]);
	while (npush-- > 0)
		movement(sortp, 't', "u");
}

void	sort_quicksort(t_sort_params *sortp)
{
	long			*sorted_list;
	long			w_piv[5];
	int				np[3];
	int				coords[2];

	if (sortp->elements <= 1)
		return ;
	if (sortp->start != 0)
	{
		sort_quicksort_align(sortp);
		return ;
	}
	if ((sortp->elements == 2) && (sortp->start == 0))
	{
		if (!l_comparison(sortp, 't', get_node(sortp, 't', 1)->content))
			movement(sortp, 't', "s");
		return ;
	}
	ft_bzero(np, 3 * sizeof(long));
	sort_quicksort_initialize(&sorted_list, w_piv, coords, sortp);
	while ((*np < (int)w_piv[2] || - coords[1] < w_piv[3]) && !np[2])
		np[2] = 1 - sort_quicksort_loop(sortp, w_piv, np, coords);
	sort_quicksort_subsorts(sortp, coords, *np);
	sort_quicksort_restore(sortp, *np, coords);
	free(sorted_list);
}
