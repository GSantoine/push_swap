/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 00:28:38 by agras             #+#    #+#             */
/*   Updated: 2022/07/26 19:43:21 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

void	push(t_list **l1, t_list **l2)
{
	t_list	*tmp;

	if (!*l1)
		return ;
	tmp = *l1;
	*l1 = (*l1)->next;
	ft_lstadd_front(l2, tmp);
}

void	push_to_a(t_stacks *stacks)
{
	push(&(stacks->b), &(stacks->a));
	write(1, "pa\n", 3);
}

void	push_to_b(t_stacks *stacks)
{
	push(&(stacks->a), &(stacks->b));
	write(1, "pb\n", 3);
}
