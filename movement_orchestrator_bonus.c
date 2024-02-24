/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_orchestrator_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:54:32 by amejia            #+#    #+#             */
/*   Updated: 2023/03/12 01:07:47 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	move_orchestrator_print(t_game *game, char *mv)
{
	ft_printf("%s\n", mv);
	if (DEBUG)
		print_game_state(game);
}

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
	move_orchestrator_print(game, mv);
}

void	movement(t_sort_params *sortp, char stack, char *mv)
{
	char		temp[10];

	ft_strlcpy(temp, mv, ft_strlen(mv)+1);
	if (stack == 't')
		stack = sortp ->cstack;
	else if (stack == 'o')
		stack = lane_swich(sortp->cstack);
	if (!ft_strncmp(temp, "p", 2))
		stack = lane_swich(stack);
	if (!ft_strncmp(temp, "r", 2) || !ft_strncmp(temp, "s", 2) || \
			!ft_strncmp(temp, "p", 2))
		ft_strlcat(temp, &stack, 3);
	if (!ft_strncmp(temp, "u", 2))
		movement(sortp, lane_swich(stack), "p");
	if (!ft_strncmp(temp, "rr", 3))
		ft_strlcat(temp, &stack, 4);
	if (!ft_strncmp(temp, "r2", 3))
		ft_strlcpy(temp, "rr", 3);
	if (!ft_strncmp(temp, "rr2", 4))
		ft_strlcpy(temp, "rrr", 4);
	movement_orchestrator(sortp->game, temp);
}

void	movement2(t_sort_params *sortp, char stack, char *mv)
{
	if (!ft_strncmp(mv, "r", 2) && \
		(ft_lstgn_size(get_node(sortp, stack, 0)) <= 1))
		return ;
	if (!ft_strncmp(mv, "rr", 3) && ft_strncmp(mv, "rr2", 4) && \
		(ft_lstgn_size(get_node(sortp, stack, 0)) <= 1))
		return ;
	movement(sortp, stack, mv);
}

int	movement_orchestrator_2(t_game *game, char *mv)
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
		return (-1);
	return (0);
}
