/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:42:18 by loamar            #+#    #+#             */
/*   Updated: 2021/08/30 23:45:19 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int     ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int     ft_atoi(const char *str)
{
	long	i;
	long	sign;
	long	res;

	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	res = 0;
	while (str[i] != '\0' && ft_isdigit(str[i]) != 0)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s++);
	}
}
