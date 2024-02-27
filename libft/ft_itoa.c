/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:15:13 by mlaporte          #+#    #+#             */
/*   Updated: 2023/05/16 11:14:50 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int		size;

	size = 1;
	if (n < 0)
		size++;
	while (n / 10 != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	int		sign;
	char	*nbr;

	sign = 1;
	size = ft_size(n);
	nbr = malloc((size + 1) * sizeof(char));
	if (!nbr)
		return (0);
	nbr[size] = '\0';
	if (n == 0)
		nbr[0] = '0';
	if (n < 0)
		sign = -1;
	size--;
	while (n)
	{
		*(nbr + size) = sign * (n % 10) + '0';
		size--;
		n /= 10;
	}
	if (sign < 0)
		nbr[0] = '-';
	return (nbr);
}
