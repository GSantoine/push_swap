/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:49:05 by agras             #+#    #+#             */
/*   Updated: 2022/07/29 17:39:58 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

t_list	*find_lowest(t_list *a, int *nb_index)
{
	int		i;
	t_list	*lowest_nb;
	int		lowest_value;

	i = 0;
	while (a)
	{
		if (i == 0)
		{
			lowest_value = a->content;
			lowest_nb = a;
			*nb_index = i;
		}
		else if (a->content < lowest_value)
		{
			lowest_value = a->content;
			lowest_nb = a;
			*nb_index = i;
		}
		i++;
		a = a->next;
	}
	return (lowest_nb);
}

void	rotate_to_top(t_stacks *prog, t_list *nb)
{
	while (nb->prev)
		rotate_a(prog);
}

void	rrotate_to_top(t_stacks *prog, t_list *nb)
{
	while (nb->prev)
		rrotate_a(prog);
}

void	simple_sort(t_stacks *prog)
{
	int		nb_index;
	t_list	*lowest_nb;

	if (ft_lstsize(prog->a) > 4)
	{
		lowest_nb = find_lowest(prog->a, &nb_index);
		if (nb_index > 2)
			rrotate_to_top(prog, lowest_nb);
		else
			rotate_to_top(prog, lowest_nb);
		push_to_b(prog);
	}
	if (ft_lstsize(prog->a) > 3)
	{
		lowest_nb = find_lowest(prog->a, &nb_index);
		if (nb_index > 1)
			rrotate_to_top(prog, lowest_nb);
		else
			rotate_to_top(prog, lowest_nb);
		push_to_b(prog);
	}
	basic_sort(prog);
	while (prog->b)
		push_to_a(prog);
}
