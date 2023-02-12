/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:33:38 by amejia            #+#    #+#             */
/*   Updated: 2023/02/12 11:17:40 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_sort_params *sort_params(char cstack, int start, int end, int ascending)
{
	t_sort_params *params;
	
	params=(t_sort_params *)ft_calloc(1,sizeof(t_sort_params));
	params->ascending=ascending;
	params->cstack=cstack;
	params->start=start;
	params->end=end;
	return (params);
}

void sort(t_game *game, t_sort_params *sortp)
{
	char	*method;
	int		elements;
	
	elements = sortp->end - sortp->start+1;
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

