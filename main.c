/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:39:34 by amejia            #+#    #+#             */
/*   Updated: 2023/02/12 19:09:59 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

#include "list_game_node_fcts2.c"
#include "random.c"
#include "game_global_manip.c"
#include "game_global_manip2.c"
#include "game_movements_push.c"
#include "game_movements_rotate.c"
#include "game_movements_reverse_rotate.c"
#include "game_movements_swap.c"
#include "list_game_node_fcts.c"
#include "quicksort.c"
#include "movement_orchestrator.c"
#include "sort.c"
#include "ft_abs.c"

int	main(int argc, char **argv)
{
	int			aux;
	t_game_node	*data;

	if (argc <= 1)
		return (0);
	aux = read_and_validate_input(argc, argv, &data);
	if (aux > 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	aux = check_uniqueness(data);
	if (aux > 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	game_start(data);
	return (0);
}

int	read_and_validate_input(int argc, char **argv, t_game_node **data)
{
	int	node_c;
	int	counter;

	if (check_valid(argc, argv) != 0)
		return (1);
	counter = 1;
	node_c = ft_atoi(argv[counter]);
	*data = ft_lstgn_new(node_c);
	while (counter++ < argc - 1)
	{
		node_c = ft_atoi(argv[counter]);
		ft_lstgn_add_back(data, ft_lstgn_new(node_c));
	}
	return (0);
}

int	check_uniqueness(t_game_node *data)
{
	t_game_node	*dataprt;

	dataprt = data->next;
	while (1)
	{
		if (data != 0 & dataprt != 0)
			if (data->content == dataprt->content)
				return (1);
		if (data->next == 0)
			break ;
		if (dataprt -> next == 0)
		{
			data = data->next;
			dataprt = data ->next;
		}
		else
			dataprt = dataprt -> next;
	}
	return (0);
}

int	check_valid(int argc, char **argv)
{
	int	i;
	int	counter;
	int	signs;

	counter = 0;
	while (counter ++ < argc -1)
	{
		i = 0;
		signs = 0;
		while (argv[counter][i] != '\0')
		{
			if (argv[counter][i++] == '+' || argv[counter][i] == '-')
				signs ++;
			else if (argv[counter][i] == ' ' || argv[counter][i] <= '9' \
				|| argv[counter][i] >= '0')
				i++;
			else
				return (1);
		}
		if (signs > 1)
			return (1);
	}
	return (0);
}
