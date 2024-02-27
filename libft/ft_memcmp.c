/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:24:22 by mlaporte          #+#    #+#             */
/*   Updated: 2023/05/17 17:03:47 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*mem1;
	const char	*mem2;
	size_t		i;

	mem1 = (const char *)s1;
	mem2 = (const char *)s2;
	i = 0;
	while (i < n && mem1[i] == mem2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)mem1[i] - (unsigned char)mem2[i]);
}
