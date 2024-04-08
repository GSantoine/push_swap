/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:28:44 by agras             #+#    #+#             */
/*   Updated: 2022/07/26 19:43:06 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

void	rrotate(t_list **lst)
{
	t_list	*tmp;

	tmp = ft_lstlast(*lst);
	tmp->prev->next = NULL;
	ft_lstadd_front(lst, tmp);
}

void	rrotate_a(t_stacks *stacks)
{
	rrotate(&(stacks)->a);
	write(1, "rra\n", 4);
}

void	rrotate_b(t_stacks *stacks)
{
	rrotate(&(stacks)->b);
	write(1, "rrb\n", 4);
}
