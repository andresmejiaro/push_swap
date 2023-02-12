/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_global_manip.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:14:48 by amejia            #+#    #+#             */
/*   Updated: 2023/02/12 07:58:09 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	game_start(t_game_node *data)
{
	t_game			*game;
	t_sort_params	*params;

	game = malloc(sizeof(t_game));
	game->stack_a = data;
	game->stack_b = 0;
	params=sort_params('a',0,ft_lstgn_size(game->stack_a)-1,1);
	sort(game, params);
	free(params);
	print_game_state(game);
}

void print_one(int content)
{
	ft_printf("%i,",content);
}

void print_game_state(t_game *game)
{
	ft_lstgn_iter(game->stack_a, print_one);
	ft_printf("\n");
	ft_lstgn_iter(game->stack_b, print_one);
	ft_printf("\n");
}
