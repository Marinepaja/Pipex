/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:36:39 by mlaporte          #+#    #+#             */
/*   Updated: 2023/12/11 14:17:53 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(const char *str, char c)
{
	int		count;

	count = 0;
	while (*str)
	{
		if (*str == c && *(str + 1))
		{
			count++;
			str++;
		}
		str++;
	}
	return (count);
}

size_t	check_format(const char *str)
{
	if (*str == 'c')
		return (0);
	else if (*str == 's')
		return (1);
	else if (*str == 'p')
		return (2);
	else if (*str == 'd' || *str == 'i' )
		return (3);
	else if (*str == 'u')
		return (4);
	else if (*str == 'x')
		return (5);
	else if (*str == 'X')
		return (6);
	else if (*str == '%')
		return (7);
	return (-1);
}

size_t	printf_format(const char *str, va_list ap)
{
	int		(*tab[8])(va_list);
	size_t	format;

	format = check_format(str);
	tab[0] = &ft_printc;
	tab[1] = &ft_printstr;
	tab[2] = &ft_printptr;
	tab[3] = &ft_printint;
	tab[4] = &ft_printuns;
	tab[5] = &ft_printhexamin;
	tab[6] = &ft_printhexamaj;
	tab[7] = &ft_printpercent;
	return ((*tab[format])(ap));
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	if (!str)
		return (-1);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += printf_format(str, ap);
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (count);
}
