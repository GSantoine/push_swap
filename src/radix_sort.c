/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:50:17 by agras             #+#    #+#             */
/*   Updated: 2022/07/26 17:25:32 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

long	get_absolute(int nb)
{
	if (nb < 0)
		return (-((long)nb));
	return ((long)nb);
}

int	get_nb_binary_len(long nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		len++;
		nb /= 2;
	}
	return (len);
}

int	is_sorted(t_list *stack)
{
	while (stack)
	{
		if (stack->prev)
			if (stack->content < stack->prev->content)
				return (0);
		stack = stack->next;
	}
	return (1);
}

void	radix_sort(t_stacks *prog, int max_digits)
{
	int	i;
	int	j;
	int	stack_size;

	i = 0;
	stack_size = ft_lstsize(prog->a);
	while (i < max_digits && !is_sorted(prog->a))
	{
		j = 0;
		while (j < stack_size)
		{
			if (((prog->a->place >> i) & 1) == 1)
				rotate_a(prog);
			else
				push_to_b(prog);
			j++;
		}
		while (prog->b)
			push_to_a(prog);
		i++;
	}
}

int	is_ordered(t_list *stack)
{
	while (stack)
	{
		if (stack->place == -1)
			return (0);
		stack = stack->next;
	}
	return (1);
}
