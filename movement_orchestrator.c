/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_orchestrator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:54:32 by amejia            #+#    #+#             */
/*   Updated: 2023/02/12 12:14:12 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void movement_orchestrator(t_game *game,char *mv)
{
	if (!ft_strncmp(mv,"pb",-1))
		pb(game);
	else if (!ft_strncmp(mv,"pa",-1))
		pa(game);
	else if (!ft_strncmp(mv,"sa",-1))
		sa(game);
	else if (!ft_strncmp(mv,"sb",-1))
		sb(game);	
	else if (!ft_strncmp(mv,"ss",-1))
		ss(game);
	else if (!ft_strncmp(mv,"rb",-1))
		rb(game);
	else if (!ft_strncmp(mv,"ra",-1))
		ra(game);
	else if (!ft_strncmp(mv,"rr",-1))
		rr(game);
	else if (!ft_strncmp(mv,"rra",-1))
		rra(game);
	else if (!ft_strncmp(mv,"rrb",-1))
		rrb(game);
	else if (!ft_strncmp(mv,"rrr",-1))
		rrr(game);
	else
		return ; 
	ft_printf("%s\n", mv);
	//print_game_state(game);
}

void	movement_translator(t_game *game, t_game_node *stack, char *mv)
{
	char	cstack[2];
	char	temp[10];
	
	ft_strlcpy(temp,mv,3);
	if (game->stack_a == stack)
		ft_strlcpy(cstack,"ab",3);
	else if (game->stack_b == stack)
		ft_strlcpy(cstack,"ba",3);	
	if (!ft_strncmp(temp,"p",2))
	{
		ft_strlcat(temp,&cstack[1],3);
		movement_orchestrator(game, temp);
	}
	if (!ft_strncmp(temp,"r",2) || !ft_strncmp(temp,"s",2))
	{
		ft_strlcat(temp, &cstack[0], 3);
		movement_orchestrator(game, temp);
	}
	if (!ft_strncmp(temp,"u",2))
	{
		ft_strlcpy(temp,"p",3);
		ft_strlcat(temp, &cstack[0], 3);
		movement_orchestrator(game, temp);
	}
	if (!ft_strncmp(temp,"rr",3))
	{
		ft_strlcat(temp, &cstack[0], 4);
		movement_orchestrator(game, temp);
	}
}

