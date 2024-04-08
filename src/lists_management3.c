/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_management3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 00:59:08 by agras             #+#    #+#             */
/*   Updated: 2022/04/08 20:15:29 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

// t_list	*ft_lstmed(t_list *lst, int lst_size)
// {
// 	while ()
// }

t_list	*ft_lstnew_from(t_list *elem)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = elem->content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*dup;

	if (!lst)
		return (NULL);
	while (lst)
	{
		ft_lstadd_back(&dup, ft_lstnew_from(lst));
		lst = lst->next;
	}
	return (dup);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	new->next = NULL;
	if (!(*lst))
	{
		new->prev = NULL;
		(*lst) = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	new->prev = tmp;
	tmp->next = new;
}
