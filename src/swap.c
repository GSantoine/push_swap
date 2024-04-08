/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:04:06 by agras             #+#    #+#             */
/*   Updated: 2022/07/26 19:42:50 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

void	swap(t_list **lst)
{
	t_list	*tmp;

	if (!*lst)
		return ;
	tmp = (*lst)->next;
	tmp->prev = (*lst)->prev;
	(*lst)->next = (*lst)->next->next;
	(*lst)->prev = (*lst)->next->prev;
	(*lst)->next->prev = (*lst);
	tmp->next = (*lst);
	(*lst) = tmp;
}

void	swap_a(t_stacks *stacks)
{
	swap(&(stacks)->a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stacks *stacks)
{
	swap(&(stacks)->b);
	write(1, "sb\n", 3);
}
