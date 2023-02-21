/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyclesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:57:48 by amejia            #+#    #+#             */
/*   Updated: 2023/02/20 04:24:22 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

// This mallocs the result
// return pos at 0 value at 1
int	*optimal_starting_p(t_sort_params *sortp)
{
	int	*max;
	int ct[3];

	max = ft_calloc(2, sizeof(int));
	ft_bzero(ct, 3 * sizeof(int));
	while (ct[0] < sortp->elements)
	{
		ct[1] = 0;
		ct[2] = 0;
		while (ct[1] < sortp->elements)
		{
			if (get_node(sortp,'t',ct[1] + ct[0])->ordered_position == ct[1]+1)
				ct[2]++;
			ct[1]++;
		}
		if (ct[2] > max[1])
		{
			max[1] = ct[2];
			max[0] = ct[0];
		}
		ct[0]++;
	}
	return (max);
}

int	check_in_cicles(int **cicles, int value)
{
	int	counter;

	while (*cicles != 0)
	{
		counter = 0;
		while ((*cicles)[counter] != 0)
		{
			if ((*cicles)[counter] == value)
				return (1);
			counter++;
		}
		cicles++;
	}
	return (0);
}

void	free_cicles(int **cicles)
{
	int	**original;

	original = cicles;
	while (*cicles != 0)
	{
		free(*cicles);
		cicles++;
	}
	free(original);
}

//this function mallocs
int	add_cicle(t_sort_params *sortp, int **cicles, int value_added, \
	int cicle_start)
{
	int	ct[3];
	int	position;

	ft_bzero(ct,3 * sizeof(int));
	while (*(cicles + ct[1]) != 0)
		ct[1]++;
	position = value_added;
	while (get_node(sortp,'t',cicle_start + position)->ordered_position  != \
		value_added + 1)
	{
		ct[0]++;
		position = get_node(sortp, 't', cicle_start + position)->ordered_position - 1;
	}	
	cicles[ct[1]] = ft_calloc(ct[0] + 2, sizeof(int));
	cicles[ct[1]][ct[0]+1] = -1;
	if (*cicles == 0)
	{
		free_cicles(cicles);
		return (0);
	}
	position = value_added;
	while (ct[2] <= ct[0])
	{
		cicles[ct[1]][ct[2]] = position;
		position = get_node(sortp, 't', cicle_start + position )->ordered_position - 1;
		ct[2]++;
	}	
	return (1);
}

//this mallocs the result
int	**get_non_trivial_cicles(t_sort_params *sortp)
{
	int	*opt_p;
	int	**cicles;
	int	ct[3];

	opt_p = optimal_starting_p(sortp);
	ft_bzero(ct, 3 * sizeof(int));
	cicles = ft_calloc(sortp->elements - opt_p[1],sizeof(int *));
	if (opt_p[1] == sortp->elements)
	{
		free(opt_p);
		return (cicles);
	}
	if (cicles == 0)
		return (0);
	while (1)
	{
		if (get_node(sortp,'t', opt_p[0] + ct[0])->ordered_position != ct[0]+1 && \
				!check_in_cicles(cicles, ct[0]))
			{
				add_cicle(sortp, cicles, ct[0], opt_p[0]);
				break;
			}
		ct[0]++;
	}
	free(opt_p);
	return (cicles);
}

void	cycle_solve(t_sort_params *sortp, int *cycle,int *opt_p)
{
	int ct;
	
	move_to(sortp, 't',opt_p[0]+cycle[0]);
	ct = 0;
	while (cycle[ct+1] >=  0)
	{
		if(cycle[ct+1]-cycle[ct] == 1)
		{
			movement(sortp,'t',"s");
			if (ct == 0 && cycle[2] < 0)
				return;
			cycle[ct+1] = cycle[ct];
			
		}
		else
		{
			movement(sortp,'t',"p");
			if (cycle[ct+1]-cycle[ct] < 0)			
				move_to(sortp,'t',cycle[ct]-cycle[ct -1]);
			else
				move_to(sortp,'t',cycle[ct]-cycle[ct -1]-1);
			movement(sortp,'t',"u");
		}
	ct++; 
	}
	if(cycle[0]-cycle[ct] == 1)
	{
		movement(sortp,'t',"s");
		cycle[ct+1] = cycle[ct];
	}
	else
	{
		movement(sortp,'t',"p");
		if (cycle[ct]-cycle[ct -1] < 0)			
			move_to(sortp,'t',cycle[ct]-cycle[ct -1]);
		else
			move_to(sortp,'t',cycle[ct]-cycle[ct -1]-1);
		movement(sortp,'t',"u");
	}
}

void	sort_cyclesort(t_sort_params *sortp)
{
	int	**cicles;
	int	*opt_p;

	opt_p = optimal_starting_p(sortp);
	while (opt_p[1]<sortp->elements)
	{
		
		cicles = get_non_trivial_cicles(sortp);
		cycle_solve(sortp,*cicles, opt_p);
		free(opt_p);	
		free(cicles);
		opt_p = optimal_starting_p(sortp);
	}
	move_to(sortp,'t',opt_p[0]);
	free(opt_p);
}
