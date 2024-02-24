/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 05:11:20 by andres            #+#    #+#             */
/*   Updated: 2023/03/16 18:49:52 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	checker(t_sort_params *sortp)
{
	char	*command;
	char	*tmp;

	command = (char *)1;
	while (command != NULL)
	{	
		command = get_next_line(2);
		if (command == NULL || ft_strchr(command, '\n') == 0)
			break ;
		tmp = ft_strchr(command, '\n');
		*tmp = '\0';
		if (movement_orchestrator_2(sortp->game, command) == -1)
		{
			ft_printf("Error\n");
			return ;
		}
		if (command != NULL)
			free(command);
	}
	if (check_sorted(sortp))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
