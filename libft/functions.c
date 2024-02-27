/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:43:01 by mlaporte          #+#    #+#             */
/*   Updated: 2023/10/28 13:55:38 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_putnbr(unsigned int nbr)
{
	int		count;

	count = 0;
	if (nbr / 10)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar((nbr % 10) + 48);
	return (count);
}

int	ft_putnbr_base(long long unsigned int nbr, char *base)
{
	int		count;

	count = 0;
	if (nbr / 16)
		count += ft_putnbr_base(nbr / 16, base);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}
