/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:28:39 by agras             #+#    #+#             */
/*   Updated: 2022/08/02 15:29:58 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

int	atoi_lst(t_list **stack, char **av)
{
	int		i;
	long	nb;

	i = 0;
	while (av[i])
	{
		if (av[i])
		{
			if (!ft_atoi_check(av[i], &nb))
				return (ERROR);
			if (ft_lstsearch(*stack, nb))
				return (ERROR);
			ft_lstadd_back(stack, ft_lstnew((int)nb));
		}
		i++;
	}
	return (1);
}

void	free_arg(char **arg)
{
	int	i;

	if (!arg)
		return ;
	i = 0;
	while (arg[i])
	{
		if (arg[i])
			free(arg[i]);
		i++;
	}
	free(arg);
}

int	is_arg_empty(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			return (0);
		i++;
	}
	return (1);
}

int	parse_args(t_list **stack, char **av, int size)
{
	int		i;
	char	**numbers;

	i = 0;
	while (i < size)
	{
		if (av[i])
		{
			if (is_arg_empty(av[i]))
				return (ERROR);
			numbers = ft_split(av[i], ' ');
			if (!numbers)
				return (ERROR);
			if (atoi_lst(stack, numbers) == ERROR)
			{
				free_arg(numbers);
				return (ERROR);
			}
			free_arg(numbers);
		}
		i++;
	}
	return (1);
}
