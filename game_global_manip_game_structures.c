/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_global_manip.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:14:48 by amejia            #+#    #+#             */
/*   Updated: 2023/02/14 17:03:12 by amejia           ###   ########.fr       */
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
	ref_to_game(game);
	params = sort_params('a', 0, ft_lstgn_size(game->stack_a) - 1, 1);
	sort(game, params);
	free(params);
	if (DEBUG ==1)
		print_game_state(game);
}

void	print_one(int content)
{
	ft_printf("%i,", content);
}

void	print_game_state(t_game *game)
{
	ft_lstgn_iter(game->stack_a, print_one);
	ft_printf("\n");
	ft_lstgn_iter(game->stack_b, print_one);
	ft_printf("\n");
}

t_game	*ref_to_game(t_game *game)
{
	static t_game	*svgame;

	if (game == 0)
		return (svgame);
	svgame = game;
	return (game);
}

long	*node_to_list(t_game *game, t_sort_params *sortp)
{
	size_t 		elements; 
	long		*to_return;
	size_t		counter;
	t_game_node *node;

	elements = sortp->end - sortp->start + 1;
	to_return = (long *)ft_calloc(elements, sizeof(long));
	counter = sortp ->start;
	node = stack_from_char(game, sortp->cstack);
	while (counter-- > 0)
		node = node->next;
	counter = 0;
	while (counter < elements)
	{
		*(to_return+counter) = node->content;
		node = node->next;
		counter++;
	}
	return (to_return);
}
