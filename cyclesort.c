/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyclesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:57:48 by amejia            #+#    #+#             */
/*   Updated: 2023/02/22 07:34:52 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

// This mallocs the result
// return pos at 0 value at 1
int	*optimal_starting_p(t_sort_params *sortp)
{
	int	*max;
	int	ct[3];

	max = ft_calloc(2, sizeof(int));
	graceful_malloc_fail(max);
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

void	cycle_solve_loop_sub(t_sort_params *sortp, int *position, int *distance)
{
	if (position[1] == sortp->elements - 1 && (get_node(sortp, 't', 0)-> \
		ordered_position - get_node(sortp, 't', -1)->ordered_position == \
		sortp->elements - 1))
	{
		movement(sortp, 't', "rr");
		movement(sortp, 't', "s");
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
}

void	cycle_solve_loop(t_sort_params *sortp, int *position, int *distance)
{
	if (position[1] == 1 && (get_node(sortp, 't', 1)->ordered_position - \
		get_node(sortp, 't', 0)->ordered_position == -1))
	{
		movement(sortp, 't', "s");
		distance[0] = 0;
		return ;
	}
	cycle_solve_loop_sub(sortp, position, distance);
	position[1] = get_node(sortp, 't', 1)->ordered_position - \
		get_node(sortp, 't', 0)->ordered_position;
	distance[0] += position[1];
	movement(sortp, 't', "r");
}
