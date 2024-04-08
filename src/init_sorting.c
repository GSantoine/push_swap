/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:53:02 by agras             #+#    #+#             */
/*   Updated: 2022/07/29 17:38:32 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

int	get_max_nb_len(t_list *stack)
{
	t_list	*biggest_nb;

	if (!stack)
		return (-1);
	biggest_nb = stack;
	while (stack)
	{
		if (get_absolute(stack->content) > get_absolute(biggest_nb->content))
			biggest_nb = stack;
		stack = stack->next;
	}
	return (get_nb_binary_len(get_absolute(biggest_nb->content)));
}

void	set_numbers_order(t_list *stack)
{
	int		place;
	t_list	*stack_start;
	t_list	*lowest;

	place = 0;
	stack_start = stack;
	while (!is_ordered(stack_start))
	{
		stack = stack_start;
		lowest = NULL;
		while (stack)
		{
			if (stack->place == -1)
			{
				if (!lowest)
					lowest = stack;
				else if (stack->content < lowest->content)
					lowest = stack;
			}
			stack = stack->next;
		}
		lowest->place = place;
		place++;
	}
}

void	init_sorting(t_stacks *prog)
{
	if (is_sorted(prog->a))
		return ;
	if (ft_lstsize(prog->a) <= 5)
	{
		simple_sort(prog);
		return ;
	}
	set_numbers_order(prog->a);
	radix_sort(prog, get_max_nb_len(prog->a));
}
