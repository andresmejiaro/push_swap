/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_orchestrator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:54:32 by amejia            #+#    #+#             */
/*   Updated: 2023/02/16 23:48:23 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	movement_orchestrator(t_game *game, char *mv)
{
	if (!ft_strncmp(mv, "pb", -1))
		pb(game);
	else if (!ft_strncmp(mv, "pa", -1))
		pa(game);
	else if (!ft_strncmp(mv, "sa", -1))
		sa(game);
	else if (!ft_strncmp(mv, "sb", -1))
		sb(game);
	else if (!ft_strncmp(mv, "ss", -1))
		ss(game);
	else if (!ft_strncmp(mv, "rb", -1))
		rb(game);
	else if (!ft_strncmp(mv, "ra", -1))
		ra(game);
	else if (!ft_strncmp(mv, "rr", -1))
		rr(game);
	else if (!ft_strncmp(mv, "rra", -1))
		rra(game);
	else if (!ft_strncmp(mv, "rrb", -1))
		rrb(game);
	else if (!ft_strncmp(mv, "rrr", -1))
		rrr(game);
	else
		return ;
	ft_printf("%s\n", mv);
	if (DEBUG)
		print_game_state(game);
}

void movement(t_sort_params *sortp, char stack, char *mv)
{
	char		temp[10];

	ft_strlcpy(temp, mv, 3);
	if (stack == 't')
		stack  = sortp ->cstack;
	else if (stack == 'o' && sortp->cstack == 'a')
		stack = 'b';
	else if (stack == 'o' && sortp->cstack == 'b')
		stack = 'a';
	else if (!(stack == 'a') || !(stack == 'b'))
		return ;
	if (!ft_strncmp(temp, "p", 2))
	{
		if (stack == 'a')
			stack = 'b';
		else if
			(stack == 'b')
			stack = 'a';
		ft_strlcat(temp, &stack, 3);
	}
	if (!ft_strncmp(temp, "r", 2) || !ft_strncmp(temp,"s",2))
		ft_strlcat(temp, &stack, 3);
	if (!ft_strncmp(temp, "u", 2))
	{
		ft_strlcpy(temp, "p", 3);
		ft_strlcat(temp, &stack, 3);
	}
	if (!ft_strncmp(temp, "rr", 3) ){
		if (!ft_strncmp(temp,"rr2",4))
			ft_strlcpy(temp,"rrr",4);
		else
			ft_strlcat(temp, &stack, 4);
	}
	if (!ft_strncmp(temp,"r2",3))
		ft_strlcpy(temp,"rr",3);
	movement_orchestrator(sortp->game, temp);
}
