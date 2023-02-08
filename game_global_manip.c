/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_global_manip.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:14:48 by amejia            #+#    #+#             */
/*   Updated: 2023/02/08 15:43:48 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	game_start(t_list *data)
{
	t_game	*game;

	game->stack_a = data;
	game->stack_b = 0;
	print_game_state(game);
	sa(game);
	print_game_state(game);
}

void print_one(void *content)
{
	ft_printf("%i,",*(int *)content);
}

void print_game_state(t_game *game)
{
	ft_lstiter(game->stack_a, print_one);
	ft_printf("\n");
	ft_lstiter(game->stack_b, print_one);
	ft_printf("\n");
}
