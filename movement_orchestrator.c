/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_orchestrator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:54:32 by amejia            #+#    #+#             */
/*   Updated: 2023/02/15 05:59:59 by amejia           ###   ########.fr       */
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

void	mv_trans(t_game *game, t_game_node *stack, char *mv)
{
	char	cstack[3];
	char	temp[10];

	ft_strlcpy(temp, mv, 3);
	if (game->stack_a == stack)
		ft_strlcpy(cstack, "ab", 3);
	else if (game->stack_b == stack)
		ft_strlcpy(cstack, "ba", 3);
	if (!ft_strncmp(temp, "p", 2))
		ft_strlcat(temp, &cstack[1], 3);
	if (!ft_strncmp(temp, "r", 2))
		ft_strlcat(temp, &cstack[0], 3);
	if (!ft_strncmp(temp, "u", 2))
	{
		ft_strlcpy(temp, "p", 3);
		ft_strlcat(temp, &cstack[0], 3);
	}
	if (!ft_strncmp(temp, "rr", 3))
		ft_strlcat(temp, &cstack[0], 4);
	if (!ft_strncmp(temp,"r2",3))
		ft_strlcpy(temp,"rr",3);
	movement_orchestrator(game, temp);
}

void	mv_trans_c(t_game *game, t_sort_params *sortp, char this, char *mv)
{
	if (this == 't')
		mv_trans(game, stack_from_char(game, sortp->cstack), mv);
	if (this == 'o')
		mv_trans(game, stack_from_char(game, lane_swich(sortp->cstack)), mv);
}

long	value_c(t_game *game, t_sort_params *sortp, char this)
{
	long	r;

	r = 0;
	if (this == 't' && size_c(game, sortp, 't') > 0)
		r = stack_from_char(game, sortp->cstack)->content;
	if (this == 'o' && size_c(game, sortp, 'o') > 0)
		r = stack_from_char(game, lane_swich(sortp->cstack))->content;
	return (r);
}
