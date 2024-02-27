/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:38:24 by mlaporte          #+#    #+#             */
/*   Updated: 2023/10/28 13:54:29 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printc(va_list ap)
{
	int	count;

	count = 0;
	count += ft_putchar(va_arg(ap, int));
	return (count);
}

int	ft_printstr(va_list ap)
{
	int		count;
	char	*str;

	count = 0;
	str = va_arg(ap, char *);
	if (!str)
		count += ft_putstr("(null)");
	else
		count += ft_putstr(str);
	return (count);
}

int	ft_printptr(va_list ap)
{
	int		count;
	char	*str;

	count = 0;
	str = va_arg(ap, char *);
	if (!str)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_putnbr_base((unsigned long)str, "0123456789abcdef");
	}
	return (count);
}

int	ft_printint(va_list ap)
{
	int			count;
	long int	nbr;

	count = 0;
	nbr = va_arg(ap, int);
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr *= -1;
	}
	count += ft_putnbr(nbr);
	return (count);
}

int	ft_printuns(va_list ap)
{
	int					count;
	long unsigned int	nbr;

	count = 0;
	nbr = va_arg(ap, int);
	count += ft_putnbr(nbr);
	return (count);
}
