/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:01:19 by mlaporte          #+#    #+#             */
/*   Updated: 2023/05/22 09:46:41 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*s1;
	size_t					i;
	unsigned char			chr;

	i = 0;
	s1 = s;
	chr = c;
	while (i < n)
	{
		if (s1[i] == chr)
			return ((void *)(s1 + i));
		i++;
	}
	return (0);
}
