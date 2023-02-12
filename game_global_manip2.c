t_game_node	*stack_from_char(t_game *game, char c)
{
	if (c == 'a')
		return (game->stack_a);
	if (c == 'b')
		return (game->stack_b);
	return(0);
}

char lane_swich(char c)
{
	if (c == 'a')
		return ('b');
	if (c == 'b')
		return ('a');
}
void	find_value(t_game *game, t_game_node *stack, int value)
{
	int         counter[2];
	t_game_node	*middle;

	middle = stack;
	counter[0] = 0;
	counter[1] = 0;
	// while (middle->content != value && middle->next != 0)
	// {
	// 	counter[0]++;
	// 	middle = middle->next;
	// }
	// while (middle->next != 0 )
	// {
	// 	counter[1]++;
	// 	middle = middle->next;
	// }
    while (middle->next != 0)
	{
		if (middle->content == value || counter[1] >0)
            counter[1]++;
        else
            counter[0]++;
		middle = middle->next;
	}
    counter[1]++;
	if (counter[1] == 0)
		return ;
	if (counter[0] < counter[1])
		while (counter[0]-- > 0)
			movement_translator(game, stack, "r");
	else
		while (counter[1]-- > 0)
			movement_translator(game, stack, "rr");
}

void	find_position(t_game *game, t_game_node *stack, int position)
{
	int 		counter;
	t_game_node	*middle;

	middle = stack;
	counter = 0;
	while (counter < position)
	{
		counter++;
		middle = middle->next;
	}
	counter = 0;
	while (middle->next != 0)
	{
		counter ++;
		middle = middle->next;
	}
	if (position < counter)
		while (position-- > 0)
			movement_translator(game, stack, "r");
	else
		while (counter-- > 0)
			movement_translator(game, stack, "rr");
}
