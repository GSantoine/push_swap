/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:51:45 by agras             #+#    #+#             */
/*   Updated: 2022/08/02 15:29:31 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

t_stacks	*ft_init_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->tofind_len = 0;
	stacks->tomove_len = 0;
	stacks->instructions = NULL;
	return (stacks);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	if (ac > 1)
	{
		stacks = ft_init_stacks();
		if (!stacks)
			return (-1);
		if (parse_args(&(stacks->a), av + 1, ac - 1) == ERROR)
			return (exit_error(stacks));
		init_sorting(stacks);
		return (exit_success(stacks));
	}
	return (-1);
}
