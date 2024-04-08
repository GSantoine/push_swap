/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:25:32 by agras             #+#    #+#             */
/*   Updated: 2022/07/31 19:28:18 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_sign(char **nptr)
{
	if (**nptr == '-')
	{
		*nptr += 1;
		return (-1);
	}
	if (**nptr == '+')
		*nptr += 1;
	return (1);
}

void	ft_putstr(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

int	ft_atoi_check(char *nptr, long	*nb)
{
	int	is_neg;
	int	i;

	*nb = 0;
	i = 0;
	is_neg = check_sign(&nptr);
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (ERROR);
		*nb = *nb * 10 + (nptr[i] - '0');
		if (is_neg == 1 && *nb > 2147483647)
			return (ERROR);
		if (is_neg == -1 && *nb > 2147483648)
			return (ERROR);
		i++;
	}
	if (i == 0)
		return (ERROR);
	*nb = *nb * is_neg;
	return (1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}
