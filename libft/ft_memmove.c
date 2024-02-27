/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:47:20 by mlaporte          #+#    #+#             */
/*   Updated: 2023/05/23 10:40:32 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destin;
	const char	*source;

	destin = dest;
	source = src;
	if (!dest && !src)
		return (0);
	else if (destin < source)
		ft_memcpy(destin, source, n);
	else
	{
		while (n-- > 0)
			destin[n] = source[n];
	}
	return (destin);
}
