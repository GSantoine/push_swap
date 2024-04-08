/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_list2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:52:33 by agras             #+#    #+#             */
/*   Updated: 2022/04/11 12:04:43 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

void	add_instruction(t_instrc **instructions, short label)
{
	t_instrc	*new;

	if (!*instructions)
		return ;
	if ((*instructions)->next)
	{
		*instructions = (*instructions)->next;
		(*instructions)->label = label;
	}
	else
	{
		new = ft_instrc_new(label);
		if (!*instructions)
		{
			*instructions = new;
			return ;
		}
		new->prev = *instructions;
		(*instructions)->next = new;
	}
}
