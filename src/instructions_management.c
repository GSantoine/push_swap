/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:50:17 by agras             #+#    #+#             */
/*   Updated: 2022/07/26 17:16:17 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

t_instrc	*new_instrc(int label)
{
	t_instrc	*new;

	new = malloc(sizeof(t_instrc));
	if (!new)
		return (NULL);
	new->label = label;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	add_instrc_front(t_instrc **lst, t_instrc *new)
{
	if (!new)
		return ;
	new->prev = NULL;
	if (!(*lst))
	{
		new->next = NULL;
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

t_instrc	*get_last_instrc(t_instrc *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_instrc_back(t_instrc **lst, t_instrc *new)
{
	t_instrc	*tmp;

	if (!new)
		return ;
	new->next = NULL;
	if (!(*lst))
	{
		new->prev = NULL;
		(*lst) = new;
		return ;
	}
	tmp = get_last_instrc(*lst);
	new->prev = tmp;
	tmp->next = new;
}
