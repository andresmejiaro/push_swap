/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_global_manip_game_structures_bonus.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:14:48 by amejia            #+#    #+#             */
/*   Updated: 2023/03/11 23:13:28 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap_bonus.h"

void	game_start(t_game_node *data)
{
	t_game			game;
	t_sort_params	*params;

	(&game)->stack_a = data;
	(&game)->stack_b = 0;
	params = sort_params('a', 0, ft_lstgn_size((&game)->stack_a) - 1, 1);
	params->game = &game;
	fill_order(params);
	checker(params);
	if (DEBUG == 1)
		print_game_state(&game);
	free(params);
	ft_lstgn_clear((&game)->stack_a);
	ft_lstgn_clear((&game)->stack_b);
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

t_game_node	*get_node(t_sort_params *sortp, char stack, int position)
{
	t_game_node	*node;
	int			stack_len;

	if (stack == 't')
		stack = sortp ->cstack;
	else if (stack == 'o' && sortp->cstack == 'a')
		stack = 'b';
	else if (stack == 'o' && sortp->cstack == 'b')
		stack = 'a';
	else if (!(stack == 'a' || stack == 'b'))
		return (0);
	if (stack == 'a')
		node = sortp->game->stack_a;
	if (stack == 'b')
		node = sortp->game->stack_b;
	stack_len = ft_lstgn_size(node);
	if (stack_len == 0)
		return (0);
	while (position < 0)
		position += stack_len;
	position = position % stack_len;
	node = ft_lstgn_nnode(node, position);
	return (node);
}

// This functions mallocs the result;
long	*list_from_params(t_sort_params *sortp)
{
	int		counter;
	long	*to_return;

	if (sortp->elements <= 0)
		return (0);
	counter = 0;
	to_return = (long *)ft_calloc(sortp->elements, sizeof(long));
	graceful_malloc_fail(to_return);
	while (counter < sortp->elements)
	{
		to_return[counter] = get_node(sortp, 't', \
			sortp->start + counter)->content;
		counter++;
	}
	return (to_return);
}
