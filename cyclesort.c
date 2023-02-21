/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyclesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:57:48 by amejia            #+#    #+#             */
/*   Updated: 2023/02/21 14:41:58 by amejia           ###   ########.fr       */
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
			if (get_node(sortp, 't', ct[1] + ct[0])->ordered_position == \
				ct[1] + 1)
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

void	cycle_solve_loop(t_sort_params *sortp, int *position, int *distance)
{
	if (position[1] == 1 && (get_node(sortp,'t',1)->ordered_position - \
		get_node(sortp, 't', 0)->ordered_position == -1))
	{
		movement(sortp, 't', "s");
		distance[0] = 0;
		return ;
	}
	if (position[1] == sortp->elements - 1 && (get_node(sortp,'t',0)->ordered_position - \
		get_node(sortp, 't', -1)->ordered_position == sortp->elements - 1))
	{
		movement(sortp, 't', "rr");
		movement(sortp,'t',"s");
		distance[0] = 0;
		return ;
	}
	else if (position[1] != 1)
	{
		movement(sortp, 't', "p");
		if (position[1] >= 0)
			move_to(sortp, 't', position[1] - 1);
		else
			move_to(sortp, 't', position[1]);
		movement(sortp, 't', "u");
	}
	position[1] = get_node(sortp,'t',1)->ordered_position - \
		get_node(sortp,'t', 0)->ordered_position;
	distance[0] += position[1];
	movement(sortp,'t',"r");
}


void	cycle_solve(t_sort_params *sortp, int *opt_p)
{
	int	position[2];
	int	distance[3];

	ft_bzero(distance, 3 * sizeof(int));
	while (get_node(sortp, 't', opt_p[0] + distance[2])->ordered_position == \
				distance[2] + 1)
			distance[2]++;
	position[0] = opt_p[0] + distance[2];
	position[1] = get_node(sortp, 't', position[0])->ordered_position -1 \
		- position[0];
	move_to(sortp, 't', position[0]);
	while (distance[0] != 0 || distance[1]++ == 0)
	{
		cycle_solve_loop(sortp, position, distance);
	}

}

void	sort_cyclesort(t_sort_params *sortp)
{
	int	*opt_p;

	opt_p = optimal_starting_p(sortp);
	while (opt_p[1]<sortp->elements)
	{
		cycle_solve(sortp, opt_p);
		opt_p = optimal_starting_p(sortp);
	}
	move_to(sortp,'t',opt_p[0]);
	free(opt_p);
}
