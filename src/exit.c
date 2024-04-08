/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:59:58 by agras             #+#    #+#             */
/*   Updated: 2022/07/31 19:28:38 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

void	free_stacks(t_stacks *stacks)
{
	ft_lstclear(&(stacks->a), ft_nothing);
	ft_lstclear(&(stacks->b), ft_nothing);
	free(stacks);
}

int	exit_error(t_stacks *stacks)
{
	free_stacks(stacks);
	ft_putstr("Error\n", 2);
	return (-1);
}

int	exit_success(t_stacks *stacks)
{
	free_stacks(stacks);
	return (0);
}
