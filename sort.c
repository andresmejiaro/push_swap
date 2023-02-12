/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:33:38 by amejia            #+#    #+#             */
/*   Updated: 2023/02/12 16:43:20 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_sort_params	*sort_params(char cstack, int start, int end, int ascending)
{
	t_sort_params	*params;

	params = (t_sort_params *)ft_calloc(1, sizeof(t_sort_params));
	params->ascending = ascending;
	params->cstack = cstack;
	params->start = start;
	params->end = end;
	return (params);
}

void	call_sort(char cstack, int start, int end, int ascending)
{
	t_sort_params	*params;
	t_game			*game;

	game = ref_to_game(NULL);
	params = sort_params(cstack, start, end, ascending);
	sort(game, params);
	free(params);
}

void	sort(t_game *game, t_sort_params *sortp)
{
	char	*method;
	int		elements;

	elements = sortp->end - sortp->start + 1;
	if (elements <= 1)
		return ;
	method = sort_chooser(game, sortp);
	if (!ft_strncmp(method, "qs", -1))
		ft_qsort(game, sortp);
}

char	*sort_chooser(t_game *game, t_sort_params *sortp)
{
	return ("qs");
}
