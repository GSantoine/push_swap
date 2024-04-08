/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:54:47 by agras             #+#    #+#             */
/*   Updated: 2022/07/26 19:43:13 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

void	rotate(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	if (*lst)
		(*lst)->prev = NULL;
	ft_lstadd_back(lst, tmp);
}

void	rotate_a(t_stacks *stacks)
{
	rotate(&(stacks)->a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stacks *stacks)
{
	rotate(&(stacks)->b);
	write(1, "rb\n", 3);
}
