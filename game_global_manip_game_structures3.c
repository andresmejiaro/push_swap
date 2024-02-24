/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_global_manip_game_structures3.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:15:53 by amejia            #+#    #+#             */
/*   Updated: 2023/03/11 03:19:35 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

long	get_nodec(t_sort_params *sortp, char stack, int position)
{
	return (get_node(sortp, stack, position)->content);
}

int	get_nodep(t_sort_params *sortp, char stack, int position)
{
	return (get_node(sortp, stack, position)->ordered_position);
}
