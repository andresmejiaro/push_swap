/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_game_node_fcts_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:47:07 by amejia            #+#    #+#             */
/*   Updated: 2023/03/11 23:16:03 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_game_node	*ft_lstgn_new(int content)
{
	t_game_node	*to_return;

	to_return = (t_game_node *)malloc(sizeof(t_game_node));
	if (to_return == 0)
		return (0);
	to_return->content = content;
	to_return->next = 0;
	return (to_return);
}

void	ft_lstgn_add_back(t_game_node **lst, t_game_node *new)
{
	t_game_node	*mover;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	mover = *lst;
	while (mover->next != NULL)
		mover = mover -> next;
	mover->next = new;
}

void	ft_lstgn_iter(t_game_node *lst, void (*f)(int))
{
	if (lst == 0)
		return ;
	while (1)
	{
		(*f)(lst->content);
		if (lst -> next == 0)
			break ;
		lst = lst->next;
	}	
}

void	ft_lstgn_add_front(t_game_node **lst, t_game_node *new)
{
	new->next = *lst;
	*lst = new;
}
