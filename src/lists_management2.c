/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_management2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 20:02:57 by agras             #+#    #+#             */
/*   Updated: 2022/07/26 19:42:57 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

void	ft_nothing(int content)
{
	if (content > 0)
		return ;
	return ;
}

void	ft_lstprint_int(int content)
{
	ft_putnbr_fd(content, 1);
}

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

static t_list	*ft_delete_elem(t_list *lst, void (*del)(int))
{
	t_list	*tmp;

	tmp = lst->next;
	ft_lstdelone(lst, del);
	return (tmp);
}

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	if (!*lst)
		return ;
	while (*lst)
		*lst = ft_delete_elem(*lst, del);
}
