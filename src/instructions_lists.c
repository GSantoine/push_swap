/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_lists.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:41:14 by agras             #+#    #+#             */
/*   Updated: 2022/07/26 16:59:04 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

t_instrc	*ft_instrc_new(short content)
{
	t_instrc	*new;

	new = malloc(sizeof(t_instrc));
	if (!new)
		return (NULL);
	new->label = content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ft_instr_delone(t_instrc *lst)
{
	if (!lst)
		return ;
	free(lst);
}

static t_instrc	*ft_delete_elem(t_instrc *lst)
{
	t_instrc	*tmp;

	tmp = lst->next;
	ft_instr_delone(lst);
	return (tmp);
}

void	ft_clear_instrc(t_instrc **lst)
{
	if (!*lst)
		return ;
	while (*lst)
		*lst = ft_delete_elem(*lst);
}

t_instrc	*ft_last_instrc(t_instrc *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
