/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:03:19 by mlaporte          #+#    #+#             */
/*   Updated: 2023/10/28 13:54:37 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhexamin(va_list ap)
{
	int				count;
	unsigned int	nbr;

	nbr = va_arg(ap, int);
	count = 0;
	count += ft_putnbr_base((unsigned int)nbr, "0123456789abcdef");
	return (count);
}

int	ft_printhexamaj(va_list ap)
{
	int				count;
	unsigned int	nbr;

	nbr = va_arg(ap, int);
	count = 0;
	count += ft_putnbr_base((unsigned int)nbr, "0123456789ABCDEF");
	return (count);
}

int	ft_printpercent(va_list ap)
{
	int	count;

	count = 0;
	(void)ap;
	count += ft_putchar('%');
	return (count);
}
